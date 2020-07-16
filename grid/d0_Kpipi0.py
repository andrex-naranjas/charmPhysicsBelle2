#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#This is the first attempt to select D0 charm
import os
import sys
import glob
import basf2 as b2
import modularAnalysis as ma


input = '/u/user/andres/data/belle/charm/data/sub00/*.root'

#Define the main path
mypath = b2.Path()

#If we are using data, we need to specify the global tag
b2.reset_database()
b2.use_central_database("data_reprocessing_proc11")

ma.inputMdst('default', input, path=mypath)

#define quality cuts for tracks
track_cuts      = 'abs(dr) <= 0.5 and abs(dz) < 2.0 and nCDCHits > 30 and nSVDHits > 0 and -0.8660 < cosTheta < 0.9563'
track_cuts_slow = 'abs(dr) <= 0.5 and abs(dz) < 2.0 and nCDCHits > 0 and nSVDHits > 0 and -0.8660 < cosTheta < 0.9563'

# charged particles
ma.fillParticleList('pi+:goodTrack',      track_cuts, path=mypath)
ma.fillParticleList('pi+:goodTrack_slow', track_cuts_slow, path=mypath)
ma.fillParticleList('K+:goodTrack',       track_cuts, path=mypath)

#apply pi identification cuts (pion pdg 211)
ma.cutAndCopyList('pi+:goodTrackID','pi+:goodTrack', 'pidPairProbabilityExpert(211, 321, ALL) > 0.3', path=mypath)

#apply kaon identification cuts (kaon pdg 321)
ma.cutAndCopyList('K+:goodTrackID', 'K+:goodTrack', 'pidPairProbabilityExpert(321, 211, ALL) > 0.3', path=mypath)

# reconstruct pi0 (performance group recommendations, eff30)
# https://confluence.desy.de/display/BI/Jan2020+pi0+Recommendations
#gamma_cuts = '[[clusterNHits>1.5] and [0.2967< clusterTheta<2.6180]] and [[clusterReg==1 and E>0.080] or [clusterReg==2 and E>0.030] or [clusterReg==3 and E>0.060 ]]'#May2020
gamma_cuts = '[[clusterReg==1 and E>0.080] or [clusterReg==2 and E>0.030] or [clusterReg==3 and E>0.060 ]]'
ma.fillParticleList('gamma:eff30_Jan2020', gamma_cuts, path=mypath)
pi0_cuts = '0.120<InvM<0.15 and -1.5<daughterDiffOfPhi(0,1)<1.5 and daughterAngleInBetween(0,1)<1.4'
ma.reconstructDecay('pi0:eff30_Jan2020 -> gamma:eff30_Jan2020 gamma:eff30_Jan2020', pi0_cuts, path=mypath)

#reconstruct D0 candidates
d0cuts = '1.7 < M < 2.05'
# D0->kpipi0
ma.reconstructDecay('D0:Kpipi0_rs -> K-:goodTrackID pi+:goodTrackID pi0:eff30_Jan2020', d0cuts,path=mypath)
ma.reconstructDecay('D0:Kpipi0_ws -> K+:goodTrackID pi-:goodTrackID pi0:eff30_Jan2020', d0cuts,path=mypath)
ma.copyLists('D0:comb',['D0:Kpipi0_rs','D0:Kpipi0_ws'],path=mypath)

# D0->kpi
ma.reconstructDecay('D0:Kpi_rs -> K-:goodTrackID pi+:goodTrackID', d0cuts,path=mypath)
ma.reconstructDecay('D0:Kpi_ws -> K+:goodTrackID pi-:goodTrackID', d0cuts,path=mypath)
ma.copyLists('D0:comb_ch',['D0:Kpi_rs','D0:Kpi_ws'],path=mypath)


#reconstruct the tag
ma.reconstructDecay('pi+:piTag -> pi+:goodTrack_slow', '', path=mypath)

#reconstruct D*+
dstcuts = 'useCMSFrame(p) > 2.0 and massDifference(0) < 0.16'
# D0->kpipi0
ma.reconstructDecay('D*+:piD0_rs_3b -> D0:Kpipi0_rs pi+:piTag', dstcuts, path=mypath)
ma.reconstructDecay('D*+:piD0_ws_3b -> D0:Kpipi0_ws pi+:piTag', dstcuts, path=mypath)
ma.reconstructDecay('D*+:piD0_cb_3b -> D0:comb pi+:piTag', dstcuts, path=mypath)

# D0->kpi
ma.reconstructDecay('D*+:piD0_rs_2b -> D0:Kpi_rs  pi+:piTag', dstcuts, path=mypath)
ma.reconstructDecay('D*+:piD0_ws_2b -> D0:Kpi_ws  pi+:piTag', dstcuts, path=mypath)
ma.reconstructDecay('D*+:piD0_cb_2b -> D0:comb_ch pi+:piTag', dstcuts, path=mypath)


