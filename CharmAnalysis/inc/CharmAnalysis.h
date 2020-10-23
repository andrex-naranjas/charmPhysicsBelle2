#ifndef CharmAnalysis_h
#define CharmAnalysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "ConfigSettings.h"

// Header file for the classes stored in the TTree if any.

class CharmAnalysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMax__experiment_ = 1;
   static constexpr Int_t kMax__run_ = 1;
   static constexpr Int_t kMax__event_ = 1;
   static constexpr Int_t kMax__candidate_ = 1;
   static constexpr Int_t kMax__ncandidates_ = 1;
   static constexpr Int_t kMax__weight_ = 1;

   //framework variables
   std::string nameOfSample;
   std::string nameOfSystematic;
   Config config;


   // Declaration of leaf types
   Int_t           __experiment__;
   Int_t           __run__;
   Int_t           __event__;
   Int_t           __candidate__;
   Int_t           __ncandidates__;
   Double_t        __weight__;
   Double_t        D0_pi0_gamma_0_M;
   Double_t        D0_pi0_gamma_0_ErrM;
   Double_t        D0_pi0_gamma_0_SigM;
   Double_t        D0_pi0_gamma_0_InvM;
   Double_t        D0_pi0_gamma_0_px;
   Double_t        D0_pi0_gamma_0_py;
   Double_t        D0_pi0_gamma_0_pz;
   Double_t        D0_pi0_gamma_0_pt;
   Double_t        D0_pi0_gamma_0_p;
   Double_t        D0_pi0_gamma_0_E;
   Double_t        D0_pi0_gamma_0_kaonID;
   Double_t        D0_pi0_gamma_0_pionID;
   Double_t        D0_pi0_gamma_0_protonID;
   Double_t        D0_pi0_gamma_0_muonID;
   Double_t        D0_pi0_gamma_0_electronID;
   Double_t        D0_pi0_gamma_0_deuteronID;
   //Double_t        D0_pi0_gamma_0_isSignal; fishy
   Double_t        D0_pi0_gamma_0_mcErrors;
   Double_t        D0_pi0_gamma_0_mcPDG;
   Double_t        D0_pi0_gamma_0_useCMSFrame_p;
   Double_t        D0_pi0_gamma_0_isSignal;
   Double_t        D0_pi0_gamma_0_isWrongCharge;
   Double_t        D0_pi0_gamma_0_isSignalAcceptMissingGamma;
   Double_t        D0_pi0_gamma_0_nCDCHits;
   Double_t        D0_pi0_gamma_0_nSVDHits;
   Double_t        D0_pi0_gamma_0_nVXDHits;
   Double_t        D0_pi0_gamma_0_clusterNHits;
   Double_t        D0_pi0_gamma_0_cosTheta;
   Double_t        D0_pi0_gamma_0_theta;
   Double_t        D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_ALL;
   Double_t        D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_ALL;
   Double_t        D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC;
   Double_t        D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC;
   Double_t        D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_SVD;
   Double_t        D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_SVD;
   Double_t        D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC_SVD;
   Double_t        D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC_SVD;
   Double_t        D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;
   Double_t        D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;
   Double_t        D0_pi0_gamma_1_M;
   Double_t        D0_pi0_gamma_1_ErrM;
   Double_t        D0_pi0_gamma_1_SigM;
   Double_t        D0_pi0_gamma_1_InvM;
   Double_t        D0_pi0_gamma_1_px;
   Double_t        D0_pi0_gamma_1_py;
   Double_t        D0_pi0_gamma_1_pz;
   Double_t        D0_pi0_gamma_1_pt;
   Double_t        D0_pi0_gamma_1_p;
   Double_t        D0_pi0_gamma_1_E;
   Double_t        D0_pi0_gamma_1_kaonID;
   Double_t        D0_pi0_gamma_1_pionID;
   Double_t        D0_pi0_gamma_1_protonID;
   Double_t        D0_pi0_gamma_1_muonID;
   Double_t        D0_pi0_gamma_1_electronID;
   Double_t        D0_pi0_gamma_1_deuteronID;
   //Double_t        D0_pi0_gamma_1_isSignal; fishy
   Double_t        D0_pi0_gamma_1_mcErrors;
   Double_t        D0_pi0_gamma_1_mcPDG;
   Double_t        D0_pi0_gamma_1_useCMSFrame_p;
   Double_t        D0_pi0_gamma_1_isSignal;
   Double_t        D0_pi0_gamma_1_isWrongCharge;
   Double_t        D0_pi0_gamma_1_isSignalAcceptMissingGamma;
   Double_t        D0_pi0_gamma_1_nCDCHits;
   Double_t        D0_pi0_gamma_1_nSVDHits;
   Double_t        D0_pi0_gamma_1_nVXDHits;
   Double_t        D0_pi0_gamma_1_clusterNHits;
   Double_t        D0_pi0_gamma_1_cosTheta;
   Double_t        D0_pi0_gamma_1_theta;
   Double_t        D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_ALL;
   Double_t        D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_ALL;
   Double_t        D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC;
   Double_t        D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC;
   Double_t        D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_SVD;
   Double_t        D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_SVD;
   Double_t        D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC_SVD;
   Double_t        D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC_SVD;
   Double_t        D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;
   Double_t        D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;
   Double_t        D0_K_M;
   Double_t        D0_K_ErrM;
   Double_t        D0_K_SigM;
   Double_t        D0_K_InvM;
   Double_t        D0_K_px;
   Double_t        D0_K_py;
   Double_t        D0_K_pz;
   Double_t        D0_K_pt;
   Double_t        D0_K_p;
   Double_t        D0_K_E;
   Double_t        D0_K_kaonID;
   Double_t        D0_K_pionID;
   Double_t        D0_K_protonID;
   Double_t        D0_K_muonID;
   Double_t        D0_K_electronID;
   Double_t        D0_K_deuteronID;
   //Double_t        D0_K_isSignal;
   Double_t        D0_K_mcErrors;
   Double_t        D0_K_mcPDG;
   Double_t        D0_K_useCMSFrame_p;
   Double_t        D0_K_isSignal;
   Double_t        D0_K_isWrongCharge;
   Double_t        D0_K_isSignalAcceptMissingGamma;
   Double_t        D0_K_nCDCHits;
   Double_t        D0_K_nSVDHits;
   Double_t        D0_K_nVXDHits;
   Double_t        D0_K_clusterNHits;
   Double_t        D0_K_cosTheta;
   Double_t        D0_K_theta;
   Double_t        D0_K_pidPairProbabilityExpert_211_321_ALL;
   Double_t        D0_K_pidPairProbabilityExpert_321_211_ALL;
   Double_t        D0_K_pidPairProbabilityExpert_321_211_CDC;
   Double_t        D0_K_pidPairProbabilityExpert_211_321_CDC;
   Double_t        D0_K_pidPairProbabilityExpert_321_211_SVD;
   Double_t        D0_K_pidPairProbabilityExpert_211_321_SVD;
   Double_t        D0_K_pidPairProbabilityExpert_321_211_CDC_SVD;
   Double_t        D0_K_pidPairProbabilityExpert_211_321_CDC_SVD;
   Double_t        D0_K_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;
   Double_t        D0_K_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;
   Double_t        D0_K_Q_masses;
   Double_t        D0_K_charge;
   Double_t        D0_pi_M;
   Double_t        D0_pi_ErrM;
   Double_t        D0_pi_SigM;
   Double_t        D0_pi_InvM;
   Double_t        D0_pi_px;
   Double_t        D0_pi_py;
   Double_t        D0_pi_pz;
   Double_t        D0_pi_pt;
   Double_t        D0_pi_p;
   Double_t        D0_pi_E;
   Double_t        D0_pi_kaonID;
   Double_t        D0_pi_pionID;
   Double_t        D0_pi_protonID;
   Double_t        D0_pi_muonID;
   Double_t        D0_pi_electronID;
   Double_t        D0_pi_deuteronID;
   //Double_t        D0_pi_isSignal;
   Double_t        D0_pi_mcErrors;
   Double_t        D0_pi_mcPDG;
   Double_t        D0_pi_useCMSFrame_p;
   Double_t        D0_pi_isSignal;
   Double_t        D0_pi_isWrongCharge;
   Double_t        D0_pi_isSignalAcceptMissingGamma;
   Double_t        D0_pi_nCDCHits;
   Double_t        D0_pi_nSVDHits;
   Double_t        D0_pi_nVXDHits;
   Double_t        D0_pi_clusterNHits;
   Double_t        D0_pi_cosTheta;
   Double_t        D0_pi_theta;
   Double_t        D0_pi_pidPairProbabilityExpert_211_321_ALL;
   Double_t        D0_pi_pidPairProbabilityExpert_321_211_ALL;
   Double_t        D0_pi_pidPairProbabilityExpert_321_211_CDC;
   Double_t        D0_pi_pidPairProbabilityExpert_211_321_CDC;
   Double_t        D0_pi_pidPairProbabilityExpert_321_211_SVD;
   Double_t        D0_pi_pidPairProbabilityExpert_211_321_SVD;
   Double_t        D0_pi_pidPairProbabilityExpert_321_211_CDC_SVD;
   Double_t        D0_pi_pidPairProbabilityExpert_211_321_CDC_SVD;
   Double_t        D0_pi_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;
   Double_t        D0_pi_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;
   Double_t        D0_pi_Q_masses;
   Double_t        D0_pi_charge;
   Double_t        D0_pi0_M;
   Double_t        D0_pi0_ErrM;
   Double_t        D0_pi0_SigM;
   Double_t        D0_pi0_InvM;
   Double_t        D0_pi0_px;
   Double_t        D0_pi0_py;
   Double_t        D0_pi0_pz;
   Double_t        D0_pi0_pt;
   Double_t        D0_pi0_p;
   Double_t        D0_pi0_E;
   Double_t        D0_pi0_kaonID;
   Double_t        D0_pi0_pionID;
   Double_t        D0_pi0_protonID;
   Double_t        D0_pi0_muonID;
   Double_t        D0_pi0_electronID;
   Double_t        D0_pi0_deuteronID;
   //Double_t        D0_pi0_isSignal;
   Double_t        D0_pi0_mcErrors;
   Double_t        D0_pi0_mcPDG;
   Double_t        D0_pi0_useCMSFrame_p;
   Double_t        D0_pi0_isSignal;
   Double_t        D0_pi0_isWrongCharge;
   Double_t        D0_pi0_isSignalAcceptMissingGamma;
   Double_t        D0_pi0_nCDCHits;
   Double_t        D0_pi0_nSVDHits;
   Double_t        D0_pi0_nVXDHits;
   Double_t        D0_pi0_clusterNHits;
   Double_t        D0_pi0_cosTheta;
   Double_t        D0_pi0_theta;
   Double_t        D0_pi0_pidPairProbabilityExpert_211_321_ALL;
   Double_t        D0_pi0_pidPairProbabilityExpert_321_211_ALL;
   Double_t        D0_pi0_pidPairProbabilityExpert_321_211_CDC;
   Double_t        D0_pi0_pidPairProbabilityExpert_211_321_CDC;
   Double_t        D0_pi0_pidPairProbabilityExpert_321_211_SVD;
   Double_t        D0_pi0_pidPairProbabilityExpert_211_321_SVD;
   Double_t        D0_pi0_pidPairProbabilityExpert_321_211_CDC_SVD;
   Double_t        D0_pi0_pidPairProbabilityExpert_211_321_CDC_SVD;
   Double_t        D0_pi0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;
   Double_t        D0_pi0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;
   Double_t        D0_pi0_Q_masses;
   Double_t        D0_pi0_charge;
   Double_t        pi_M;
   Double_t        pi_ErrM;
   Double_t        pi_SigM;
   Double_t        pi_InvM;
   Double_t        pi_px;
   Double_t        pi_py;
   Double_t        pi_pz;
   Double_t        pi_pt;
   Double_t        pi_p;
   Double_t        pi_E;
   Double_t        pi_kaonID;
   Double_t        pi_pionID;
   Double_t        pi_protonID;
   Double_t        pi_muonID;
   Double_t        pi_electronID;
   Double_t        pi_deuteronID;
   //Double_t        pi_isSignal;
   Double_t        pi_mcErrors;
   Double_t        pi_mcPDG;
   Double_t        pi_useCMSFrame_p;
   Double_t        pi_isSignal;
   Double_t        pi_isWrongCharge;
   Double_t        pi_isSignalAcceptMissingGamma;
   Double_t        pi_nCDCHits;
   Double_t        pi_nSVDHits;
   Double_t        pi_nVXDHits;
   Double_t        pi_clusterNHits;
   Double_t        pi_cosTheta;
   Double_t        pi_theta;
   Double_t        pi_pidPairProbabilityExpert_211_321_ALL;
   Double_t        pi_pidPairProbabilityExpert_321_211_ALL;
   Double_t        pi_pidPairProbabilityExpert_321_211_CDC;
   Double_t        pi_pidPairProbabilityExpert_211_321_CDC;
   Double_t        pi_pidPairProbabilityExpert_321_211_SVD;
   Double_t        pi_pidPairProbabilityExpert_211_321_SVD;
   Double_t        pi_pidPairProbabilityExpert_321_211_CDC_SVD;
   Double_t        pi_pidPairProbabilityExpert_211_321_CDC_SVD;
   Double_t        pi_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;
   Double_t        pi_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;
   Double_t        pi_Q_masses;
   Double_t        pi_charge;
   Double_t        D0_M;
   Double_t        D0_ErrM;
   Double_t        D0_SigM;
   Double_t        D0_InvM;
   Double_t        D0_px;
   Double_t        D0_py;
   Double_t        D0_pz;
   Double_t        D0_pt;
   Double_t        D0_p;
   Double_t        D0_E;
   Double_t        D0_kaonID;
   Double_t        D0_pionID;
   Double_t        D0_protonID;
   Double_t        D0_muonID;
   Double_t        D0_electronID;
   Double_t        D0_deuteronID;
   //Double_t        D0_isSignal;
   Double_t        D0_mcErrors;
   Double_t        D0_mcPDG;
   Double_t        D0_useCMSFrame_p;
   Double_t        D0_isSignal;
   Double_t        D0_isWrongCharge;
   Double_t        D0_isSignalAcceptMissingGamma;
   Double_t        D0_nCDCHits;
   Double_t        D0_nSVDHits;
   Double_t        D0_nVXDHits;
   Double_t        D0_clusterNHits;
   Double_t        D0_cosTheta;
   Double_t        D0_theta;
   Double_t        D0_pidPairProbabilityExpert_211_321_ALL;
   Double_t        D0_pidPairProbabilityExpert_321_211_ALL;
   Double_t        D0_pidPairProbabilityExpert_321_211_CDC;
   Double_t        D0_pidPairProbabilityExpert_211_321_CDC;
   Double_t        D0_pidPairProbabilityExpert_321_211_SVD;
   Double_t        D0_pidPairProbabilityExpert_211_321_SVD;
   Double_t        D0_pidPairProbabilityExpert_321_211_CDC_SVD;
   Double_t        D0_pidPairProbabilityExpert_211_321_CDC_SVD;
   Double_t        D0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;
   Double_t        D0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;
   Double_t        D0_dM;
   Double_t        D0_vtxChi2;
   Double_t        D0_vtxNDF;
   Double_t        D0_dQ;
   Double_t        D0_Q;
   Double_t        D0_charge;
   Double_t        Dst_M;
   Double_t        Dst_ErrM;
   Double_t        Dst_SigM;
   Double_t        Dst_InvM;
   Double_t        Dst_px;
   Double_t        Dst_py;
   Double_t        Dst_pz;
   Double_t        Dst_pt;
   Double_t        Dst_p;
   Double_t        Dst_E;
   Double_t        Dst_kaonID;
   Double_t        Dst_pionID;
   Double_t        Dst_protonID;
   Double_t        Dst_muonID;
   Double_t        Dst_electronID;
   Double_t        Dst_deuteronID;
   //Double_t        Dst_isSignal;
   Double_t        Dst_mcErrors;
   Double_t        Dst_mcPDG;
   Double_t        Dst_useCMSFrame_p;
   Double_t        Dst_isSignal;
   Double_t        Dst_isWrongCharge;
   Double_t        Dst_isSignalAcceptMissingGamma;
   Double_t        Dst_nCDCHits;
   Double_t        Dst_nSVDHits;
   Double_t        Dst_nVXDHits;
   Double_t        Dst_clusterNHits;
   Double_t        Dst_cosTheta;
   Double_t        Dst_theta;
   Double_t        Dst_pidPairProbabilityExpert_211_321_ALL;
   Double_t        Dst_pidPairProbabilityExpert_321_211_ALL;
   Double_t        Dst_pidPairProbabilityExpert_321_211_CDC;
   Double_t        Dst_pidPairProbabilityExpert_211_321_CDC;
   Double_t        Dst_pidPairProbabilityExpert_321_211_SVD;
   Double_t        Dst_pidPairProbabilityExpert_211_321_SVD;
   Double_t        Dst_pidPairProbabilityExpert_321_211_CDC_SVD;
   Double_t        Dst_pidPairProbabilityExpert_211_321_CDC_SVD;
   Double_t        Dst_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;
   Double_t        Dst_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;
   Double_t        Dst_dM;
   Double_t        Dst_dQ;
   Double_t        Dst_Q;
   Double_t        Dst_charge;

   // List of branches
   TBranch        *b___experiment__;   //!
   TBranch        *b___run__;   //!
   TBranch        *b___event__;   //!
   TBranch        *b___candidate__;   //!
   TBranch        *b___ncandidates__;   //!
   TBranch        *b___weight__;   //!
   TBranch        *b_D0_pi0_gamma_0_M;   //!
   TBranch        *b_D0_pi0_gamma_0_ErrM;   //!
   TBranch        *b_D0_pi0_gamma_0_SigM;   //!
   TBranch        *b_D0_pi0_gamma_0_InvM;   //!
   TBranch        *b_D0_pi0_gamma_0_px;   //!
   TBranch        *b_D0_pi0_gamma_0_py;   //!
   TBranch        *b_D0_pi0_gamma_0_pz;   //!
   TBranch        *b_D0_pi0_gamma_0_pt;   //!
   TBranch        *b_D0_pi0_gamma_0_p;   //!
   TBranch        *b_D0_pi0_gamma_0_E;   //!
   TBranch        *b_D0_pi0_gamma_0_kaonID;   //!
   TBranch        *b_D0_pi0_gamma_0_pionID;   //!
   TBranch        *b_D0_pi0_gamma_0_protonID;   //!
   TBranch        *b_D0_pi0_gamma_0_muonID;   //!
   TBranch        *b_D0_pi0_gamma_0_electronID;   //!
   TBranch        *b_D0_pi0_gamma_0_deuteronID;   //!
   //TBranch        *b_D0_pi0_gamma_0_isSignal;   //! fisshy
   TBranch        *b_D0_pi0_gamma_0_mcErrors;   //!
   TBranch        *b_D0_pi0_gamma_0_mcPDG;   //!
   TBranch        *b_D0_pi0_gamma_0_useCMSFrame_p;   //!
   TBranch        *b_D0_pi0_gamma_0_isSignal;   //!
   TBranch        *b_D0_pi0_gamma_0_isWrongCharge;   //!
   TBranch        *b_D0_pi0_gamma_0_isSignalAcceptMissingGamma;   //!
   TBranch        *b_D0_pi0_gamma_0_nCDCHits;   //!
   TBranch        *b_D0_pi0_gamma_0_nSVDHits;   //!
   TBranch        *b_D0_pi0_gamma_0_nVXDHits;   //!
   TBranch        *b_D0_pi0_gamma_0_clusterNHits;   //!
   TBranch        *b_D0_pi0_gamma_0_cosTheta;   //!
   TBranch        *b_D0_pi0_gamma_0_theta;   //!
   TBranch        *b_D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_ALL;   //!
   TBranch        *b_D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_ALL;   //!
   TBranch        *b_D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC;   //!
   TBranch        *b_D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC;   //!
   TBranch        *b_D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_SVD;   //!
   TBranch        *b_D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_SVD;   //!
   TBranch        *b_D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC_SVD;   //!
   TBranch        *b_D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC_SVD;   //!
   TBranch        *b_D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_pi0_gamma_1_M;   //!
   TBranch        *b_D0_pi0_gamma_1_ErrM;   //!
   TBranch        *b_D0_pi0_gamma_1_SigM;   //!
   TBranch        *b_D0_pi0_gamma_1_InvM;   //!
   TBranch        *b_D0_pi0_gamma_1_px;   //!
   TBranch        *b_D0_pi0_gamma_1_py;   //!
   TBranch        *b_D0_pi0_gamma_1_pz;   //!
   TBranch        *b_D0_pi0_gamma_1_pt;   //!
   TBranch        *b_D0_pi0_gamma_1_p;   //!
   TBranch        *b_D0_pi0_gamma_1_E;   //!
   TBranch        *b_D0_pi0_gamma_1_kaonID;   //!
   TBranch        *b_D0_pi0_gamma_1_pionID;   //!
   TBranch        *b_D0_pi0_gamma_1_protonID;   //!
   TBranch        *b_D0_pi0_gamma_1_muonID;   //!
   TBranch        *b_D0_pi0_gamma_1_electronID;   //!
   TBranch        *b_D0_pi0_gamma_1_deuteronID;   //!
   //TBranch        *b_D0_pi0_gamma_1_isSignal;   //! fishy
   TBranch        *b_D0_pi0_gamma_1_mcErrors;   //!
   TBranch        *b_D0_pi0_gamma_1_mcPDG;   //!
   TBranch        *b_D0_pi0_gamma_1_useCMSFrame_p;   //!
   TBranch        *b_D0_pi0_gamma_1_isSignal;   //!
   TBranch        *b_D0_pi0_gamma_1_isWrongCharge;   //!
   TBranch        *b_D0_pi0_gamma_1_isSignalAcceptMissingGamma;   //!
   TBranch        *b_D0_pi0_gamma_1_nCDCHits;   //!
   TBranch        *b_D0_pi0_gamma_1_nSVDHits;   //!
   TBranch        *b_D0_pi0_gamma_1_nVXDHits;   //!
   TBranch        *b_D0_pi0_gamma_1_clusterNHits;   //!
   TBranch        *b_D0_pi0_gamma_1_cosTheta;   //!
   TBranch        *b_D0_pi0_gamma_1_theta;   //!
   TBranch        *b_D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_ALL;   //!
   TBranch        *b_D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_ALL;   //!
   TBranch        *b_D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC;   //!
   TBranch        *b_D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC;   //!
   TBranch        *b_D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_SVD;   //!
   TBranch        *b_D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_SVD;   //!
   TBranch        *b_D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC_SVD;   //!
   TBranch        *b_D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC_SVD;   //!
   TBranch        *b_D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_K_M;   //!
   TBranch        *b_D0_K_ErrM;   //!
   TBranch        *b_D0_K_SigM;   //!
   TBranch        *b_D0_K_InvM;   //!
   TBranch        *b_D0_K_px;   //!
   TBranch        *b_D0_K_py;   //!
   TBranch        *b_D0_K_pz;   //!
   TBranch        *b_D0_K_pt;   //!
   TBranch        *b_D0_K_p;   //!
   TBranch        *b_D0_K_E;   //!
   TBranch        *b_D0_K_kaonID;   //!
   TBranch        *b_D0_K_pionID;   //!
   TBranch        *b_D0_K_protonID;   //!
   TBranch        *b_D0_K_muonID;   //!
   TBranch        *b_D0_K_electronID;   //!
   TBranch        *b_D0_K_deuteronID;   //!
   //TBranch        *b_D0_K_isSignal;   //!
   TBranch        *b_D0_K_mcErrors;   //!
   TBranch        *b_D0_K_mcPDG;   //!
   TBranch        *b_D0_K_useCMSFrame_p;   //!
   TBranch        *b_D0_K_isSignal;   //!
   TBranch        *b_D0_K_isWrongCharge;   //!
   TBranch        *b_D0_K_isSignalAcceptMissingGamma;   //!
   TBranch        *b_D0_K_nCDCHits;   //!
   TBranch        *b_D0_K_nSVDHits;   //!
   TBranch        *b_D0_K_nVXDHits;   //!
   TBranch        *b_D0_K_clusterNHits;   //!
   TBranch        *b_D0_K_cosTheta;   //!
   TBranch        *b_D0_K_theta;   //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_211_321_ALL;   //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_321_211_ALL;   //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_321_211_CDC;   //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_211_321_CDC;   //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_321_211_SVD;   //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_211_321_SVD;   //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_321_211_CDC_SVD;   //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_211_321_CDC_SVD;   //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_K_Q_masses;   //!
   TBranch        *b_D0_K_charge;   //!
   TBranch        *b_D0_pi_M;   //!
   TBranch        *b_D0_pi_ErrM;   //!
   TBranch        *b_D0_pi_SigM;   //!
   TBranch        *b_D0_pi_InvM;   //!
   TBranch        *b_D0_pi_px;   //!
   TBranch        *b_D0_pi_py;   //!
   TBranch        *b_D0_pi_pz;   //!
   TBranch        *b_D0_pi_pt;   //!
   TBranch        *b_D0_pi_p;   //!
   TBranch        *b_D0_pi_E;   //!
   TBranch        *b_D0_pi_kaonID;   //!
   TBranch        *b_D0_pi_pionID;   //!
   TBranch        *b_D0_pi_protonID;   //!
   TBranch        *b_D0_pi_muonID;   //!
   TBranch        *b_D0_pi_electronID;   //!
   TBranch        *b_D0_pi_deuteronID;   //!
   //TBranch        *b_D0_pi_isSignal;   //!
   TBranch        *b_D0_pi_mcErrors;   //!
   TBranch        *b_D0_pi_mcPDG;   //!
   TBranch        *b_D0_pi_useCMSFrame_p;   //!
   TBranch        *b_D0_pi_isSignal;   //!
   TBranch        *b_D0_pi_isWrongCharge;   //!
   TBranch        *b_D0_pi_isSignalAcceptMissingGamma;   //!
   TBranch        *b_D0_pi_nCDCHits;   //!
   TBranch        *b_D0_pi_nSVDHits;   //!
   TBranch        *b_D0_pi_nVXDHits;   //!
   TBranch        *b_D0_pi_clusterNHits;   //!
   TBranch        *b_D0_pi_cosTheta;   //!
   TBranch        *b_D0_pi_theta;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_211_321_ALL;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_321_211_ALL;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_321_211_CDC;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_211_321_CDC;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_321_211_SVD;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_211_321_SVD;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_321_211_CDC_SVD;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_211_321_CDC_SVD;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_pi_Q_masses;   //!
   TBranch        *b_D0_pi_charge;   //!
   TBranch        *b_D0_pi0_M;   //!
   TBranch        *b_D0_pi0_ErrM;   //!
   TBranch        *b_D0_pi0_SigM;   //!
   TBranch        *b_D0_pi0_InvM;   //!
   TBranch        *b_D0_pi0_px;   //!
   TBranch        *b_D0_pi0_py;   //!
   TBranch        *b_D0_pi0_pz;   //!
   TBranch        *b_D0_pi0_pt;   //!
   TBranch        *b_D0_pi0_p;   //!
   TBranch        *b_D0_pi0_E;   //!
   TBranch        *b_D0_pi0_kaonID;   //!
   TBranch        *b_D0_pi0_pionID;   //!
   TBranch        *b_D0_pi0_protonID;   //!
   TBranch        *b_D0_pi0_muonID;   //!
   TBranch        *b_D0_pi0_electronID;   //!
   TBranch        *b_D0_pi0_deuteronID;   //!
   //TBranch        *b_D0_pi0_isSignal;   //!
   TBranch        *b_D0_pi0_mcErrors;   //!
   TBranch        *b_D0_pi0_mcPDG;   //!
   TBranch        *b_D0_pi0_useCMSFrame_p;   //!
   TBranch        *b_D0_pi0_isSignal;   //!
   TBranch        *b_D0_pi0_isWrongCharge;   //!
   TBranch        *b_D0_pi0_isSignalAcceptMissingGamma;   //!
   TBranch        *b_D0_pi0_nCDCHits;   //!
   TBranch        *b_D0_pi0_nSVDHits;   //!
   TBranch        *b_D0_pi0_nVXDHits;   //!
   TBranch        *b_D0_pi0_clusterNHits;   //!
   TBranch        *b_D0_pi0_cosTheta;   //!
   TBranch        *b_D0_pi0_theta;   //!
   TBranch        *b_D0_pi0_pidPairProbabilityExpert_211_321_ALL;   //!
   TBranch        *b_D0_pi0_pidPairProbabilityExpert_321_211_ALL;   //!
   TBranch        *b_D0_pi0_pidPairProbabilityExpert_321_211_CDC;   //!
   TBranch        *b_D0_pi0_pidPairProbabilityExpert_211_321_CDC;   //!
   TBranch        *b_D0_pi0_pidPairProbabilityExpert_321_211_SVD;   //!
   TBranch        *b_D0_pi0_pidPairProbabilityExpert_211_321_SVD;   //!
   TBranch        *b_D0_pi0_pidPairProbabilityExpert_321_211_CDC_SVD;   //!
   TBranch        *b_D0_pi0_pidPairProbabilityExpert_211_321_CDC_SVD;   //!
   TBranch        *b_D0_pi0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_pi0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_pi0_Q_masses;   //!
   TBranch        *b_D0_pi0_charge;   //!
   TBranch        *b_pi_M;   //!
   TBranch        *b_pi_ErrM;   //!
   TBranch        *b_pi_SigM;   //!
   TBranch        *b_pi_InvM;   //!
   TBranch        *b_pi_px;   //!
   TBranch        *b_pi_py;   //!
   TBranch        *b_pi_pz;   //!
   TBranch        *b_pi_pt;   //!
   TBranch        *b_pi_p;   //!
   TBranch        *b_pi_E;   //!
   TBranch        *b_pi_kaonID;   //!
   TBranch        *b_pi_pionID;   //!
   TBranch        *b_pi_protonID;   //!
   TBranch        *b_pi_muonID;   //!
   TBranch        *b_pi_electronID;   //!
   TBranch        *b_pi_deuteronID;   //!
   //TBranch        *b_pi_isSignal;   //!
   TBranch        *b_pi_mcErrors;   //!
   TBranch        *b_pi_mcPDG;   //!
   TBranch        *b_pi_useCMSFrame_p;   //!
   TBranch        *b_pi_isSignal;   //!
   TBranch        *b_pi_isWrongCharge;   //!
   TBranch        *b_pi_isSignalAcceptMissingGamma;   //!
   TBranch        *b_pi_nCDCHits;   //!
   TBranch        *b_pi_nSVDHits;   //!
   TBranch        *b_pi_nVXDHits;   //!
   TBranch        *b_pi_clusterNHits;   //!
   TBranch        *b_pi_cosTheta;   //!
   TBranch        *b_pi_theta;   //!
   TBranch        *b_pi_pidPairProbabilityExpert_211_321_ALL;   //!
   TBranch        *b_pi_pidPairProbabilityExpert_321_211_ALL;   //!
   TBranch        *b_pi_pidPairProbabilityExpert_321_211_CDC;   //!
   TBranch        *b_pi_pidPairProbabilityExpert_211_321_CDC;   //!
   TBranch        *b_pi_pidPairProbabilityExpert_321_211_SVD;   //!
   TBranch        *b_pi_pidPairProbabilityExpert_211_321_SVD;   //!
   TBranch        *b_pi_pidPairProbabilityExpert_321_211_CDC_SVD;   //!
   TBranch        *b_pi_pidPairProbabilityExpert_211_321_CDC_SVD;   //!
   TBranch        *b_pi_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_pi_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_pi_Q_masses;   //!
   TBranch        *b_pi_charge;   //!
   TBranch        *b_D0_M;   //!
   TBranch        *b_D0_ErrM;   //!
   TBranch        *b_D0_SigM;   //!
   TBranch        *b_D0_InvM;   //!
   TBranch        *b_D0_px;   //!
   TBranch        *b_D0_py;   //!
   TBranch        *b_D0_pz;   //!
   TBranch        *b_D0_pt;   //!
   TBranch        *b_D0_p;   //!
   TBranch        *b_D0_E;   //!
   TBranch        *b_D0_kaonID;   //!
   TBranch        *b_D0_pionID;   //!
   TBranch        *b_D0_protonID;   //!
   TBranch        *b_D0_muonID;   //!
   TBranch        *b_D0_electronID;   //!
   TBranch        *b_D0_deuteronID;   //!
   //TBranch        *b_D0_isSignal;   //!
   TBranch        *b_D0_mcErrors;   //!
   TBranch        *b_D0_mcPDG;   //!
   TBranch        *b_D0_useCMSFrame_p;   //!
   TBranch        *b_D0_isSignal;   //!
   TBranch        *b_D0_isWrongCharge;   //!
   TBranch        *b_D0_isSignalAcceptMissingGamma;   //!
   TBranch        *b_D0_nCDCHits;   //!
   TBranch        *b_D0_nSVDHits;   //!
   TBranch        *b_D0_nVXDHits;   //!
   TBranch        *b_D0_clusterNHits;   //!
   TBranch        *b_D0_cosTheta;   //!
   TBranch        *b_D0_theta;   //!
   TBranch        *b_D0_pidPairProbabilityExpert_211_321_ALL;   //!
   TBranch        *b_D0_pidPairProbabilityExpert_321_211_ALL;   //!
   TBranch        *b_D0_pidPairProbabilityExpert_321_211_CDC;   //!
   TBranch        *b_D0_pidPairProbabilityExpert_211_321_CDC;   //!
   TBranch        *b_D0_pidPairProbabilityExpert_321_211_SVD;   //!
   TBranch        *b_D0_pidPairProbabilityExpert_211_321_SVD;   //!
   TBranch        *b_D0_pidPairProbabilityExpert_321_211_CDC_SVD;   //!
   TBranch        *b_D0_pidPairProbabilityExpert_211_321_CDC_SVD;   //!
   TBranch        *b_D0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_D0_dM;   //!
   TBranch        *b_D0_vtxChi2;   //!
   TBranch        *b_D0_vtxNDF;   //!
   TBranch        *b_D0_dQ;   //!
   TBranch        *b_D0_Q;   //!
   TBranch        *b_D0_charge;   //!
   TBranch        *b_Dst_M;   //!
   TBranch        *b_Dst_ErrM;   //!
   TBranch        *b_Dst_SigM;   //!
   TBranch        *b_Dst_InvM;   //!
   TBranch        *b_Dst_px;   //!
   TBranch        *b_Dst_py;   //!
   TBranch        *b_Dst_pz;   //!
   TBranch        *b_Dst_pt;   //!
   TBranch        *b_Dst_p;   //!
   TBranch        *b_Dst_E;   //!
   TBranch        *b_Dst_kaonID;   //!
   TBranch        *b_Dst_pionID;   //!
   TBranch        *b_Dst_protonID;   //!
   TBranch        *b_Dst_muonID;   //!
   TBranch        *b_Dst_electronID;   //!
   TBranch        *b_Dst_deuteronID;   //!
   //TBranch        *b_Dst_isSignal;   //!
   TBranch        *b_Dst_mcErrors;   //!
   TBranch        *b_Dst_mcPDG;   //!
   TBranch        *b_Dst_useCMSFrame_p;   //!
   TBranch        *b_Dst_isSignal;   //!
   TBranch        *b_Dst_isWrongCharge;   //!
   TBranch        *b_Dst_isSignalAcceptMissingGamma;   //!
   TBranch        *b_Dst_nCDCHits;   //!
   TBranch        *b_Dst_nSVDHits;   //!
   TBranch        *b_Dst_nVXDHits;   //!
   TBranch        *b_Dst_clusterNHits;   //!
   TBranch        *b_Dst_cosTheta;   //!
   TBranch        *b_Dst_theta;   //!
   TBranch        *b_Dst_pidPairProbabilityExpert_211_321_ALL;   //!
   TBranch        *b_Dst_pidPairProbabilityExpert_321_211_ALL;   //!
   TBranch        *b_Dst_pidPairProbabilityExpert_321_211_CDC;   //!
   TBranch        *b_Dst_pidPairProbabilityExpert_211_321_CDC;   //!
   TBranch        *b_Dst_pidPairProbabilityExpert_321_211_SVD;   //!
   TBranch        *b_Dst_pidPairProbabilityExpert_211_321_SVD;   //!
   TBranch        *b_Dst_pidPairProbabilityExpert_321_211_CDC_SVD;   //!
   TBranch        *b_Dst_pidPairProbabilityExpert_211_321_CDC_SVD;   //!
   TBranch        *b_Dst_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_Dst_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH;   //!
   TBranch        *b_Dst_dM;   //!
   TBranch        *b_Dst_dQ;   //!
   TBranch        *b_Dst_Q;   //!
   TBranch        *b_Dst_charge;   //!

   CharmAnalysis(Config config, std::string samples);
   virtual ~CharmAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree, Config config);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CharmAnalysis_cxx
