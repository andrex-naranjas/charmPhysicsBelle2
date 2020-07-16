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

   //Added later
   Double_t       Dst_charge;
   Double_t       D0_pi_charge;
   Double_t       dst1_charge;
   Double_t       pi_charge;
   Double_t       D0_pi_pidPairProbabilityExpert_321_211_ALL; //pion identified as kaon
   Double_t       D0_K_pidPairProbabilityExpert_211_321_ALL; //kaon identified as pion

   Double_t       D0_pi0_useCMSFrame_p;
   Double_t       D0_pi_isWrongCharge;


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
   Double_t        D0_pi0_gamma_0_isSignal;
   Double_t        D0_pi0_gamma_0_mcErrors;
   Double_t        D0_pi0_gamma_0_mcPDG;
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
   Double_t        D0_pi0_gamma_1_isSignal;
   Double_t        D0_pi0_gamma_1_mcErrors;
   Double_t        D0_pi0_gamma_1_mcPDG;
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
   Double_t        D0_K_isSignal;
   Double_t        D0_K_mcErrors;
   Double_t        D0_K_mcPDG;
   Double_t        D0_K_Q_masses;
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
   Double_t        D0_pi_isSignal;
   Double_t        D0_pi_mcErrors;
   Double_t        D0_pi_mcPDG;
   Double_t        D0_pi_Q_masses;
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
   Double_t        D0_pi0_isSignal;
   Double_t        D0_pi0_mcErrors;
   Double_t        D0_pi0_mcPDG;
   Double_t        D0_pi0_Q_masses;
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
   Double_t        pi_isSignal;
   Double_t        pi_mcErrors;
   Double_t        pi_mcPDG;
   Double_t        pi_Q_masses;
   Double_t        dst0_M;
   Double_t        dst0_ErrM;
   Double_t        dst0_SigM;
   Double_t        dst0_InvM;
   Double_t        dst0_px;
   Double_t        dst0_py;
   Double_t        dst0_pz;
   Double_t        dst0_pt;
   Double_t        dst0_p;
   Double_t        dst0_E;
   Double_t        dst0_kaonID;
   Double_t        dst0_pionID;
   Double_t        dst0_protonID;
   Double_t        dst0_muonID;
   Double_t        dst0_electronID;
   Double_t        dst0_deuteronID;
   Double_t        dst0_isSignal;
   Double_t        dst0_mcErrors;
   Double_t        dst0_mcPDG;
   Double_t        dst0_dM;
   Double_t        dst0_vtxChi2;
   Double_t        dst0_vtxNDF;
   Double_t        dst0_dQ;
   Double_t        dst0_Q;
   Double_t        dst1_M;
   Double_t        dst1_ErrM;
   Double_t        dst1_SigM;
   Double_t        dst1_InvM;
   Double_t        dst1_px;
   Double_t        dst1_py;
   Double_t        dst1_pz;
   Double_t        dst1_pt;
   Double_t        dst1_p;
   Double_t        dst1_E;
   Double_t        dst1_kaonID;
   Double_t        dst1_pionID;
   Double_t        dst1_protonID;
   Double_t        dst1_muonID;
   Double_t        dst1_electronID;
   Double_t        dst1_deuteronID;
   Double_t        dst1_isSignal;
   Double_t        dst1_mcErrors;
   Double_t        dst1_mcPDG;
   Double_t        dst1_dM;
   Double_t        dst1_vtxChi2;
   Double_t        dst1_vtxNDF;
   Double_t        dst1_dQ;
   Double_t        dst1_Q;
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
   Double_t        Dst_isSignal;
   Double_t        Dst_mcErrors;
   Double_t        Dst_mcPDG;
   Double_t        Dst_dM;
   Double_t        Dst_dQ;
   Double_t        Dst_Q;

   // List of branches
   //Added later
   TBranch        *b_Dst_charge;   //!
   TBranch        *b_D0_pi_charge;   //!
   TBranch        *b_dst1_charge;   //!
   TBranch        *b_pi_charge;   //!
   TBranch        *b_D0_pi_pidPairProbabilityExpert_321_211_ALL;  //!
   TBranch        *b_D0_K_pidPairProbabilityExpert_211_321_ALL;   //!
   TBranch        *b_D0_pi0_useCMSFrame_p;   //!
   TBranch        *b_D0_pi_isWrongCharge;   //!


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
   TBranch        *b_D0_pi0_gamma_0_isSignal;   //!
   TBranch        *b_D0_pi0_gamma_0_mcErrors;   //!
   TBranch        *b_D0_pi0_gamma_0_mcPDG;   //!
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
   TBranch        *b_D0_pi0_gamma_1_isSignal;   //!
   TBranch        *b_D0_pi0_gamma_1_mcErrors;   //!
   TBranch        *b_D0_pi0_gamma_1_mcPDG;   //!
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
   TBranch        *b_D0_K_isSignal;   //!
   TBranch        *b_D0_K_mcErrors;   //!
   TBranch        *b_D0_K_mcPDG;   //!
   TBranch        *b_D0_K_Q_masses;   //!
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
   TBranch        *b_D0_pi_isSignal;   //!
   TBranch        *b_D0_pi_mcErrors;   //!
   TBranch        *b_D0_pi_mcPDG;   //!
   TBranch        *b_D0_pi_Q_masses;   //!
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
   TBranch        *b_D0_pi0_isSignal;   //!
   TBranch        *b_D0_pi0_mcErrors;   //!
   TBranch        *b_D0_pi0_mcPDG;   //!
   TBranch        *b_D0_pi0_Q_masses;   //!
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
   TBranch        *b_pi_isSignal;   //!
   TBranch        *b_pi_mcErrors;   //!
   TBranch        *b_pi_mcPDG;   //!
   TBranch        *b_pi_Q_masses;   //!
   TBranch        *b_dst0_M;   //!
   TBranch        *b_dst0_ErrM;   //!
   TBranch        *b_dst0_SigM;   //!
   TBranch        *b_dst0_InvM;   //!
   TBranch        *b_dst0_px;   //!
   TBranch        *b_dst0_py;   //!
   TBranch        *b_dst0_pz;   //!
   TBranch        *b_dst0_pt;   //!
   TBranch        *b_dst0_p;   //!
   TBranch        *b_dst0_E;   //!
   TBranch        *b_dst0_kaonID;   //!
   TBranch        *b_dst0_pionID;   //!
   TBranch        *b_dst0_protonID;   //!
   TBranch        *b_dst0_muonID;   //!
   TBranch        *b_dst0_electronID;   //!
   TBranch        *b_dst0_deuteronID;   //!
   TBranch        *b_dst0_isSignal;   //!
   TBranch        *b_dst0_mcErrors;   //!
   TBranch        *b_dst0_mcPDG;   //!
   TBranch        *b_dst0_dM;   //!
   TBranch        *b_dst0_vtxChi2;   //!
   TBranch        *b_dst0_vtxNDF;   //!
   TBranch        *b_dst0_dQ;   //!
   TBranch        *b_dst0_Q;   //!
   TBranch        *b_dst1_M;   //!
   TBranch        *b_dst1_ErrM;   //!
   TBranch        *b_dst1_SigM;   //!
   TBranch        *b_dst1_InvM;   //!
   TBranch        *b_dst1_px;   //!
   TBranch        *b_dst1_py;   //!
   TBranch        *b_dst1_pz;   //!
   TBranch        *b_dst1_pt;   //!
   TBranch        *b_dst1_p;   //!
   TBranch        *b_dst1_E;   //!
   TBranch        *b_dst1_kaonID;   //!
   TBranch        *b_dst1_pionID;   //!
   TBranch        *b_dst1_protonID;   //!
   TBranch        *b_dst1_muonID;   //!
   TBranch        *b_dst1_electronID;   //!
   TBranch        *b_dst1_deuteronID;   //!
   TBranch        *b_dst1_isSignal;   //!
   TBranch        *b_dst1_mcErrors;   //!
   TBranch        *b_dst1_mcPDG;   //!
   TBranch        *b_dst1_dM;   //!
   TBranch        *b_dst1_vtxChi2;   //!
   TBranch        *b_dst1_vtxNDF;   //!
   TBranch        *b_dst1_dQ;   //!
   TBranch        *b_dst1_Q;   //!
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
   TBranch        *b_Dst_isSignal;   //!
   TBranch        *b_Dst_mcErrors;   //!
   TBranch        *b_Dst_mcPDG;   //!
   TBranch        *b_Dst_dM;   //!
   TBranch        *b_Dst_dQ;   //!
   TBranch        *b_Dst_Q;   //!

   CharmAnalysis(Config config, std::string samples);
   virtual ~CharmAnalysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree, Config config );
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
  TChain *chain = new TChain("DstD0PiKPipi0WS","");
  //chain->Add((config.InputFileDir+nameOfSample+"/*.root").c_str());
  chain->Add((config.InputFileDir+"/"+nameOfSample+"/ouput_charm_dst.root").c_str());
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
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   //Added later
   fChain->SetBranchAddress("Dst_charge", &Dst_charge, &b_Dst_charge);
   fChain->SetBranchAddress("D0_pi_charge", &D0_pi_charge, &b_D0_pi_charge);
   fChain->SetBranchAddress("dst1_charge", &dst1_charge, &b_dst1_charge);
   fChain->SetBranchAddress("pi_charge", &pi_charge, &b_pi_charge);
   fChain->SetBranchAddress("D0_pi_pidPairProbabilityExpert_321_211_ALL", &D0_pi_pidPairProbabilityExpert_321_211_ALL, &b_D0_pi_pidPairProbabilityExpert_321_211_ALL);
   fChain->SetBranchAddress("D0_K_pidPairProbabilityExpert_211_321_ALL", &D0_K_pidPairProbabilityExpert_211_321_ALL, &b_D0_K_pidPairProbabilityExpert_211_321_ALL);

   fChain->SetBranchAddress("D0_pi0_useCMSFrame_p", &D0_pi0_useCMSFrame_p, &b_D0_pi0_useCMSFrame_p);
   fChain->SetBranchAddress("D0_pi_isWrongCharge", &D0_pi_isWrongCharge, &b_D0_pi_isWrongCharge);

   fChain->SetBranchAddress("__experiment__", &__experiment__, &b___experiment__);
   fChain->SetBranchAddress("__run__", &__run__, &b___run__);
   fChain->SetBranchAddress("__event__", &__event__, &b___event__);
   fChain->SetBranchAddress("__candidate__", &__candidate__, &b___candidate__);
   fChain->SetBranchAddress("__ncandidates__", &__ncandidates__, &b___ncandidates__);
   fChain->SetBranchAddress("__weight__", &__weight__, &b___weight__);
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
   fChain->SetBranchAddress("D0_K_Q_masses", &D0_K_Q_masses, &b_D0_K_Q_masses);
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
   fChain->SetBranchAddress("D0_pi_Q_masses", &D0_pi_Q_masses, &b_D0_pi_Q_masses);
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
   fChain->SetBranchAddress("D0_pi0_Q_masses", &D0_pi0_Q_masses, &b_D0_pi0_Q_masses);
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
   fChain->SetBranchAddress("pi_Q_masses", &pi_Q_masses, &b_pi_Q_masses);
   fChain->SetBranchAddress("dst0_M", &dst0_M, &b_dst0_M);
   fChain->SetBranchAddress("dst0_ErrM", &dst0_ErrM, &b_dst0_ErrM);
   fChain->SetBranchAddress("dst0_SigM", &dst0_SigM, &b_dst0_SigM);
   fChain->SetBranchAddress("dst0_InvM", &dst0_InvM, &b_dst0_InvM);
   fChain->SetBranchAddress("dst0_px", &dst0_px, &b_dst0_px);
   fChain->SetBranchAddress("dst0_py", &dst0_py, &b_dst0_py);
   fChain->SetBranchAddress("dst0_pz", &dst0_pz, &b_dst0_pz);
   fChain->SetBranchAddress("dst0_pt", &dst0_pt, &b_dst0_pt);
   fChain->SetBranchAddress("dst0_p", &dst0_p, &b_dst0_p);
   fChain->SetBranchAddress("dst0_E", &dst0_E, &b_dst0_E);
   fChain->SetBranchAddress("dst0_kaonID", &dst0_kaonID, &b_dst0_kaonID);
   fChain->SetBranchAddress("dst0_pionID", &dst0_pionID, &b_dst0_pionID);
   fChain->SetBranchAddress("dst0_protonID", &dst0_protonID, &b_dst0_protonID);
   fChain->SetBranchAddress("dst0_muonID", &dst0_muonID, &b_dst0_muonID);
   fChain->SetBranchAddress("dst0_electronID", &dst0_electronID, &b_dst0_electronID);
   fChain->SetBranchAddress("dst0_deuteronID", &dst0_deuteronID, &b_dst0_deuteronID);
   fChain->SetBranchAddress("dst0_isSignal", &dst0_isSignal, &b_dst0_isSignal);
   fChain->SetBranchAddress("dst0_mcErrors", &dst0_mcErrors, &b_dst0_mcErrors);
   fChain->SetBranchAddress("dst0_mcPDG", &dst0_mcPDG, &b_dst0_mcPDG);
   fChain->SetBranchAddress("dst0_dM", &dst0_dM, &b_dst0_dM);
   fChain->SetBranchAddress("dst0_vtxChi2", &dst0_vtxChi2, &b_dst0_vtxChi2);
   fChain->SetBranchAddress("dst0_vtxNDF", &dst0_vtxNDF, &b_dst0_vtxNDF);
   fChain->SetBranchAddress("dst0_dQ", &dst0_dQ, &b_dst0_dQ);
   fChain->SetBranchAddress("dst0_Q", &dst0_Q, &b_dst0_Q);
   fChain->SetBranchAddress("dst1_M", &dst1_M, &b_dst1_M);
   fChain->SetBranchAddress("dst1_ErrM", &dst1_ErrM, &b_dst1_ErrM);
   fChain->SetBranchAddress("dst1_SigM", &dst1_SigM, &b_dst1_SigM);
   fChain->SetBranchAddress("dst1_InvM", &dst1_InvM, &b_dst1_InvM);
   fChain->SetBranchAddress("dst1_px", &dst1_px, &b_dst1_px);
   fChain->SetBranchAddress("dst1_py", &dst1_py, &b_dst1_py);
   fChain->SetBranchAddress("dst1_pz", &dst1_pz, &b_dst1_pz);
   fChain->SetBranchAddress("dst1_pt", &dst1_pt, &b_dst1_pt);
   fChain->SetBranchAddress("dst1_p", &dst1_p, &b_dst1_p);
   fChain->SetBranchAddress("dst1_E", &dst1_E, &b_dst1_E);
   fChain->SetBranchAddress("dst1_kaonID", &dst1_kaonID, &b_dst1_kaonID);
   fChain->SetBranchAddress("dst1_pionID", &dst1_pionID, &b_dst1_pionID);
   fChain->SetBranchAddress("dst1_protonID", &dst1_protonID, &b_dst1_protonID);
   fChain->SetBranchAddress("dst1_muonID", &dst1_muonID, &b_dst1_muonID);
   fChain->SetBranchAddress("dst1_electronID", &dst1_electronID, &b_dst1_electronID);
   fChain->SetBranchAddress("dst1_deuteronID", &dst1_deuteronID, &b_dst1_deuteronID);
   fChain->SetBranchAddress("dst1_isSignal", &dst1_isSignal, &b_dst1_isSignal);
   fChain->SetBranchAddress("dst1_mcErrors", &dst1_mcErrors, &b_dst1_mcErrors);
   fChain->SetBranchAddress("dst1_mcPDG", &dst1_mcPDG, &b_dst1_mcPDG);
   fChain->SetBranchAddress("dst1_dM", &dst1_dM, &b_dst1_dM);
   fChain->SetBranchAddress("dst1_vtxChi2", &dst1_vtxChi2, &b_dst1_vtxChi2);
   fChain->SetBranchAddress("dst1_vtxNDF", &dst1_vtxNDF, &b_dst1_vtxNDF);
   fChain->SetBranchAddress("dst1_dQ", &dst1_dQ, &b_dst1_dQ);
   fChain->SetBranchAddress("dst1_Q", &dst1_Q, &b_dst1_Q);
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
   fChain->SetBranchAddress("Dst_dM", &Dst_dM, &b_Dst_dM);
   fChain->SetBranchAddress("Dst_dQ", &Dst_dQ, &b_Dst_dQ);
   fChain->SetBranchAddress("Dst_Q", &Dst_Q, &b_Dst_Q);
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