# rank
# from variables import variables as va
# ma.rankByHighest(particleList='K+:goodTrackID', variable='kaonID', outputVariable='kID_rank', path=mypath)
# va.addAlias('kaonID_rank', 'extraInfo(kID_rank)')

# Fit the vertex
import vertex as vx
# D0->kpipi0
ma.vertexTree('D*+:piD0_rs_3b', conf_level=0.001, massConstraint=['pi0'], updateAllDaughters=True, ipConstraint=True, path=mypath)
ma.vertexTree('D*+:piD0_ws_3b', conf_level=0.001, massConstraint=['pi0'], updateAllDaughters=True, ipConstraint=True, path=mypath)
ma.vertexTree('D*+:piD0_cb_3b', conf_level=0.001, massConstraint=['pi0'], updateAllDaughters=True, ipConstraint=True, path=mypath)


# D0->kpi
ma.vertexTree('D*+:piD0_rs_2b', conf_level=0.01, updateAllDaughters=True, ipConstraint=True, path=mypath)
ma.vertexTree('D*+:piD0_ws_2b', conf_level=0.01, updateAllDaughters=True, ipConstraint=True, path=mypath)
ma.vertexTree('D*+:piD0_cb_2b', conf_level=0.01, updateAllDaughters=True, ipConstraint=True, path=mypath)


#Define aliases for the vertex results
from variables import variables as va
va.addAlias('vtxChi2', 'extraInfo(chiSquared)')
va.addAlias('vtxNDF', 'extraInfo(ndf)')
va.addAlias('vtxChi2', 'extraInfo(chiSquared)')
va.addAlias('Q_masses','formula(M - daughter(0,M)-daughter(1,M))')


# call the buildEventKinematics from modular analysis
# Pass the particle lists to the function
ma.buildEventKinematics(['K+:goodTrackID', 'pi+:goodTrackID', 'gamma:eff30_Jan2020'], '', path=mypath)

# mc match
# D0->kpipi0
ma.matchMCTruth('D*+:piD0_rs_3b', path=mypath)
ma.matchMCTruth('D*+:piD0_ws_3b', path=mypath)
ma.matchMCTruth('D*+:piD0_cb_3b', path=mypath)

# D0->kpi
ma.matchMCTruth('D*+:piD0_rs_2b', path=mypath)
ma.matchMCTruth('D*+:piD0_ws_2b', path=mypath)
ma.matchMCTruth('D*+:piD0_cb_2b', path=mypath)


# Store variables
# We will also store some useful MC match information.
mcVariables = ['mcErrors', 
               'genMotherPDG',
               'mcPDG']

import variables.collections as vc
import variables.utils as vu

# You can use collections of variables, as vc.kinematics or vc.inv_mass.
kVariables = vc.inv_mass + vc.kinematics + vc.pid + vc.mc_truth + ['pidPairProbabilityExpert(211, 321, ALL)'] + ['pidPairProbabilityExpert(321, 211, ALL)'] + ['useCMSFrame(p)'] + ['isWrongCharge']
#+ ['kaonID_rank']

# right sign
# gamma variables
fs_gammas_rs = vu.create_aliases_for_selected(
    list_of_variables = kVariables,
    decay_string = 'D*+ -> [D0 -> K- pi+ [pi0 -> ^gamma ^gamma] ] pi+')

# hadron variables
fs_hadrons_3b_rs = vu.create_aliases_for_selected(
    list_of_variables = kVariables + ['Q_masses', 'charge'], 
    decay_string = 'D*+ -> [D0 -> ^K- ^pi+ ^pi0] ^pi+')

fs_hadrons_2b_rs = vu.create_aliases_for_selected(
    list_of_variables = kVariables + ['Q_masses', 'charge'], 
    decay_string = 'D*+ -> [D0 -> ^K- ^pi+] ^pi+')

# D0 variables (the same for right and wrong sign)
fs_d0 = vu.create_aliases_for_selected(
    list_of_variables = kVariables + ['dM', 'vtxChi2', 'vtxNDF', 'dQ', 'Q','charge'],
    decay_string = 'D*+ -> ^D0 ^pi+',
    prefix = ['dst0','dst1'])

# Dstar variables (the same for right and wrong sign)
fs_dst = vu.create_aliases_for_selected(
    list_of_variables = kVariables + ['dM', 'dQ', 'Q','charge'],
    decay_string = '^D*+',
    prefix='Dst')

variableList_3b_rs = fs_gammas_rs + fs_hadrons_3b_rs + fs_d0 + fs_dst
variableList_2b_rs = fs_hadrons_2b_rs + fs_d0 + fs_dst


# wrong sign
# gamma variables
fs_gammas_ws = vu.create_aliases_for_selected(
    list_of_variables = kVariables,
    decay_string = 'D*+ -> [D0 -> K+ pi- [pi0 -> ^gamma ^gamma] ] pi+')