CharmAnalysis::CharmAnalysis(Config myconfig, std::string samples) : fChain(0) 
{

  //Config
  config = myconfig;
  nameOfSample = samples;
  //nameOfSystematic  = systematics;
  TTree* tree;

  //Reco analysis
  TString TreeName = "";

  if(config.Channel == "kpi" && config.Sign=="Right")
    TreeName = "DstD0PiKPiRS";
  else if(config.Channel == "kpi" && config.Sign=="Wrong")
    TreeName = "DstD0PiKPiWS";
  else if(config.Channel == "kpipi0" && config.Sign=="Right")
    TreeName = "DstD0PiKPipi0RS";
  else if(config.Channel == "kpipi0" && config.Sign=="Wrong")
    TreeName = "DstD0PiKPipi0WS";

  TChain *chain = new TChain(TreeName,"");
  //chain->Add((config.InputFileDir+nameOfSample+"/*.root").c_str());
  chain->Add((config.InputFileDir+"/"+nameOfSample+"/ouput_charm_dst_channels_newRel.root").c_str());
  tree=chain;
  Init(tree,config);//nameOfSystematic

}


CharmAnalysis::~CharmAnalysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CharmAnalysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CharmAnalysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void CharmAnalysis::Init(TTree *tree, Config config)
{
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("__experiment__", &__experiment__, &b___experiment__);
   fChain->SetBranchAddress("__run__", &__run__, &b___run__);
   fChain->SetBranchAddress("__event__", &__event__, &b___event__);
   fChain->SetBranchAddress("__candidate__", &__candidate__, &b___candidate__);
   fChain->SetBranchAddress("__ncandidates__", &__ncandidates__, &b___ncandidates__);
   fChain->SetBranchAddress("__weight__", &__weight__, &b___weight__);

   if(config.Channel=="kpipi0"){
     fChain->SetBranchAddress("D0_pi0_gamma_0_M", &D0_pi0_gamma_0_M, &b_D0_pi0_gamma_0_M);
     fChain->SetBranchAddress("D0_pi0_gamma_0_ErrM", &D0_pi0_gamma_0_ErrM, &b_D0_pi0_gamma_0_ErrM);
     fChain->SetBranchAddress("D0_pi0_gamma_0_SigM", &D0_pi0_gamma_0_SigM, &b_D0_pi0_gamma_0_SigM);
     fChain->SetBranchAddress("D0_pi0_gamma_0_InvM", &D0_pi0_gamma_0_InvM, &b_D0_pi0_gamma_0_InvM);
     fChain->SetBranchAddress("D0_pi0_gamma_0_px", &D0_pi0_gamma_0_px, &b_D0_pi0_gamma_0_px);
     fChain->SetBranchAddress("D0_pi0_gamma_0_py", &D0_pi0_gamma_0_py, &b_D0_pi0_gamma_0_py);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pz", &D0_pi0_gamma_0_pz, &b_D0_pi0_gamma_0_pz);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pt", &D0_pi0_gamma_0_pt, &b_D0_pi0_gamma_0_pt);
     fChain->SetBranchAddress("D0_pi0_gamma_0_p", &D0_pi0_gamma_0_p, &b_D0_pi0_gamma_0_p);
     fChain->SetBranchAddress("D0_pi0_gamma_0_E", &D0_pi0_gamma_0_E, &b_D0_pi0_gamma_0_E);
     fChain->SetBranchAddress("D0_pi0_gamma_0_kaonID", &D0_pi0_gamma_0_kaonID, &b_D0_pi0_gamma_0_kaonID);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pionID", &D0_pi0_gamma_0_pionID, &b_D0_pi0_gamma_0_pionID);
     fChain->SetBranchAddress("D0_pi0_gamma_0_protonID", &D0_pi0_gamma_0_protonID, &b_D0_pi0_gamma_0_protonID);
     fChain->SetBranchAddress("D0_pi0_gamma_0_muonID", &D0_pi0_gamma_0_muonID, &b_D0_pi0_gamma_0_muonID);
     fChain->SetBranchAddress("D0_pi0_gamma_0_electronID", &D0_pi0_gamma_0_electronID, &b_D0_pi0_gamma_0_electronID);
     fChain->SetBranchAddress("D0_pi0_gamma_0_deuteronID", &D0_pi0_gamma_0_deuteronID, &b_D0_pi0_gamma_0_deuteronID);
     fChain->SetBranchAddress("D0_pi0_gamma_0_isSignal", &D0_pi0_gamma_0_isSignal, &b_D0_pi0_gamma_0_isSignal);
     fChain->SetBranchAddress("D0_pi0_gamma_0_mcErrors", &D0_pi0_gamma_0_mcErrors, &b_D0_pi0_gamma_0_mcErrors);
     fChain->SetBranchAddress("D0_pi0_gamma_0_mcPDG", &D0_pi0_gamma_0_mcPDG, &b_D0_pi0_gamma_0_mcPDG);
     fChain->SetBranchAddress("D0_pi0_gamma_0_useCMSFrame_p", &D0_pi0_gamma_0_useCMSFrame_p, &b_D0_pi0_gamma_0_useCMSFrame_p);
     //    fChain->SetBranchAddress("D0_pi0_gamma_0_isSignal", &D0_pi0_gamma_0_isSignal, &b_D0_pi0_gamma_0_isSignal);
     fChain->SetBranchAddress("D0_pi0_gamma_0_isWrongCharge", &D0_pi0_gamma_0_isWrongCharge, &b_D0_pi0_gamma_0_isWrongCharge);
     fChain->SetBranchAddress("D0_pi0_gamma_0_isSignalAcceptMissingGamma", &D0_pi0_gamma_0_isSignalAcceptMissingGamma, &b_D0_pi0_gamma_0_isSignalAcceptMissingGamma);
     fChain->SetBranchAddress("D0_pi0_gamma_0_nCDCHits", &D0_pi0_gamma_0_nCDCHits, &b_D0_pi0_gamma_0_nCDCHits);
     fChain->SetBranchAddress("D0_pi0_gamma_0_nSVDHits", &D0_pi0_gamma_0_nSVDHits, &b_D0_pi0_gamma_0_nSVDHits);
     fChain->SetBranchAddress("D0_pi0_gamma_0_nVXDHits", &D0_pi0_gamma_0_nVXDHits, &b_D0_pi0_gamma_0_nVXDHits);
     fChain->SetBranchAddress("D0_pi0_gamma_0_clusterNHits", &D0_pi0_gamma_0_clusterNHits, &b_D0_pi0_gamma_0_clusterNHits);
     fChain->SetBranchAddress("D0_pi0_gamma_0_cosTheta", &D0_pi0_gamma_0_cosTheta, &b_D0_pi0_gamma_0_cosTheta);
     fChain->SetBranchAddress("D0_pi0_gamma_0_theta", &D0_pi0_gamma_0_theta, &b_D0_pi0_gamma_0_theta);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_ALL", &D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_ALL, &b_D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_ALL);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_ALL", &D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_ALL, &b_D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_ALL);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC", &D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC, &b_D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC", &D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC, &b_D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_SVD", &D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_SVD, &b_D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_SVD);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_SVD", &D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_SVD, &b_D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_SVD);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC_SVD", &D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC_SVD, &b_D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC_SVD);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC_SVD", &D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC_SVD, &b_D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC_SVD);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH", &D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH, &b_D0_pi0_gamma_0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH);
     fChain->SetBranchAddress("D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH", &D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH, &b_D0_pi0_gamma_0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH);
     fChain->SetBranchAddress("D0_pi0_gamma_1_M", &D0_pi0_gamma_1_M, &b_D0_pi0_gamma_1_M);
     fChain->SetBranchAddress("D0_pi0_gamma_1_ErrM", &D0_pi0_gamma_1_ErrM, &b_D0_pi0_gamma_1_ErrM);
     fChain->SetBranchAddress("D0_pi0_gamma_1_SigM", &D0_pi0_gamma_1_SigM, &b_D0_pi0_gamma_1_SigM);
     fChain->SetBranchAddress("D0_pi0_gamma_1_InvM", &D0_pi0_gamma_1_InvM, &b_D0_pi0_gamma_1_InvM);
     fChain->SetBranchAddress("D0_pi0_gamma_1_px", &D0_pi0_gamma_1_px, &b_D0_pi0_gamma_1_px);
     fChain->SetBranchAddress("D0_pi0_gamma_1_py", &D0_pi0_gamma_1_py, &b_D0_pi0_gamma_1_py);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pz", &D0_pi0_gamma_1_pz, &b_D0_pi0_gamma_1_pz);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pt", &D0_pi0_gamma_1_pt, &b_D0_pi0_gamma_1_pt);
     fChain->SetBranchAddress("D0_pi0_gamma_1_p", &D0_pi0_gamma_1_p, &b_D0_pi0_gamma_1_p);
     fChain->SetBranchAddress("D0_pi0_gamma_1_E", &D0_pi0_gamma_1_E, &b_D0_pi0_gamma_1_E);
     fChain->SetBranchAddress("D0_pi0_gamma_1_kaonID", &D0_pi0_gamma_1_kaonID, &b_D0_pi0_gamma_1_kaonID);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pionID", &D0_pi0_gamma_1_pionID, &b_D0_pi0_gamma_1_pionID);
     fChain->SetBranchAddress("D0_pi0_gamma_1_protonID", &D0_pi0_gamma_1_protonID, &b_D0_pi0_gamma_1_protonID);
     fChain->SetBranchAddress("D0_pi0_gamma_1_muonID", &D0_pi0_gamma_1_muonID, &b_D0_pi0_gamma_1_muonID);
     fChain->SetBranchAddress("D0_pi0_gamma_1_electronID", &D0_pi0_gamma_1_electronID, &b_D0_pi0_gamma_1_electronID);
     fChain->SetBranchAddress("D0_pi0_gamma_1_deuteronID", &D0_pi0_gamma_1_deuteronID, &b_D0_pi0_gamma_1_deuteronID);
     fChain->SetBranchAddress("D0_pi0_gamma_1_isSignal", &D0_pi0_gamma_1_isSignal, &b_D0_pi0_gamma_1_isSignal);
     fChain->SetBranchAddress("D0_pi0_gamma_1_mcErrors", &D0_pi0_gamma_1_mcErrors, &b_D0_pi0_gamma_1_mcErrors);
     fChain->SetBranchAddress("D0_pi0_gamma_1_mcPDG", &D0_pi0_gamma_1_mcPDG, &b_D0_pi0_gamma_1_mcPDG);
     fChain->SetBranchAddress("D0_pi0_gamma_1_useCMSFrame_p", &D0_pi0_gamma_1_useCMSFrame_p, &b_D0_pi0_gamma_1_useCMSFrame_p);
     //    fChain->SetBranchAddress("D0_pi0_gamma_1_isSignal", &D0_pi0_gamma_1_isSignal, &b_D0_pi0_gamma_1_isSignal);
     fChain->SetBranchAddress("D0_pi0_gamma_1_isWrongCharge", &D0_pi0_gamma_1_isWrongCharge, &b_D0_pi0_gamma_1_isWrongCharge);
     fChain->SetBranchAddress("D0_pi0_gamma_1_isSignalAcceptMissingGamma", &D0_pi0_gamma_1_isSignalAcceptMissingGamma, &b_D0_pi0_gamma_1_isSignalAcceptMissingGamma);
     fChain->SetBranchAddress("D0_pi0_gamma_1_nCDCHits", &D0_pi0_gamma_1_nCDCHits, &b_D0_pi0_gamma_1_nCDCHits);
     fChain->SetBranchAddress("D0_pi0_gamma_1_nSVDHits", &D0_pi0_gamma_1_nSVDHits, &b_D0_pi0_gamma_1_nSVDHits);
     fChain->SetBranchAddress("D0_pi0_gamma_1_nVXDHits", &D0_pi0_gamma_1_nVXDHits, &b_D0_pi0_gamma_1_nVXDHits);
     fChain->SetBranchAddress("D0_pi0_gamma_1_clusterNHits", &D0_pi0_gamma_1_clusterNHits, &b_D0_pi0_gamma_1_clusterNHits);
     fChain->SetBranchAddress("D0_pi0_gamma_1_cosTheta", &D0_pi0_gamma_1_cosTheta, &b_D0_pi0_gamma_1_cosTheta);
     fChain->SetBranchAddress("D0_pi0_gamma_1_theta", &D0_pi0_gamma_1_theta, &b_D0_pi0_gamma_1_theta);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_ALL", &D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_ALL, &b_D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_ALL);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_ALL", &D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_ALL, &b_D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_ALL);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC", &D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC, &b_D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC", &D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC, &b_D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_SVD", &D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_SVD, &b_D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_SVD);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_SVD", &D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_SVD, &b_D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_SVD);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC_SVD", &D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC_SVD, &b_D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC_SVD);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC_SVD", &D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC_SVD, &b_D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC_SVD);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH", &D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH, &b_D0_pi0_gamma_1_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH);
     fChain->SetBranchAddress("D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH", &D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH, &b_D0_pi0_gamma_1_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH);
   }
   
   fChain->SetBranchAddress("D0_K_M", &D0_K_M, &b_D0_K_M);
   fChain->SetBranchAddress("D0_K_ErrM", &D0_K_ErrM, &b_D0_K_ErrM);
   fChain->SetBranchAddress("D0_K_SigM", &D0_K_SigM, &b_D0_K_SigM);
   fChain->SetBranchAddress("D0_K_InvM", &D0_K_InvM, &b_D0_K_InvM);
   fChain->SetBranchAddress("D0_K_px", &D0_K_px, &b_D0_K_px);
   fChain->SetBranchAddress("D0_K_py", &D0_K_py, &b_D0_K_py);
   fChain->SetBranchAddress("D0_K_pz", &D0_K_pz, &b_D0_K_pz);
   fChain->SetBranchAddress("D0_K_pt", &D0_K_pt, &b_D0_K_pt);
   fChain->SetBranchAddress("D0_K_p", &D0_K_p, &b_D0_K_p);
   fChain->SetBranchAddress("D0_K_E", &D0_K_E, &b_D0_K_E);
   fChain->SetBranchAddress("D0_K_kaonID", &D0_K_kaonID, &b_D0_K_kaonID);
   fChain->SetBranchAddress("D0_K_pionID", &D0_K_pionID, &b_D0_K_pionID);
   fChain->SetBranchAddress("D0_K_protonID", &D0_K_protonID, &b_D0_K_protonID);
   fChain->SetBranchAddress("D0_K_muonID", &D0_K_muonID, &b_D0_K_muonID);
   fChain->SetBranchAddress("D0_K_electronID", &D0_K_electronID, &b_D0_K_electronID);
   fChain->SetBranchAddress("D0_K_deuteronID", &D0_K_deuteronID, &b_D0_K_deuteronID);
   fChain->SetBranchAddress("D0_K_isSignal", &D0_K_isSignal, &b_D0_K_isSignal);
   fChain->SetBranchAddress("D0_K_mcErrors", &D0_K_mcErrors, &b_D0_K_mcErrors);
   fChain->SetBranchAddress("D0_K_mcPDG", &D0_K_mcPDG, &b_D0_K_mcPDG);
   fChain->SetBranchAddress("D0_K_useCMSFrame_p", &D0_K_useCMSFrame_p, &b_D0_K_useCMSFrame_p);
