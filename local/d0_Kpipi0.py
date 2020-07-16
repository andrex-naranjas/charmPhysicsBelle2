#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#This is the first attempt to select D0 charm
import os
import sys
import glob
import basf2 as b2
import modularAnalysis as ma


if len(sys.argv) != 2:
    sys.exit('Provide channel. Try again!')

sample = sys.argv[1]

#input directory 
dir = '/u/user/andres/data/belle/charm/mc13b_proc11'


if sample == 'ccbar':
    input = dir+'/ccbar/mdst/*.root'#ccbar_0010_r05248_1_mdst.root'
elif sample == 'mixed':
    input = dir+'/mixed/mdst/*.root'
elif sample == 'charged':
    input = dir+'/charged/mdst/*.root'
elif sample == 'ssbar':
    input = dir+'/ssbar/mdst/*.root'
elif sample == 'uubar':
    input = dir+'/uubar/mdst/*.root'
elif sample == 'ddbar':
    input = dir+'/ddbar/mdst/*.root'
elif sample == 'taupair':
    input = dir+'/taupair/mdst/*.root'
elif sample == 'signal':
    input = dir+'/signal_three/mdst/*.root'
elif sample == 'data':
    input = dir+'/data/*.root'


#Define the main path
mypath = b2.Path()

#If we are using data, we need to specify the global tag
b2.reset_database()
b2.use_central_database("mc_production_MC13b_proc11")

ma.inputMdst('default', input, path=mypath)

#define quality cuts for tracks
track_cuts      = 'abs(dr) <= 0.5 and abs(dz) < 2.0 and nCDCHits > 30 and nSVDHits > 0 and -0.8660 < cosTheta < 0.9563'
track_cuts_slow = 'abs(dr) <= 0.5 and abs(dz) < 2.0 and nCDCHits > 0 and nSVDHits > 0 and -0.8660 < cosTheta < 0.9563'

#fill the particle lis of pions
ma.fillParticleList('pi+:goodTrack', track_cuts, path=mypath)
ma.fillParticleList('pi+:goodTrack_slow', track_cuts_slow, path=mypath)
ma.fillParticleList('K+:goodTrack', track_cuts, path=mypath)

#apply pi identification cuts (pion pdg 211)
ma.cutAndCopyList('pi+:goodTrackID','pi+:goodTrack', 'pidPairProbabilityExpert(211, 321, ALL) > 0.3', path=mypath)

#apply kaon identification cuts (kaon pdg 321)
ma.cutAndCopyList('K+:goodTrackID', 'K+:goodTrack', 'pidPairProbabilityExpert(321, 211, ALL) > 0.3', path=mypath)

# reconstruct pi0 (performance group recommendations, eff30)
# https://confluence.desy.de/display/BI/Jan2020+pi0+Recommendations
#gamma_cuts = '[[clusterNHits>1.5] and [0.2967< clusterTheta<2.6180]] and [[clusterReg==1 and E>0.080] or [clusterReg==2 and E>0.030] or [clusterReg==3 and E>0.060 ]]'#May2020
gamma_cuts = '[[clusterReg==1 and E>0.080] or [clusterReg==2 and E>0.030] or [clusterReg==3 and E>0.060 ]]'
from stdPhotons import stdPhotons
stdPhotons(listtype='all',path=mypath)
#ma.fillParticleList('gamma:eff30_Jan2020', gamma_cuts, path=mypath)
ma.cutAndCopyList('gamma:eff30_Jan2020', 'gamma:all', gamma_cuts, path=mypath)
pi0_cuts = '0.120<InvM<0.15 and -1.5<daughterDiffOfPhi(0,1)<1.5 and daughterAngleInBetween(0,1)<1.4'
ma.reconstructDecay('pi0:eff30_Jan2020 -> gamma:eff30_Jan2020 gamma:eff30_Jan2020', pi0_cuts, path=mypath)


#reconstruct D0 candidates
d0cuts = '1.7 < M < 2.05'
# D0->kpipi0
ma.reconstructDecay('D0:Kpipi0_rs -> K-:goodTrackID pi+:goodTrackID pi0:eff30_Jan2020', d0cuts, dmID=0, path=mypath)
ma.reconstructDecay('D0:Kpipi0_ws -> K+:goodTrackID pi-:goodTrackID pi0:eff30_Jan2020', d0cuts, dmID=1, path=mypath)
ma.copyLists('D0:merged',['D0:Kpipi0_rs','D0:Kpipi0_ws'], True, path=mypath)


#reconstruct the tag
ma.reconstructDecay('pi+:piTag -> pi+:goodTrack_slow', '', path=mypath)

#reconstruct D*+
dstcuts = 'useCMSFrame(p) > 2.0 and massDifference(0) < 0.16'
ma.reconstructDecay('D*+:good -> D0:merged pi+:piTag', dstcuts, path=mypath)

#Fit the vertex
import vertex as vx
ma.vertexTree('D*+:good', conf_level=0.01, massConstraint=['pi0'], updateAllDaughters=True, ipConstraint=True, path=mypath)


# Create one ntuple per channel in the same output file
ma.cutAndCopyList('D*+:Kpipi0RS'   ,'D*+:good','daughter(0,extraInfo(decayModeID))==0',path=mypath)
ma.cutAndCopyList('D*+:Kpipi0WS'   ,'D*+:good','daughter(0,extraInfo(decayModeID))==1',path=mypath)


# call the buildEventKinematics from modular analysis
# Pass the particle lists to the function
ma.buildEventKinematics(['K+:goodTrackID', 'pi+:goodTrackID', 'gamma:eff30_Jan2020'], '', path=mypath)