# hadron variables
fs_hadrons_3b_ws = vu.create_aliases_for_selected(
    list_of_variables = kVariables + ['Q_masses', 'charge'], 
    decay_string = 'D*+ -> [D0 -> ^K+ ^pi- ^pi0] ^pi+')

fs_hadrons_2b_ws = vu.create_aliases_for_selected(
    list_of_variables = kVariables + ['Q_masses', 'charge'], 
    decay_string = 'D*+ -> [D0 -> ^K+ ^pi-] ^pi+')

variableList_3b_ws = fs_gammas_ws + fs_hadrons_3b_ws + fs_d0 + fs_dst
variableList_2b_ws = fs_hadrons_2b_ws + fs_d0 + fs_dst

# combined
variableList_3b_cb = variableList_3b_ws + variableList_3b_rs
variableList_2b_cb = variableList_2b_ws + variableList_2b_rs


va.printAliases()
rootFileName = 'output_charm_data.root'

# kpipi0
ma.variablesToNtuple(decayString='D*+:piD0_rs_3b',
                     variables = variableList_3b_rs, 
                     filename = rootFileName,
                     treename='charm_rs_3b',
                     path=mypath)

ma.variablesToNtuple(decayString='D*+:piD0_ws_3b',
                     variables = variableList_3b_ws, 
                     filename = rootFileName,
                     treename='charm_ws_3b',
                     path=mypath)

ma.variablesToNtuple(decayString='D*+:piD0_cb_3b',
                     variables = variableList_3b_cb, 
                     filename = rootFileName,
                     treename='charm_cb_3b',
                     path=mypath)

# kpi
ma.variablesToNtuple(decayString='D*+:piD0_rs_2b',
                     variables = variableList_2b_rs, 
                     filename = rootFileName,
                     treename='charm_rs_2b',
                     path=mypath)

ma.variablesToNtuple(decayString='D*+:piD0_ws_2b',
                     variables = variableList_2b_ws, 
                     filename = rootFileName,
                     treename='charm_ws_2b',
                     path=mypath)

ma.variablesToNtuple(decayString='D*+:piD0_cb_2b',
                     variables = variableList_2b_cb, 
                     filename = rootFileName,
                     treename='charm_cb_2b',
                     path=mypath)

#Process path, do the actual work
b2.process(mypath)
#printout summary
print(b2.statistics)


# # We will store some useful event variables, as the thrust, the event kinematics variables. 
# eventVariables = ['thrust',
#                   'visibleEnergyOfEventCMS',
#                   'missingMomentumOfEvent',
#                   'missingMomentumOfEvent_theta',
#                   'missingMomentumOfEventCMS',
#                   'missingMomentumOfEventCMS_theta',
#                   'totalPhotonsEnergyOfEvent',
#                   'missingMass2OfEvent']

# #Here we will create the variable list 
# variableList = vu.create_aliases_for_selected(list_of_variables=eventVariables,
#                                               decay_string='^D0') + \
#     vu.create_aliases_for_selected(list_of_variables=mcVariables + kVariables + ['charge'],
#                                    decay_string='D*+ -> ^D0 ^pi+') + \
#     vu.create_aliases_for_selected(list_of_variables=kVariables + ['isSignalAcceptMissingNeutrino'],
#                                    decay_string='D*+ -> [^D0 -> ^K- ^pi+ ^pi0] ^pi+') + \
#     vu.create_aliases_for_selected(list_of_variables=kVariables + ['isSignalAcceptMissingNeutrino'],
#                                    decay_string='D*+ -> [^D0 -> ^K- ^pi+ [pi0 -> ^gamma ^gamma] ] ^pi+')

#call the buildEventShape from modular analysis
#Pass the particle lists to the function
# ma.buildEventShape(['K+:goodTrackID', 'pi+:goodTrackID', 'gamma:eff30_Jan2020'],
#                    thrust=True,
#                    foxWolfram=False,
#                    cleoCones=False,
#                    jets=False,
#                    harmonicMoments=False,
#                    allMoments=False,
#                    collisionAxis=False,
#                    sphericity=False,
#                    path=mypath)


# ma.cutAndCopyList('pi+:goodTrackIDmiss','pi+:goodTrack', 'pidPairProbabilityExpert(211, 321, ALL) <= 0.3', path=mypath)
# ma.cutAndCopyList('K+:goodTrackIDmiss', 'K+:goodTrack', 'pidPairProbabilityExpert(321, 211, ALL) <= 0.3', path=mypath)
# d0cuts_miss = 'M < 1.85 or M > 1.88'
# ma.reconstructDecay('D0:Kpipi0miss -> K-:goodTrackIDmiss pi+:goodTrackIDmiss pi0:eff30_Jan2020', d0cuts_miss,path=mypath)
# ma.applyEventCuts()