//    fChain->SetBranchAddress("D0_K_isSignal", &D0_K_isSignal, &b_D0_K_isSignal);
   fChain->SetBranchAddress("D0_K_isWrongCharge", &D0_K_isWrongCharge, &b_D0_K_isWrongCharge);
   fChain->SetBranchAddress("D0_K_isSignalAcceptMissingGamma", &D0_K_isSignalAcceptMissingGamma, &b_D0_K_isSignalAcceptMissingGamma);
   fChain->SetBranchAddress("D0_K_nCDCHits", &D0_K_nCDCHits, &b_D0_K_nCDCHits);
   fChain->SetBranchAddress("D0_K_nSVDHits", &D0_K_nSVDHits, &b_D0_K_nSVDHits);
   fChain->SetBranchAddress("D0_K_nVXDHits", &D0_K_nVXDHits, &b_D0_K_nVXDHits);
   fChain->SetBranchAddress("D0_K_clusterNHits", &D0_K_clusterNHits, &b_D0_K_clusterNHits);
   fChain->SetBranchAddress("D0_K_cosTheta", &D0_K_cosTheta, &b_D0_K_cosTheta);
   fChain->SetBranchAddress("D0_K_theta", &D0_K_theta, &b_D0_K_theta);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_211_321_ALL", &D0_K_pidPairProbabilityExpert_211_321_ALL, &b_D0_K_pidPairProbabilityExpert_211_321_ALL);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_321_211_ALL", &D0_K_pidPairProbabilityExpert_321_211_ALL, &b_D0_K_pidPairProbabilityExpert_321_211_ALL);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_321_211_CDC", &D0_K_pidPairProbabilityExpert_321_211_CDC, &b_D0_K_pidPairProbabilityExpert_321_211_CDC);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_211_321_CDC", &D0_K_pidPairProbabilityExpert_211_321_CDC, &b_D0_K_pidPairProbabilityExpert_211_321_CDC);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_321_211_SVD", &D0_K_pidPairProbabilityExpert_321_211_SVD, &b_D0_K_pidPairProbabilityExpert_321_211_SVD);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_211_321_SVD", &D0_K_pidPairProbabilityExpert_211_321_SVD, &b_D0_K_pidPairProbabilityExpert_211_321_SVD);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_321_211_CDC_SVD", &D0_K_pidPairProbabilityExpert_321_211_CDC_SVD, &b_D0_K_pidPairProbabilityExpert_321_211_CDC_SVD);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_211_321_CDC_SVD", &D0_K_pidPairProbabilityExpert_211_321_CDC_SVD, &b_D0_K_pidPairProbabilityExpert_211_321_CDC_SVD);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH", &D0_K_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH, &b_D0_K_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH", &D0_K_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH, &b_D0_K_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH);
   fChain->SetBranchAddress("D0_K_Q_masses", &D0_K_Q_masses, &b_D0_K_Q_masses);
   fChain->SetBranchAddress("D0_K_charge", &D0_K_charge, &b_D0_K_charge);
   fChain->SetBranchAddress("D0_pi_M", &D0_pi_M, &b_D0_pi_M);
   fChain->SetBranchAddress("D0_pi_ErrM", &D0_pi_ErrM, &b_D0_pi_ErrM);
   fChain->SetBranchAddress("D0_pi_SigM", &D0_pi_SigM, &b_D0_pi_SigM);
   fChain->SetBranchAddress("D0_pi_InvM", &D0_pi_InvM, &b_D0_pi_InvM);
   fChain->SetBranchAddress("D0_pi_px", &D0_pi_px, &b_D0_pi_px);
   fChain->SetBranchAddress("D0_pi_py", &D0_pi_py, &b_D0_pi_py);
   fChain->SetBranchAddress("D0_pi_pz", &D0_pi_pz, &b_D0_pi_pz);
   fChain->SetBranchAddress("D0_pi_pt", &D0_pi_pt, &b_D0_pi_pt);
   fChain->SetBranchAddress("D0_pi_p", &D0_pi_p, &b_D0_pi_p);
   fChain->SetBranchAddress("D0_pi_E", &D0_pi_E, &b_D0_pi_E);
   fChain->SetBranchAddress("D0_pi_kaonID", &D0_pi_kaonID, &b_D0_pi_kaonID);
   fChain->SetBranchAddress("D0_pi_pionID", &D0_pi_pionID, &b_D0_pi_pionID);
   fChain->SetBranchAddress("D0_pi_protonID", &D0_pi_protonID, &b_D0_pi_protonID);
   fChain->SetBranchAddress("D0_pi_muonID", &D0_pi_muonID, &b_D0_pi_muonID);
   fChain->SetBranchAddress("D0_pi_electronID", &D0_pi_electronID, &b_D0_pi_electronID);
   fChain->SetBranchAddress("D0_pi_deuteronID", &D0_pi_deuteronID, &b_D0_pi_deuteronID);
   fChain->SetBranchAddress("D0_pi_isSignal", &D0_pi_isSignal, &b_D0_pi_isSignal);
   fChain->SetBranchAddress("D0_pi_mcErrors", &D0_pi_mcErrors, &b_D0_pi_mcErrors);
   fChain->SetBranchAddress("D0_pi_mcPDG", &D0_pi_mcPDG, &b_D0_pi_mcPDG);
   fChain->SetBranchAddress("D0_pi_useCMSFrame_p", &D0_pi_useCMSFrame_p, &b_D0_pi_useCMSFrame_p);
