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
#include "TGraph.h"



void CharmAnalysis::Loop()
{

  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  TFile* newfile;
  newfile = new TFile((config.OutputFileDir +  nameOfSample + "_" + config.Channel + "_" + config.Sign + ".root").c_str(),"RECREATE");
  std::cout<<"New sample:  "<<nameOfSample<<"  Channel:  "<<config.Channel<<"  Sign:  "<<config.Sign<<std::endl;

  TH1D* h_d0_m    = new TH1D("h_d0_m"  , "mass; M(K#pi#pi_0) [GeV]; Entries ",100,1.68,2.1);
  TH1D* h_d0_m_p  = new TH1D("h_d0_m_p", "mass; M(K#pi#pi_0) [GeV]; Entries ",100,1.68,2.1);
  TH2D* h_d0_2D   = new TH2D("h_d0_2D",  "mass; M(K#pi#pi_0) [GeV]; Entries ",100,1.8,1.95,100,1.8,1.95);

  TH1D* h_kaon_ID  = new TH1D("kaon_ID", "mass; M(K#pi#pi_0) [GeV]; Entries ",100,0,1);
  
  TH1D* h_pi0_m   = new TH1D("h_pi0_m" , "mass; M(K#pi#pi_0) [GeV]; Entries ",50,0.118,0.150);
  TH1D* h_pi0_q   = new TH1D("h_pi0_q" , "Q; Q [MeV]; Entries ",50,0,12);
  
  TH1D* h_deltaM  = new TH1D("h_deltaM", "mass; #Delta M [GeV]; Entries ",100,0.14,0.16);

  //For mva
  TH1D* h_d0_m_signal   = new TH1D("h_d0_m_signal" , "mass; M(K#pi#pi_0) [GeV]; Entries ",100,1.8,1.95);
  TH1D* h_d0_m_back     = new TH1D("h_d0_m_back"   , "mass; M(K#pi#pi_0) [GeV]; Entries ",100,1.8,1.95);
  TH1D* h_d0_m_sum      = new TH1D("h_d0_m_sum"    , "mass; M(K#pi#pi_0) [GeV]; Entries ",100,1.8,1.95);

  TH1D* h_p0_p_signal   = new TH1D("h_p0_p_signal" , "momentum; p(#pi_0) [GeV]; Entries ",100,0,4.5);
  TH1D* h_p0_p_back     = new TH1D("h_p0_p_back"   , "momentum; p(#pi_0) [GeV]; Entries ",100,0,4.5);

  TH1D* h_d0_p_signal   = new TH1D("h_d0_p_signal" , "momentum; p(K#pi#pi_0) [GeV]; Entries ",100,0,8.);
  TH1D* h_d0_p_back     = new TH1D("h_d0_p_back"   , "momentum; p(K#pi#pi_0) [GeV]; Entries ",100,0,8.);

  //kine variables  
  Float_t d0_m=0.,d0_q=0,pi0_m=0.,pi0_q=0,dst_m=0.,dst_q=0.;
  Float_t mass_var=0., q_masses=0.;
  Float_t deltaM=0.;
  Float_t swapped_K_E = 0., swapped_pi_E=0.;

  double gamma1_px = 0, gamma1_py = 0, gamma1_pz = 0, gamma1_E =0;
  double gamma2_px = 0, gamma2_py = 0, gamma2_pz = 0, gamma2_E =0;                 
  
  TLorentzVector pi_short(0.,0.,0.,0.), dstar_decay(0.,0.,0.,0.), d0_decay(0.,0.,0.,0.);
  TLorentzVector k_plus(0.,0.,0.,0.), pi0(0.,0.,0.,0.), pim(0.,0.,0.,0.), d0(0.,0.,0.,0.);
  TLorentzVector dstar(0.,0.,0.,0.);
  TLorentzVector gamma1(0.,0.,0.,0.), gamma2(0.,0.,0.,0.), pi0_gammas(0.,0.,0.,0.);

  TLorentzVector swappedD0(0.,0.,0.,0.), swappedK(0.,0.,0.,0.), swappedPi(0.,0.,0.,0.);

  //store variables to be used by roofit
  TTree deltaM_tree("deltaM", "tree_delta");
  Double_t value_deltaM;
  deltaM_tree.Branch("x", &value_deltaM);

  //store variables to be used in (t)mva
  TTree signal("signal", "signal");
  TTree background("background", "background");
  TTree combined("combined", "combined");
  Double_t value_D0_m=0., value_D0_p=0., value_p0_p=0., value_flag=0;
  signal.Branch("D0_m", &value_D0_m);
  signal.Branch("D0_p", &value_D0_p);
  signal.Branch("p0_p", &value_p0_p);
  signal.Branch("Class", &value_flag);
  background.Branch("D0_m", &value_D0_m);
  background.Branch("D0_p", &value_D0_p);
  background.Branch("p0_p", &value_p0_p);
  background.Branch("Class", &value_flag);
  combined.Branch("D0_m", &value_D0_m);
  combined.Branch("D0_p", &value_D0_p);
  combined.Branch("p0_p", &value_p0_p);
  combined.Branch("Class", &value_flag);


  //FOM, purity s/(s+b)
  int nPurities=20;
  std::vector<double> sig_pi0(nPurities); std::vector<double> sig_d0(nPurities); //sig.clear();
  std::vector<double> bkg_pi0(nPurities); std::vector<double> bkg_d0(nPurities); //bkg.clear();
  std::vector<double> cut_pi0(nPurities); std::vector<double> cut_d0(nPurities); //cut.clear();
  std::vector<double> fom_pi0(nPurities); std::vector<double> fom_d0(nPurities); //fom.clear();
  double step_pi0 = 0.025;  double step_d0 = 0.05;
  double off_pi0 = 0.3;  double off_d0 = 1.75;


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++){
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    
    if(jentry % 1000 == 0) std::cout<<"Processing event  "<<jentry<<"/"<<nentries<<std::endl;

    double scale = 1.00056; scale = 1.;
    
    pi_short.SetPxPyPzE(scale*pi_px,scale*pi_py,scale*pi_pz,pi_E);
    k_plus.SetPxPyPzE(scale*D0_K_px,scale*D0_K_py,scale*D0_K_pz,D0_K_E);
    if(config.Channel=="kpipi0") pi0.SetPxPyPzE(D0_pi0_px,D0_pi0_py,D0_pi0_pz,D0_pi0_E);
    pim.SetPxPyPzE(scale*D0_pi_px,scale*D0_pi_py,scale*D0_pi_pz,D0_pi_E);
    d0.SetPxPyPzE(D0_px,D0_py,D0_pz,D0_E);
    dstar.SetPxPyPzE(scale*Dst_px,scale*Dst_py,scale*Dst_pz,Dst_E);

    if(config.Channel=="kpipi0")   d0_decay = k_plus + pim + pi0;
    else if(config.Channel=="kpi") d0_decay = k_plus + pim;
    dstar_decay = pi_short + d0_decay;
    deltaM = dstar_decay.M() - d0_decay.M();

    q_masses = dstar_decay.M() - d0_decay.M() - pi_short.M();

    // swapped stuff
    swapped_K_E  = std::sqrt(std::pow(D0_K_px,2)  + std::pow(D0_K_py,2)  + std::pow(D0_K_pz,2)  + std::pow(pim.M(),2) );
    swapped_pi_E = std::sqrt(std::pow(D0_pi_px,2) + std::pow(D0_pi_py,2) + std::pow(D0_pi_pz,2) + std::pow(k_plus.M(),2));
    swappedK.SetPxPyPzE(scale*D0_K_px,scale*D0_K_py,scale*D0_K_pz,swapped_K_E);
    swappedPi.SetPxPyPzE(scale*D0_pi_px,scale*D0_pi_py,scale*D0_pi_pz,swapped_pi_E);
    swappedD0 = swappedK + swappedPi + pi0;


    TVector3 pi0_vect = pi0.Vect();
    //std::cout<<pi0_m-pi0.M()<<std::endl;// (the same)

    dst_m=Dst_M;
    d0_m=D0_M;
    pi0_m=D0_pi0_M;

    int chargeSelection=0;
    if(config.Sign == "Right")
      chargeSelection = 1;
    else if(config.Sign == "Wrong")
      chargeSelection = -1;

    bool kineCuts = false;
    double mass_low=0., mass_high=0., swap_low=0., swap_high=0.;
    if(config.Channel == "kpi"){
      kineCuts = true; mass_low=1.85; mass_high=1.88; swap_low=1.85; swap_high=1.88;
    }else if(config.Channel == "kpipi0"){
      mass_low=1.84; mass_high=1.88; swap_low=1.81; swap_high=1.90;
      if(pi0_vect.Mag() >= 0.45 && d0_decay.Pt() >= 2.5)
	kineCuts = true;
    }


    bool swappedFlag=true;
    if(D0_K_pidPairProbabilityExpert_211_321_ALL > 0.3 and D0_pi_pidPairProbabilityExpert_321_211_ALL > 0.3)
      if(swappedD0.M() > swap_low or swappedD0.M() < swap_high)
	{swappedFlag = false;}
    //swappedFlag=true;

    bool idFlag = false;
    if(D0_pi_pidPairProbabilityExpert_211_321_ALL>0.3 /*&& std::abs(D0_K_mcPDG) == 211*/) idFlag=true;
    idFlag=true;

    if(d0_decay.M() >= mass_low && d0_decay.M() <= mass_high /*D0_K_isSignal == 1 && D0_K_charge != chargeSelection*/) h_kaon_ID->Fill(D0_K_pidPairProbabilityExpert_321_211_ALL,1.);

    //if(idFlag && D0_K_charge != chargeSelection && D0_pi_charge == chargeSelection && Dst_charge == chargeSelection  && pi_charge == chargeSelection){h_d0_m->Fill(d0_decay.M(),1.);}
    if(D0_K_charge == chargeSelection && D0_pi_charge !=chargeSelection && Dst_charge != D0_K_charge && pi_charge == Dst_charge )    h_d0_2D->Fill(d0_decay.M(),swappedD0.M(),1.);
    if(swappedFlag && kineCuts  && D0_K_charge == chargeSelection && D0_pi_charge !=chargeSelection && idFlag){h_d0_m->Fill(d0_decay.M(),1.);}
    if(swappedFlag && kineCuts  && (d0_decay.M() >= mass_low && d0_decay.M() <= mass_high) && D0_K_charge == chargeSelection && D0_pi_charge != chargeSelection && idFlag){
      value_deltaM = deltaM; deltaM_tree.Fill();
      h_deltaM->Fill(deltaM,1.);
    }
    if(swappedFlag &&    D0_pi0_p > 0.45 &&    D0_pt > 2.5 && D0_K_charge == chargeSelection && idFlag ){ h_d0_m_p->Fill(d0_m,1.);}
    if(swappedFlag &&    D0_pi0_p > 0.45 &&    D0_pt > 2.5 or true) h_pi0_m->Fill(pi0.M(),1.);


    bool noNanVal = false;
    if(!std::isnan(value_D0_m) && !std::isnan(value_D0_p) && !std::isnan(value_p0_p) && !std::isinf(value_D0_m) && !std::isinf(value_D0_p) && !std::isinf(value_p0_p))
      noNanVal = true;

    value_D0_m=d0_decay.M(); value_D0_p=d0_decay.Pt(); value_p0_p=pi0_vect.Mag();


    //FOM, purity s/(s+b)
    if(D0_mcErrors == 0 or D0_mcErrors == 1 or D0_mcErrors == 2 or D0_mcErrors == 8 or D0_mcErrors == 16 or D0_mcErrors == 64)
      if(D0_K_charge == chargeSelection)
	for(int i = 0; i<nPurities; i++){	  
	  if(D0_pi0_p > step_pi0 * i + off_pi0 ){ sig_pi0.at(i) = sig_pi0.at(i)+1; cut_pi0.at(i) = step_pi0 * i  + off_pi0;}
	  if(D0_pt    > step_d0  * i + off_d0  ){ sig_d0.at(i)  = sig_d0.at(i)+1;  cut_d0.at(i)  = step_d0 * i   + off_d0;}
	}
    
    if(D0_mcErrors == 4 or D0_mcErrors == 20 or D0_mcErrors == 32 or D0_mcErrors == 48 or D0_mcErrors >= 128 or D0_mcErrors >= 256 or D0_mcErrors >= 512 or D0_mcErrors == 1024)
      if(D0_K_charge == chargeSelection)
	for(int i = 0; i<nPurities; i++){
	  if(D0_pi0_p > step_pi0 * i + off_pi0) bkg_pi0.at(i) = bkg_pi0.at(i)+1;
	  if(D0_pt    > step_d0  * i + off_d0 ) bkg_d0.at(i)  = bkg_d0.at(i)+1;
	}
	 

    // if(D0_isSignal==1 && pi_isSignal == 1 && D0_K_isSignal == 1 && D0_pi_isSignal == 1 && D0_pi0_isSignal == 1){
    if(D0_mcErrors == 0 or D0_mcErrors == 1 or D0_mcErrors == 2 or D0_mcErrors == 8 or D0_mcErrors == 16 or D0_mcErrors == 64){
      if(D0_K_charge == chargeSelection){
	//h_d0_m_sum->Fill(d0_decay.M(),1.);
	h_d0_m_signal->Fill(d0_decay.M(),1.);
	h_d0_p_signal->Fill(d0_decay.Pt(),1.);
	h_p0_p_signal->Fill(pi0_vect.Mag(),1.);
	value_flag = 1;
	if(noNanVal){signal.Fill(); combined.Fill();}
      }
    }

    if(D0_K_charge == chargeSelection && D0_pi_charge !=chargeSelection) h_d0_m_sum->Fill(d0_decay.M(),1.);
    //if(D0_isSignal!=1 && pi_isSignal != 1 /*or D0_pi0_isSignal != 1 or D0_pi_isSignal != 1 or D0_K_isSignal != 1 or D0_pi0_gamma_0_isSignal != 1 or D0_pi0_gamma_1_isSignal !=1 )*/){
    if(D0_mcErrors == 4 or D0_mcErrors == 20 or D0_mcErrors == 32 or D0_mcErrors == 48 or D0_mcErrors >= 128 or D0_mcErrors >= 256 or D0_mcErrors >= 512 or D0_mcErrors == 1024){
      if(D0_K_charge == chargeSelection){
	h_d0_m_back  ->Fill(d0_decay.M(),1.);
	h_p0_p_back  ->Fill(pi0_vect.Mag(),1.);
	h_d0_p_back  ->Fill( d0_decay.Pt(),1.);
	value_flag = -1;
	if(noNanVal){background.Fill(); combined.Fill();}
      }
    }
    
    //if(noNanVal && D0_K_charge == chargeSelection) combined.Fill();   

    
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

  float lumi = 1.;
  if(nameOfSample == "ccbar")  lumi = 1.329; //e6;
  if(nameOfSample == "charged")lumi = 0.5654;//e6;
  if(nameOfSample == "ddbar")  lumi = 0.401; //e6;
  if(nameOfSample == "mixed")  lumi = 0.5346;//e6;
  if(nameOfSample == "ssbar")  lumi = 0.383; //e6;
  if(nameOfSample == "taupair")lumi = 0.919; //e6;
  if(nameOfSample == "uubar")  lumi = 1.605; //e6;


  if(nameOfSample != "data"){
    h_d0_m ->Scale(lumi);
    h_pi0_m->Scale(lumi);
    // h_d0_m->Scale(1.0/ (h_d0_m->Integral()));
    // h_pi0_m->Scale(1.0/(h_pi0_m->Integral()));
  }

  //h_d0_m_sum->Add(h_d0_m_back);

  newfile->cd();

  deltaM_tree.Write();
  h_d0_m->Write("h_d0_m");
  h_d0_m_p->Write("h_d0_m_p");
  h_kaon_ID->Write("h_kaon_ID");
  h_d0_2D->Write("h_d0_2D");
  h_pi0_m->Write("h_pi0_m");
  h_deltaM->Write("h_deltaM");

  delete h_d0_m;
  delete h_d0_m_p;
  delete h_pi0_m;
  delete h_deltaM;


  //MVA
  h_d0_m_sum->Write("h_d0_m_sum");
  h_d0_m_signal->Write("h_d0_m_signal");
  h_p0_p_signal->Write("h_p0_p_signal");
  h_d0_p_signal->Write("h_d0_p_signal");
  h_d0_m_back  ->Write("h_d0_m_back");
  h_p0_p_back  ->Write("h_p0_p_back");
  h_d0_p_back  ->Write("h_d0_p_back");

  //roofit
  signal.Write();
  background.Write();
  combined.Write();

  //mva 
  delete h_d0_m_signal;
  delete h_p0_p_signal;
  delete h_d0_p_signal;
  delete h_d0_m_back;
  delete h_p0_p_back;
  delete h_d0_p_back;

  for(int i=0; i<sig_pi0.size(); i++) fom_pi0.at(i) = sig_pi0.at(i)/std::sqrt(( sig_pi0.at(i) + bkg_pi0.at(i) ));
  for(int i=0; i<sig_d0.size(); i++)  fom_d0.at(i) = sig_d0.at(i)/std::sqrt(( sig_d0.at(i) + bkg_d0.at(i) ));


  TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,500,300);
  Double_t x[sig_pi0.size()], y[sig_pi0.size()];
  for (Int_t i=0;i<sig_pi0.size();i++) {
    x[i] = cut_pi0.at(i);
    y[i] = fom_pi0.at(i);
  }
  TGraph* gr = new TGraph(sig_pi0.size(),x,y);
  gr->Draw("AC*");
  c1->cd();
  c1->Print("fom_pi0.pdf");
  c1->Clear();

  for (Int_t i=0;i<sig_d0.size();i++) {
    x[i] = cut_d0.at(i);
    y[i] = fom_d0.at(i);
  }
  TGraph* gr1 = new TGraph(sig_d0.size(),x,y);
  gr1->Draw("AC*");
  c1->cd();
  c1->Print("fom_d0.pdf");

  newfile->Close("");
  delete newfile;
}


    // gamma1_px = D0_pi0_gamma_0_px;
    // gamma2_px = D0_pi0_gamma_1_px;

    // gamma1_py = D0_pi0_gamma_0_py;
    // gamma2_py = D0_pi0_gamma_1_py;

    // gamma1_pz = D0_pi0_gamma_0_pz;
    // gamma2_pz = D0_pi0_gamma_1_pz;

    // gamma1_E  = D0_pi0_gamma_0_E;
    // gamma2_E  = D0_pi0_gamma_1_E;

    // gamma1.SetPxPyPzE(gamma1_px,gamma1_py,gamma1_pz,gamma1_E);
    // gamma2.SetPxPyPzE(gamma2_px,gamma2_py,gamma2_pz,gamma2_E);

    // pi0_gammas = gamma1 + gamma2;