#mc match
ma.matchMCTruth('D*+:Kpipi0RS', path=mypath)
ma.matchMCTruth('D*+:Kpipi0WS', path=mypath)

# ma.matchMCTruth('D*+:piD0RS', path=mypath)
# ma.matchMCTruth('D*+:piD0WS', path=mypath)


#Store variables
#Define aliases for the vertex results
from variables import variables as va
va.addAlias('vtxChi2', 'extraInfo(chiSquared)')
va.addAlias('vtxNDF', 'extraInfo(ndf)')

va.addAlias('vtxChi2', 'extraInfo(chiSquared)')
va.addAlias('Q_masses','formula(M - daughter(0,M)-daughter(1,M))')


# We will also store some useful MC match information.
mcVariables = ['mcErrors', 
               'genMotherPDG', 
               'mcPDG']

import variables.collections as vc
import variables.utils as vu


# You can use collections of variables, as vc.kinematics or vc.inv_mass.
kVariables = vc.inv_mass + vc.kinematics + vc.pid + vc.mc_truth + ['pidPairProbabilityExpert(211, 321, ALL)'] + ['pidPairProbabilityExpert(321, 211, ALL)'] + ['useCMSFrame(p)'] + ['isSignal']
#+ ['kaonID_rank']


varsKpipi0RS = vu.create_aliases_for_selected(list_of_variables = kVariables,
                                              decay_string = 'D*+ -> [D0 -> K- pi+ [pi0 -> ^gamma ^gamma] ] pi+') + \
               vu.create_aliases_for_selected(list_of_variables = kVariables + ['Q_masses', 'charge'], 
                                              decay_string = 'D*+ -> [D0 -> ^K- ^pi+ ^pi0] ^pi+') + \
               vu.create_aliases_for_selected(list_of_variables = kVariables + ['dM', 'vtxChi2', 'vtxNDF', 'dQ', 'Q','charge'],
                                              decay_string = 'D*+ -> ^D0 ^pi+',
                                              prefix = ['dst0','dst1']) + \
               vu.create_aliases_for_selected(list_of_variables = kVariables + ['dM', 'dQ', 'Q','charge'],
                                              decay_string = '^D*+',
                                              prefix='Dst')


varsKpipi0WS = vu.create_aliases_for_selected(list_of_variables = kVariables,
                                              decay_string = 'D*+ -> [D0 -> K+ pi- [pi0 -> ^gamma ^gamma] ] pi+') + \
               vu.create_aliases_for_selected(list_of_variables = kVariables + ['Q_masses', 'charge'], 
                                              decay_string = 'D*+ -> [D0 -> ^K+ ^pi- ^pi0] ^pi+') + \
               vu.create_aliases_for_selected(list_of_variables = kVariables + ['dM', 'vtxChi2', 'vtxNDF', 'dQ', 'Q','charge'],
                                              #decay_string = 'D*+ -> [^D0 -> ^K+ ^pi- ^pi0] ^pi+',
                                              decay_string = 'D*+ -> ^D0 ^pi+',
                                              prefix = ['dst0','dst1']) + \
               vu.create_aliases_for_selected(list_of_variables = kVariables + ['dM', 'dQ', 'Q','charge'],
                                              #decay_string = '^D*+ -> [^D0 -> ^K+ ^pi- ^pi0] ^pi+',
                                              decay_string = '^D*+',
                                              prefix='Dst')


# # Create one ntuple per channel in the same output file
# ma.cutAndCopyList('D*+:Kpipi0RS'   ,'D*+:good','daughter(0,extraInfo(decayModeID))==0',path=mypath)
# ma.cutAndCopyList('D*+:Kpipi0WS'   ,'D*+:good','daughter(0,extraInfo(decayModeID))==1',path=mypath)

va.printAliases()
rootFileName = './Files/'+ sample + '/ouput_charm_dst.root'


ma.variablesToNtuple(decayString='D*+:Kpipi0RS'   ,variables=varsKpipi0RS   ,filename=rootFileName,treename='DstD0PiKPipi0RS'   ,path=mypath)
ma.variablesToNtuple(decayString='D*+:Kpipi0WS'   ,variables=varsKpipi0WS   ,filename=rootFileName,treename='DstD0PiKPipi0WS'   ,path=mypath)

#Process path, do the actual work
b2.process(mypath)
#printout summary
print(b2.statistics)


# # gamma variables
# fs_gammas = vu.create_aliases_for_selected(
#     list_of_variables = kVariables,
#     decay_string = 'D*+ -> [D0 -> K- pi+ [pi0 -> ^gamma ^gamma] ] pi+')

# # hadron variables
# fs_hadrons = vu.create_aliases_for_selected(
#     list_of_variables = kVariables + ['Q_masses'], 
#     decay_string = 'D*+ -> [D0 -> ^K- ^pi+ ^pi0] ^pi+')

# # D0 variables
# fs_d0 = vu.create_aliases_for_selected(
#     list_of_variables = kVariables + ['dM', 'vtxChi2', 'vtxNDF', 'dQ', 'Q'],
#     decay_string = 'D*+ -> ^D0 ^pi+',
#     prefix = ['dst0','dst1'])

# # Dstar variables
# fs_dst = vu.create_aliases_for_selected(
#     list_of_variables = kVariables + ['dM', 'dQ', 'Q'],
#     decay_string = '^D*+',
#     prefix='Dst')

# variableList = fs_gammas + fs_hadrons + fs_d0 + fs_dst


# ma.variablesToNtuple(decayString='D*+:piD0',
#                      variables = variableList, 
#                      filename = rootFileName,
#                      treename='charm',
#                      path=mypath)