//    fChain->SetBranchAddress("D0_pi_isSignal", &D0_pi_isSignal, &b_D0_pi_isSignal);
   fChain->SetBranchAddress("D0_pi_isWrongCharge", &D0_pi_isWrongCharge, &b_D0_pi_isWrongCharge);
   fChain->SetBranchAddress("D0_pi_isSignalAcceptMissingGamma", &D0_pi_isSignalAcceptMissingGamma, &b_D0_pi_isSignalAcceptMissingGamma);
   fChain->SetBranchAddress("D0_pi_nCDCHits", &D0_pi_nCDCHits, &b_D0_pi_nCDCHits);
   fChain->SetBranchAddress("D0_pi_nSVDHits", &D0_pi_nSVDHits, &b_D0_pi_nSVDHits);
   fChain->SetBranchAddress("D0_pi_nVXDHits", &D0_pi_nVXDHits, &b_D0_pi_nVXDHits);
   fChain->SetBranchAddress("D0_pi_clusterNHits", &D0_pi_clusterNHits, &b_D0_pi_clusterNHits);
   fChain->SetBranchAddress("D0_pi_cosTheta", &D0_pi_cosTheta, &b_D0_pi_cosTheta);
   fChain->SetBranchAddress("D0_pi_theta", &D0_pi_theta, &b_D0_pi_theta);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_211_321_ALL", &D0_pi_pidPairProbabilityExpert_211_321_ALL, &b_D0_pi_pidPairProbabilityExpert_211_321_ALL);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_321_211_ALL", &D0_pi_pidPairProbabilityExpert_321_211_ALL, &b_D0_pi_pidPairProbabilityExpert_321_211_ALL);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_321_211_CDC", &D0_pi_pidPairProbabilityExpert_321_211_CDC, &b_D0_pi_pidPairProbabilityExpert_321_211_CDC);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_211_321_CDC", &D0_pi_pidPairProbabilityExpert_211_321_CDC, &b_D0_pi_pidPairProbabilityExpert_211_321_CDC);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_321_211_SVD", &D0_pi_pidPairProbabilityExpert_321_211_SVD, &b_D0_pi_pidPairProbabilityExpert_321_211_SVD);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_211_321_SVD", &D0_pi_pidPairProbabilityExpert_211_321_SVD, &b_D0_pi_pidPairProbabilityExpert_211_321_SVD);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_321_211_CDC_SVD", &D0_pi_pidPairProbabilityExpert_321_211_CDC_SVD, &b_D0_pi_pidPairProbabilityExpert_321_211_CDC_SVD);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_211_321_CDC_SVD", &D0_pi_pidPairProbabilityExpert_211_321_CDC_SVD, &b_D0_pi_pidPairProbabilityExpert_211_321_CDC_SVD);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH", &D0_pi_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH, &b_D0_pi_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH", &D0_pi_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH, &b_D0_pi_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH);
   fChain->SetBranchAddress("D0_pi_Q_masses", &D0_pi_Q_masses, &b_D0_pi_Q_masses);
   fChain->SetBranchAddress("D0_pi_charge", &D0_pi_charge, &b_D0_pi_charge);
   if(config.Channel=="kpipi0"){
     fChain->SetBranchAddress("D0_pi0_M", &D0_pi0_M, &b_D0_pi0_M);
     fChain->SetBranchAddress("D0_pi0_ErrM", &D0_pi0_ErrM, &b_D0_pi0_ErrM);
     fChain->SetBranchAddress("D0_pi0_SigM", &D0_pi0_SigM, &b_D0_pi0_SigM);
     fChain->SetBranchAddress("D0_pi0_InvM", &D0_pi0_InvM, &b_D0_pi0_InvM);
     fChain->SetBranchAddress("D0_pi0_px", &D0_pi0_px, &b_D0_pi0_px);
     fChain->SetBranchAddress("D0_pi0_py", &D0_pi0_py, &b_D0_pi0_py);
     fChain->SetBranchAddress("D0_pi0_pz", &D0_pi0_pz, &b_D0_pi0_pz);
     fChain->SetBranchAddress("D0_pi0_pt", &D0_pi0_pt, &b_D0_pi0_pt);
     fChain->SetBranchAddress("D0_pi0_p", &D0_pi0_p, &b_D0_pi0_p);
     fChain->SetBranchAddress("D0_pi0_E", &D0_pi0_E, &b_D0_pi0_E);
     fChain->SetBranchAddress("D0_pi0_kaonID", &D0_pi0_kaonID, &b_D0_pi0_kaonID);
     fChain->SetBranchAddress("D0_pi0_pionID", &D0_pi0_pionID, &b_D0_pi0_pionID);
     fChain->SetBranchAddress("D0_pi0_protonID", &D0_pi0_protonID, &b_D0_pi0_protonID);
     fChain->SetBranchAddress("D0_pi0_muonID", &D0_pi0_muonID, &b_D0_pi0_muonID);
     fChain->SetBranchAddress("D0_pi0_electronID", &D0_pi0_electronID, &b_D0_pi0_electronID);
     fChain->SetBranchAddress("D0_pi0_deuteronID", &D0_pi0_deuteronID, &b_D0_pi0_deuteronID);
     fChain->SetBranchAddress("D0_pi0_isSignal", &D0_pi0_isSignal, &b_D0_pi0_isSignal);
     fChain->SetBranchAddress("D0_pi0_mcErrors", &D0_pi0_mcErrors, &b_D0_pi0_mcErrors);
     fChain->SetBranchAddress("D0_pi0_mcPDG", &D0_pi0_mcPDG, &b_D0_pi0_mcPDG);
     fChain->SetBranchAddress("D0_pi0_useCMSFrame_p", &D0_pi0_useCMSFrame_p, &b_D0_pi0_useCMSFrame_p);
     //    fChain->SetBranchAddress("D0_pi0_isSignal", &D0_pi0_isSignal, &b_D0_pi0_isSignal);
     fChain->SetBranchAddress("D0_pi0_isWrongCharge", &D0_pi0_isWrongCharge, &b_D0_pi0_isWrongCharge);
     fChain->SetBranchAddress("D0_pi0_isSignalAcceptMissingGamma", &D0_pi0_isSignalAcceptMissingGamma, &b_D0_pi0_isSignalAcceptMissingGamma);
     fChain->SetBranchAddress("D0_pi0_nCDCHits", &D0_pi0_nCDCHits, &b_D0_pi0_nCDCHits);
     fChain->SetBranchAddress("D0_pi0_nSVDHits", &D0_pi0_nSVDHits, &b_D0_pi0_nSVDHits);
     fChain->SetBranchAddress("D0_pi0_nVXDHits", &D0_pi0_nVXDHits, &b_D0_pi0_nVXDHits);
     fChain->SetBranchAddress("D0_pi0_clusterNHits", &D0_pi0_clusterNHits, &b_D0_pi0_clusterNHits);
     fChain->SetBranchAddress("D0_pi0_cosTheta", &D0_pi0_cosTheta, &b_D0_pi0_cosTheta);
     fChain->SetBranchAddress("D0_pi0_theta", &D0_pi0_theta, &b_D0_pi0_theta);
     fChain->SetBranchAddress("D0_pi0_pidPairProbabilityExpert_211_321_ALL", &D0_pi0_pidPairProbabilityExpert_211_321_ALL, &b_D0_pi0_pidPairProbabilityExpert_211_321_ALL);
     fChain->SetBranchAddress("D0_pi0_pidPairProbabilityExpert_321_211_ALL", &D0_pi0_pidPairProbabilityExpert_321_211_ALL, &b_D0_pi0_pidPairProbabilityExpert_321_211_ALL);
     fChain->SetBranchAddress("D0_pi0_pidPairProbabilityExpert_321_211_CDC", &D0_pi0_pidPairProbabilityExpert_321_211_CDC, &b_D0_pi0_pidPairProbabilityExpert_321_211_CDC);
     fChain->SetBranchAddress("D0_pi0_pidPairProbabilityExpert_211_321_CDC", &D0_pi0_pidPairProbabilityExpert_211_321_CDC, &b_D0_pi0_pidPairProbabilityExpert_211_321_CDC);
     fChain->SetBranchAddress("D0_pi0_pidPairProbabilityExpert_321_211_SVD", &D0_pi0_pidPairProbabilityExpert_321_211_SVD, &b_D0_pi0_pidPairProbabilityExpert_321_211_SVD);
     fChain->SetBranchAddress("D0_pi0_pidPairProbabilityExpert_211_321_SVD", &D0_pi0_pidPairProbabilityExpert_211_321_SVD, &b_D0_pi0_pidPairProbabilityExpert_211_321_SVD);
     fChain->SetBranchAddress("D0_pi0_pidPairProbabilityExpert_321_211_CDC_SVD", &D0_pi0_pidPairProbabilityExpert_321_211_CDC_SVD, &b_D0_pi0_pidPairProbabilityExpert_321_211_CDC_SVD);
     fChain->SetBranchAddress("D0_pi0_pidPairProbabilityExpert_211_321_CDC_SVD", &D0_pi0_pidPairProbabilityExpert_211_321_CDC_SVD, &b_D0_pi0_pidPairProbabilityExpert_211_321_CDC_SVD);
     fChain->SetBranchAddress("D0_pi0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH", &D0_pi0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH, &b_D0_pi0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH);
     fChain->SetBranchAddress("D0_pi0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH", &D0_pi0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH, &b_D0_pi0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH);
     fChain->SetBranchAddress("D0_pi0_Q_masses", &D0_pi0_Q_masses, &b_D0_pi0_Q_masses);
     fChain->SetBranchAddress("D0_pi0_charge", &D0_pi0_charge, &b_D0_pi0_charge);
   }

   fChain->SetBranchAddress("pi_M", &pi_M, &b_pi_M);
   fChain->SetBranchAddress("pi_ErrM", &pi_ErrM, &b_pi_ErrM);
   fChain->SetBranchAddress("pi_SigM", &pi_SigM, &b_pi_SigM);
   fChain->SetBranchAddress("pi_InvM", &pi_InvM, &b_pi_InvM);
   fChain->SetBranchAddress("pi_px", &pi_px, &b_pi_px);
   fChain->SetBranchAddress("pi_py", &pi_py, &b_pi_py);
   fChain->SetBranchAddress("pi_pz", &pi_pz, &b_pi_pz);
   fChain->SetBranchAddress("pi_pt", &pi_pt, &b_pi_pt);
   fChain->SetBranchAddress("pi_p", &pi_p, &b_pi_p);
   fChain->SetBranchAddress("pi_E", &pi_E, &b_pi_E);
   fChain->SetBranchAddress("pi_kaonID", &pi_kaonID, &b_pi_kaonID);
   fChain->SetBranchAddress("pi_pionID", &pi_pionID, &b_pi_pionID);
   fChain->SetBranchAddress("pi_protonID", &pi_protonID, &b_pi_protonID);
   fChain->SetBranchAddress("pi_muonID", &pi_muonID, &b_pi_muonID);
   fChain->SetBranchAddress("pi_electronID", &pi_electronID, &b_pi_electronID);
   fChain->SetBranchAddress("pi_deuteronID", &pi_deuteronID, &b_pi_deuteronID);
   fChain->SetBranchAddress("pi_isSignal", &pi_isSignal, &b_pi_isSignal);
   fChain->SetBranchAddress("pi_mcErrors", &pi_mcErrors, &b_pi_mcErrors);
   fChain->SetBranchAddress("pi_mcPDG", &pi_mcPDG, &b_pi_mcPDG);
   fChain->SetBranchAddress("pi_useCMSFrame_p", &pi_useCMSFrame_p, &b_pi_useCMSFrame_p);
