#define CharmAnalysis_cxx
#include "CharmAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <vector>

#include <unordered_map>
#include <map>
#include <memory>

#include <iostream>
#include <string>
#include <fstream>
#include <TTree.h>
#include <TFile.h>
#include "TChain.h"
#include "TMath.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TRandom3.h"


void CharmAnalysis::Loop()
{

  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  TFile* newfile;
  newfile = new TFile((config.OutputFileDir +  nameOfSample + ".root").c_str(),"RECREATE");
  
  TH1D* h_d0_m    = new TH1D("h_d0_m"  , "mass; M(K#pi#pi_0) [GeV]; Entries ",100,1.8,1.95);
  TH1D* h_d0_m_p    = new TH1D("h_d0_m_p"  , "mass; M(K#pi#pi_0) [GeV]; Entries ",100,1.8,1.95);

  TH1D* h_d0_m_neg    = new TH1D("h_d0_m_neg"  , "mass; M(K#pi#pi_0) [GeV]; Entries ",50,1.8,1.95);
  TH1D* h_d0_q    = new TH1D("h_d0_q"  , "Q; Q [MeV]; Entries ",50,0,12);
  
  TH1D* h_pi0_m   = new TH1D("h_pi0_m"  , "mass; M(K#pi#pi_0) [GeV]; Entries ",50,0.118,0.150);
  TH1D* h_pi0_q   = new TH1D("h_pi0_q"  , "Q; Q [MeV]; Entries ",50,0,12);
  
  TH1D* h_dst_m   = new TH1D("h_dst_m"  , "mass; M(K#pi#pi_0) [GeV]; Entries ",50,1.75,1.95);
  TH1D* h_dst_q   = new TH1D("h_dst_q"  , "Q; Q [MeV]; Entries ",50,0,12);

  TH1D* h_deltaM  = new TH1D("h_deltaM"  , "mass; #Delta M [GeV]; Entries ",100,0.14,0.16);
  
  //gaussian histo for testing RooFit
  TH1D *h_gauss = new TH1D("h_gauss", "Gaussian", 50, -10,10);
  TRandom3 *gRandom = new TRandom3();
  for (Int_t i = 0; i < 10000; i++) { Double_t x = gRandom->Gaus(0.0, 3); h_gauss->Fill(x, 1.); }

  Float_t d0_m=0.,d0_q=0,pi0_m=0.,pi0_q=0,dst_m=0.,dst_q=0.;
  Float_t mass_var=0., q_masses=0.;
  Float_t deltaM=0.;
  
  TLorentzVector pi_short(0.,0.,0.,0.), dstar_decay(0.,0.,0.,0.), d0_decay(0.,0.,0.,0.);
  TLorentzVector k_plus(0.,0.,0.,0.), pi0(0.,0.,0.,0.), pim(0.,0.,0.,0.), d0(0.,0.,0.,0.);
  TLorentzVector dstar(0.,0.,0.,0.);

  Int_t count_pos = 0;  
  Int_t count_neg = 0;    
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    
    if(jentry % 1000 == 0) std::cout<<"Processing event  "<<jentry<<"/"<<nentries<<std::endl;
    
    pi_short.SetPxPyPzE(pi_px,pi_py,pi_pz,pi_E);
    k_plus.SetPxPyPzE(D0_K_px,D0_K_py,D0_K_pz,D0_K_E);
    pi0.SetPxPyPzE(D0_pi0_px,D0_pi0_py,D0_pi0_pz,D0_pi0_E);
    pim.SetPxPyPzE(D0_pi_px,D0_pi_py,D0_pi_pz,D0_pi_E);
    d0.SetPxPyPzE(dst0_px,dst0_py,dst0_pz,dst0_E);
    dstar.SetPxPyPzE(Dst_px,Dst_py,Dst_pz,Dst_E);

    //dstar_decay = pi_short + k_plus + pim + pi0;
    dstar_decay = pi_short + d0;
    d0_decay = k_plus + pim + pi0;    
    q_masses = dstar_decay.M() - d0_decay.M() - pi_short.M();
    deltaM = dstar.M() - d0.M();
  
    TLorentzVector dummy(0.,0.,0.,0.);
    dummy  = k_plus + pi0 + pim;

    TVector3 pi0_vect = pi0.Vect();

    //std::cout<<pi0_m-pi0.M()<<std::endl;// (the same)

    if(Dst_charge>0) ++count_pos;
    if(Dst_charge<0) ++count_neg;

    // if(Dst_charge != D0_pi_charge) std::cout<<"Wrong sign   "<<Dst_charge<<"   "<<D0_pi_charge<<std::endl;

    dst_m=Dst_M;
    d0_m=dst0_M;
    pi0_m=D0_pi0_M;

    bool swappedFlag=true;

    if(D0_K_pidPairProbabilityExpert_211_321_ALL > 0.3 && D0_pi_pidPairProbabilityExpert_321_211_ALL > 0.3)
      if(dst0_M > 1.81 or dst0_M < 1.90){
	if(pi0_vect.Mag() > 0.45 && dummy.Pt()>2.5){
	  swappedFlag = false;
	}
      }

    swappedFlag=true;
    //D0_pi0_useCMSFrame_p > 0.45
    //std::cout<<dst0_isSignal<<std::endl;
        
    if(q_masses > 0.585 && Dst_charge == 1)h_d0_q->Fill(q_masses,1.);
    if(swappedFlag &&  pi0_vect.Mag() > 0.45 && dummy.Pt() > 2.5/1.00056 && dst0_isSignal==1 ){ h_d0_m->Fill(dummy.M(),1.);} //&& dummy.Pt()>2.5    Dst_charge == 1 && Dst_charge == D0_pi_charge && 
    if(swappedFlag && D0_pi0_p>0.45 && dst0_pt > 2.5/1.00056){ h_d0_m_p->Fill(d0_m,1.);}
    if(swappedFlag && D0_pi0_p>0.45 && dst0_pt > 2.5 && d0_m > 1.84 && d0_m < 1.88 ){ h_deltaM->Fill(deltaM,1.);}

    if(Dst_charge == -1 && Dst_charge == D0_pi_charge && swappedFlag ){ h_d0_m_neg->Fill(d0_m,1.);}
    if(pi0_m > 0.118 && pi0_m < 0.150 && true && Dst_charge == 1) h_pi0_m->Fill(pi0_m,1.);
    
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
  }
  
  // mixed mixed 0.51
  // charged charged 0.54
  // uubar uubar 1.61
  // ddbar ddbar 0.40
  // ssbar ssbar 0.38
  // ccbar ccbar 1.30
  // taupair taupair 0.919

  float lumi = 5.;
  if(nameOfSample == "signal") lumi = 0.;
  if(nameOfSample == "ccbar"  )lumi = 1.30e6;
  if(nameOfSample == "charged")lumi = 0.54e6;
  //if(nameOfSample == "charm")  lumi = 1.;
  if(nameOfSample == "ddbar")  lumi = 0.40e6;
  if(nameOfSample == "mixed")  lumi = 0.51e6;
  if(nameOfSample == "ssbar")  lumi = 0.38e6;
  if(nameOfSample == "taupair")lumi = 0.919e6;
  if(nameOfSample == "uubar")  lumi = 1.61e6;


  if(nameOfSample != "data" and false){  
    h_d0_m->Scale(1.0/ (h_d0_m->Integral()));
    h_pi0_m->Scale(1.0/(h_pi0_m->Integral()));
    h_d0_q->Scale(1.0/ (h_d0_q->Integral()));
  }


  std::cout<<h_d0_m->Integral()<<"  D0 mass integral"<<std::endl;
  std::cout<<count_pos<<"    "<<count_neg<<"    "<<count_pos-count_neg<<std::endl;


  newfile->cd();

  h_gauss->Write("h_gauss");
  h_d0_m->Write("h_d0_m");
  h_d0_m_p->Write("h_d0_m_p");
  h_d0_m_neg->Write("h_d0_m_neg");
  h_pi0_m->Write("h_pi0_m");
  h_d0_q->Write("h_d0_q");
  h_deltaM->Write("h_deltaM");
  
  delete h_d0_m;
  delete h_pi0_m;
  delete h_d0_q;
  
  newfile->Close("");
  delete newfile;
}
