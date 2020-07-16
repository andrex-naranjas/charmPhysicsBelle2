#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#This is the first attempt to select D0 charm
import os
import sys
import glob
import basf2 as b2
import modularAnalysis as ma


# if len(sys.argv) != 2:
#     sys.exit('Provide channel. Try again!')

# sample = sys.argv[1]

# #input directory
# if sample == 'signal':
#     input = '/u/user/andres/data/belle/charm/signal/sub00/mdst_000001_prod00007456_task10020000001.root'
# elif sample == 'charged':
#     input = '/u/user/andres/data/belle/charm/charged/sub00/mdst_000252_prod00009551_task10020000252.root'
# elif sample == 'mixed':
#     input = '/u/user/andres/data/belle/charm/mixed/sub00/mdst_000088_prod00009434_task10020000088.root'
# elif sample == 'ccbar':
#     input = '/u/user/andres/data/belle/charm/ccbar/sub00/mdst_000652_prod00009493_task10020000653.root'
# elif sample == 'ddbar':
#     input = '/u/user/andres/data/belle/charm/ddbar/sub00/mdst_000174_prod00009489_task10020000173.root'
# elif sample == 'ssbar':
#     input = '/u/user/andres/data/belle/charm/ssbar/sub00/mdst_000158_prod00009529_task10020000158.root'
# elif sample == 'uubar':
#     input = '/u/user/andres/data/belle/charm/uubar/sub00/mdst_000786_prod00009553_task10020000786.root'
# elif sample == 'taupair':
#     input = '/u/user/andres/data/belle/charm/taupair/sub00/mdst_000440_prod00009538_task10020000440.root'
# elif sample == 'data':
#     input = '/u/user/andres/data/belle/charm/data/sub00/*.root'

input = '/u/user/andres/data/belle/charm/data/sub00/*.root'

#Define the main path
mypath = b2.Path()

ma.inputMdst('default', input, path=mypath)

#define quality cuts for tracks
track_cuts = 'abs(dr) <= 1.0 and abs(dz) < 3.0 and nCDCHits > 20 and abs(d0)<0.5'

#fill the particle lis of pions
ma.fillParticleList('pi+:goodTrack', track_cuts, path=mypath)
ma.fillParticleList('K+:goodTrack', track_cuts, path=mypath)

#apply event cuts
ma.applyEventCuts('countInList(pi+:goodTrack) >= 1', path=mypath)
ma.applyEventCuts('countInList(K+:goodTrack) >= 1', path=mypath)

from variables import variables as va

#apply pi identification cuts
va.addAlias('EoverP', 'formula( ifNANgiveX( clusterE, -1)/p )')
ma.cutAndCopyList('pi+:goodTrackID','pi+:goodTrack', 'EoverP < 0.8', path=mypath)

#apply kaon identification cuts (kaon pdg 321) abs(mcPDG) == 321
ma.cutAndCopyList('K+:goodTrackID', 'K+:goodTrack', '', path=mypath)

#reconstruct D0 candidates
ma.reconstructDecay('D0:Kp -> K-:goodTrackID pi+:goodTrackID', '1.845 < M < 1.9' ,path=mypath)

#reconstruct the tag
ma.reconstructDecay('pi+:piTag -> pi+:goodTrack', '', path=mypath)

#reconstruct D*+ 
ma.reconstructDecay('D*+:piD0 -> D0:Kp pi+:piTag', 'useCMSFrame(p) > 2.5 and 0.14 < massDifference(0) < 0.16', path=mypath)

#Fit the vertex
import vertex as vx
#ma.vertexTree('D*+:piD0', conf_level=0.0, massConstraint=['D0'], ipConstraint=True, updateAllDaughters=True, path=mypath)
ma.vertexTree('D*+:piD0', conf_level=0.0, updateAllDaughters=True, ipConstraint=True, path=mypath)

#Define aliases for the vertex results
va.addAlias('vtxChi2', 'extraInfo(chiSquared)')
va.addAlias('vtxNDF', 'extraInfo(ndf)')


#call the buildEventShape from modular analysis
#Pass the particle lists to the function
ma.buildEventShape(['K+:goodTrackID', 'pi+:goodTrackID'],
                   thrust=True,
                   foxWolfram=False,
                   cleoCones=False,
                   jets=False,
                   harmonicMoments=False,
                   allMoments=False,
                   collisionAxis=False,
                   sphericity=False,
                   path=mypath)

#In the same way, call the buildEventKinematics too
ma.buildEventKinematics(['K+:goodTrackID', 'pi+:goodTrackID'], '', path=mypath)

#mc match
ma.matchMCTruth('D*+:piD0', path=mypath)
#ma.matchMCTruth(list_name='K+:goodTrackID', path=mypath)
#ma.matchMCTruth(list_name='pi+:goodTrackID', path=mypath)

#Label something... check

#Store variables
# We will store some useful event variables, as the thrust, the event kinematics variables. 
eventVariables = ['thrust',
                  'visibleEnergyOfEventCMS',
                  'missingMomentumOfEvent',
                  'missingMomentumOfEvent_theta',
                  'missingMomentumOfEventCMS',
                  'missingMomentumOfEventCMS_theta',
                  'totalPhotonsEnergyOfEvent',
                  'missingMass2OfEvent']

# We will also store some useful MC match information.
mcVariables = ['mcErrors', 
               'genMotherPDG', 
               'mcPDG']

import variables.collections as vc
import variables.utils as vu

# You can use collections of variables, as vc.kinematics or vc.inv_mass.
kVariables = vc.inv_mass + vc.kinematics

#Here we will create the variable list 
variableList = vu.create_aliases_for_selected(list_of_variables=eventVariables,
                                              decay_string='^D0') + \
    vu.create_aliases_for_selected(list_of_variables=mcVariables + ['charge'],
                                   decay_string='D*+ -> ^D0 ^pi+') + \
    vu.create_aliases_for_selected(list_of_variables=kVariables + ['isSignalAcceptMissingNeutrino'],
                                   decay_string='D*+ -> [^D0 -> ^K- ^pi+ ] ^pi+')



va.printAliases()
rootFileName = sys.argv[1]+'.root'

ma.variablesToNtuple(decayString='D*+:piD0',
                     variables = variableList, 
                     filename = rootFileName,
                     treename='charm',
                     path=mypath)

#Process path, do the actual work
b2.process(mypath)
#printout summary
print(b2.statistics)