//    fChain->SetBranchAddress("pi_isSignal", &pi_isSignal, &b_pi_isSignal);
   fChain->SetBranchAddress("pi_isWrongCharge", &pi_isWrongCharge, &b_pi_isWrongCharge);
   fChain->SetBranchAddress("pi_isSignalAcceptMissingGamma", &pi_isSignalAcceptMissingGamma, &b_pi_isSignalAcceptMissingGamma);
   fChain->SetBranchAddress("pi_nCDCHits", &pi_nCDCHits, &b_pi_nCDCHits);
   fChain->SetBranchAddress("pi_nSVDHits", &pi_nSVDHits, &b_pi_nSVDHits);
   fChain->SetBranchAddress("pi_nVXDHits", &pi_nVXDHits, &b_pi_nVXDHits);
   fChain->SetBranchAddress("pi_clusterNHits", &pi_clusterNHits, &b_pi_clusterNHits);
   fChain->SetBranchAddress("pi_cosTheta", &pi_cosTheta, &b_pi_cosTheta);
   fChain->SetBranchAddress("pi_theta", &pi_theta, &b_pi_theta);
   fChain->SetBranchAddress("pi_pidPairProbabilityExpert_211_321_ALL", &pi_pidPairProbabilityExpert_211_321_ALL, &b_pi_pidPairProbabilityExpert_211_321_ALL);
   fChain->SetBranchAddress("pi_pidPairProbabilityExpert_321_211_ALL", &pi_pidPairProbabilityExpert_321_211_ALL, &b_pi_pidPairProbabilityExpert_321_211_ALL);
   fChain->SetBranchAddress("pi_pidPairProbabilityExpert_321_211_CDC", &pi_pidPairProbabilityExpert_321_211_CDC, &b_pi_pidPairProbabilityExpert_321_211_CDC);
   fChain->SetBranchAddress("pi_pidPairProbabilityExpert_211_321_CDC", &pi_pidPairProbabilityExpert_211_321_CDC, &b_pi_pidPairProbabilityExpert_211_321_CDC);
   fChain->SetBranchAddress("pi_pidPairProbabilityExpert_321_211_SVD", &pi_pidPairProbabilityExpert_321_211_SVD, &b_pi_pidPairProbabilityExpert_321_211_SVD);
   fChain->SetBranchAddress("pi_pidPairProbabilityExpert_211_321_SVD", &pi_pidPairProbabilityExpert_211_321_SVD, &b_pi_pidPairProbabilityExpert_211_321_SVD);
   fChain->SetBranchAddress("pi_pidPairProbabilityExpert_321_211_CDC_SVD", &pi_pidPairProbabilityExpert_321_211_CDC_SVD, &b_pi_pidPairProbabilityExpert_321_211_CDC_SVD);
   fChain->SetBranchAddress("pi_pidPairProbabilityExpert_211_321_CDC_SVD", &pi_pidPairProbabilityExpert_211_321_CDC_SVD, &b_pi_pidPairProbabilityExpert_211_321_CDC_SVD);
   fChain->SetBranchAddress("pi_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH", &pi_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH, &b_pi_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH);
   fChain->SetBranchAddress("pi_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH", &pi_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH, &b_pi_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH);
   fChain->SetBranchAddress("pi_Q_masses", &pi_Q_masses, &b_pi_Q_masses);
   fChain->SetBranchAddress("pi_charge", &pi_charge, &b_pi_charge);
   fChain->SetBranchAddress("D0_M", &D0_M, &b_D0_M);
   fChain->SetBranchAddress("D0_ErrM", &D0_ErrM, &b_D0_ErrM);
   fChain->SetBranchAddress("D0_SigM", &D0_SigM, &b_D0_SigM);
   fChain->SetBranchAddress("D0_InvM", &D0_InvM, &b_D0_InvM);
   fChain->SetBranchAddress("D0_px", &D0_px, &b_D0_px);
   fChain->SetBranchAddress("D0_py", &D0_py, &b_D0_py);
   fChain->SetBranchAddress("D0_pz", &D0_pz, &b_D0_pz);
   fChain->SetBranchAddress("D0_pt", &D0_pt, &b_D0_pt);
   fChain->SetBranchAddress("D0_p", &D0_p, &b_D0_p);
   fChain->SetBranchAddress("D0_E", &D0_E, &b_D0_E);
   fChain->SetBranchAddress("D0_kaonID", &D0_kaonID, &b_D0_kaonID);
   fChain->SetBranchAddress("D0_pionID", &D0_pionID, &b_D0_pionID);
   fChain->SetBranchAddress("D0_protonID", &D0_protonID, &b_D0_protonID);
   fChain->SetBranchAddress("D0_muonID", &D0_muonID, &b_D0_muonID);
   fChain->SetBranchAddress("D0_electronID", &D0_electronID, &b_D0_electronID);
   fChain->SetBranchAddress("D0_deuteronID", &D0_deuteronID, &b_D0_deuteronID);
   fChain->SetBranchAddress("D0_isSignal", &D0_isSignal, &b_D0_isSignal);
   fChain->SetBranchAddress("D0_mcErrors", &D0_mcErrors, &b_D0_mcErrors);
   fChain->SetBranchAddress("D0_mcPDG", &D0_mcPDG, &b_D0_mcPDG);
   fChain->SetBranchAddress("D0_useCMSFrame_p", &D0_useCMSFrame_p, &b_D0_useCMSFrame_p);
//    fChain->SetBranchAddress("D0_isSignal", &D0_isSignal, &b_D0_isSignal);
   fChain->SetBranchAddress("D0_isWrongCharge", &D0_isWrongCharge, &b_D0_isWrongCharge);
   fChain->SetBranchAddress("D0_isSignalAcceptMissingGamma", &D0_isSignalAcceptMissingGamma, &b_D0_isSignalAcceptMissingGamma);
   fChain->SetBranchAddress("D0_nCDCHits", &D0_nCDCHits, &b_D0_nCDCHits);
   fChain->SetBranchAddress("D0_nSVDHits", &D0_nSVDHits, &b_D0_nSVDHits);
   fChain->SetBranchAddress("D0_nVXDHits", &D0_nVXDHits, &b_D0_nVXDHits);
   fChain->SetBranchAddress("D0_clusterNHits", &D0_clusterNHits, &b_D0_clusterNHits);
   fChain->SetBranchAddress("D0_cosTheta", &D0_cosTheta, &b_D0_cosTheta);
   fChain->SetBranchAddress("D0_theta", &D0_theta, &b_D0_theta);
   fChain->SetBranchAddress("D0_pidPairProbabilityExpert_211_321_ALL", &D0_pidPairProbabilityExpert_211_321_ALL, &b_D0_pidPairProbabilityExpert_211_321_ALL);
   fChain->SetBranchAddress("D0_pidPairProbabilityExpert_321_211_ALL", &D0_pidPairProbabilityExpert_321_211_ALL, &b_D0_pidPairProbabilityExpert_321_211_ALL);
   fChain->SetBranchAddress("D0_pidPairProbabilityExpert_321_211_CDC", &D0_pidPairProbabilityExpert_321_211_CDC, &b_D0_pidPairProbabilityExpert_321_211_CDC);
   fChain->SetBranchAddress("D0_pidPairProbabilityExpert_211_321_CDC", &D0_pidPairProbabilityExpert_211_321_CDC, &b_D0_pidPairProbabilityExpert_211_321_CDC);
   fChain->SetBranchAddress("D0_pidPairProbabilityExpert_321_211_SVD", &D0_pidPairProbabilityExpert_321_211_SVD, &b_D0_pidPairProbabilityExpert_321_211_SVD);
   fChain->SetBranchAddress("D0_pidPairProbabilityExpert_211_321_SVD", &D0_pidPairProbabilityExpert_211_321_SVD, &b_D0_pidPairProbabilityExpert_211_321_SVD);
   fChain->SetBranchAddress("D0_pidPairProbabilityExpert_321_211_CDC_SVD", &D0_pidPairProbabilityExpert_321_211_CDC_SVD, &b_D0_pidPairProbabilityExpert_321_211_CDC_SVD);
   fChain->SetBranchAddress("D0_pidPairProbabilityExpert_211_321_CDC_SVD", &D0_pidPairProbabilityExpert_211_321_CDC_SVD, &b_D0_pidPairProbabilityExpert_211_321_CDC_SVD);
   fChain->SetBranchAddress("D0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH", &D0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH, &b_D0_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH);
   fChain->SetBranchAddress("D0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH", &D0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH, &b_D0_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH);
   fChain->SetBranchAddress("D0_dM", &D0_dM, &b_D0_dM);
   fChain->SetBranchAddress("D0_vtxChi2", &D0_vtxChi2, &b_D0_vtxChi2);
   fChain->SetBranchAddress("D0_vtxNDF", &D0_vtxNDF, &b_D0_vtxNDF);
   fChain->SetBranchAddress("D0_dQ", &D0_dQ, &b_D0_dQ);
   fChain->SetBranchAddress("D0_Q", &D0_Q, &b_D0_Q);
   fChain->SetBranchAddress("D0_charge", &D0_charge, &b_D0_charge);
   fChain->SetBranchAddress("Dst_M", &Dst_M, &b_Dst_M);
   fChain->SetBranchAddress("Dst_ErrM", &Dst_ErrM, &b_Dst_ErrM);
   fChain->SetBranchAddress("Dst_SigM", &Dst_SigM, &b_Dst_SigM);
   fChain->SetBranchAddress("Dst_InvM", &Dst_InvM, &b_Dst_InvM);
   fChain->SetBranchAddress("Dst_px", &Dst_px, &b_Dst_px);
   fChain->SetBranchAddress("Dst_py", &Dst_py, &b_Dst_py);
   fChain->SetBranchAddress("Dst_pz", &Dst_pz, &b_Dst_pz);
   fChain->SetBranchAddress("Dst_pt", &Dst_pt, &b_Dst_pt);
   fChain->SetBranchAddress("Dst_p", &Dst_p, &b_Dst_p);
   fChain->SetBranchAddress("Dst_E", &Dst_E, &b_Dst_E);
   fChain->SetBranchAddress("Dst_kaonID", &Dst_kaonID, &b_Dst_kaonID);
   fChain->SetBranchAddress("Dst_pionID", &Dst_pionID, &b_Dst_pionID);
   fChain->SetBranchAddress("Dst_protonID", &Dst_protonID, &b_Dst_protonID);
   fChain->SetBranchAddress("Dst_muonID", &Dst_muonID, &b_Dst_muonID);
   fChain->SetBranchAddress("Dst_electronID", &Dst_electronID, &b_Dst_electronID);
   fChain->SetBranchAddress("Dst_deuteronID", &Dst_deuteronID, &b_Dst_deuteronID);
   fChain->SetBranchAddress("Dst_isSignal", &Dst_isSignal, &b_Dst_isSignal);
   fChain->SetBranchAddress("Dst_mcErrors", &Dst_mcErrors, &b_Dst_mcErrors);
   fChain->SetBranchAddress("Dst_mcPDG", &Dst_mcPDG, &b_Dst_mcPDG);
   fChain->SetBranchAddress("Dst_useCMSFrame_p", &Dst_useCMSFrame_p, &b_Dst_useCMSFrame_p);
//    fChain->SetBranchAddress("Dst_isSignal", &Dst_isSignal, &b_Dst_isSignal);
   fChain->SetBranchAddress("Dst_isWrongCharge", &Dst_isWrongCharge, &b_Dst_isWrongCharge);
   fChain->SetBranchAddress("Dst_isSignalAcceptMissingGamma", &Dst_isSignalAcceptMissingGamma, &b_Dst_isSignalAcceptMissingGamma);
   fChain->SetBranchAddress("Dst_nCDCHits", &Dst_nCDCHits, &b_Dst_nCDCHits);
   fChain->SetBranchAddress("Dst_nSVDHits", &Dst_nSVDHits, &b_Dst_nSVDHits);
   fChain->SetBranchAddress("Dst_nVXDHits", &Dst_nVXDHits, &b_Dst_nVXDHits);
   fChain->SetBranchAddress("Dst_clusterNHits", &Dst_clusterNHits, &b_Dst_clusterNHits);
   fChain->SetBranchAddress("Dst_cosTheta", &Dst_cosTheta, &b_Dst_cosTheta);
   fChain->SetBranchAddress("Dst_theta", &Dst_theta, &b_Dst_theta);
   fChain->SetBranchAddress("Dst_pidPairProbabilityExpert_211_321_ALL", &Dst_pidPairProbabilityExpert_211_321_ALL, &b_Dst_pidPairProbabilityExpert_211_321_ALL);
   fChain->SetBranchAddress("Dst_pidPairProbabilityExpert_321_211_ALL", &Dst_pidPairProbabilityExpert_321_211_ALL, &b_Dst_pidPairProbabilityExpert_321_211_ALL);
   fChain->SetBranchAddress("Dst_pidPairProbabilityExpert_321_211_CDC", &Dst_pidPairProbabilityExpert_321_211_CDC, &b_Dst_pidPairProbabilityExpert_321_211_CDC);
   fChain->SetBranchAddress("Dst_pidPairProbabilityExpert_211_321_CDC", &Dst_pidPairProbabilityExpert_211_321_CDC, &b_Dst_pidPairProbabilityExpert_211_321_CDC);
   fChain->SetBranchAddress("Dst_pidPairProbabilityExpert_321_211_SVD", &Dst_pidPairProbabilityExpert_321_211_SVD, &b_Dst_pidPairProbabilityExpert_321_211_SVD);
   fChain->SetBranchAddress("Dst_pidPairProbabilityExpert_211_321_SVD", &Dst_pidPairProbabilityExpert_211_321_SVD, &b_Dst_pidPairProbabilityExpert_211_321_SVD);
   fChain->SetBranchAddress("Dst_pidPairProbabilityExpert_321_211_CDC_SVD", &Dst_pidPairProbabilityExpert_321_211_CDC_SVD, &b_Dst_pidPairProbabilityExpert_321_211_CDC_SVD);
   fChain->SetBranchAddress("Dst_pidPairProbabilityExpert_211_321_CDC_SVD", &Dst_pidPairProbabilityExpert_211_321_CDC_SVD, &b_Dst_pidPairProbabilityExpert_211_321_CDC_SVD);
   fChain->SetBranchAddress("Dst_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH", &Dst_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH, &b_Dst_pidPairProbabilityExpert_321_211_CDC_SVD_TOP_ARICH);
   fChain->SetBranchAddress("Dst_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH", &Dst_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH, &b_Dst_pidPairProbabilityExpert_211_321_CDC_SVD_TOP_ARICH);
   fChain->SetBranchAddress("Dst_dM", &Dst_dM, &b_Dst_dM);
   fChain->SetBranchAddress("Dst_dQ", &Dst_dQ, &b_Dst_dQ);
   fChain->SetBranchAddress("Dst_Q", &Dst_Q, &b_Dst_Q);
   fChain->SetBranchAddress("Dst_charge", &Dst_charge, &b_Dst_charge);
   Notify();
}

Bool_t CharmAnalysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CharmAnalysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CharmAnalysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CharmAnalysis_cxx
