//Plotting Class includes
#ifndef PRINTPLOTS_CXX
#define PRINTPLOTS_CXX

#include "PrintPlots.h"

#include <cmath>
#include <iostream>
#include <vector>
#include <string>


PrintPlots::PrintPlots()
{
}

PrintPlots::~PrintPlots(){}

void PrintPlots::initialize(Config config)
{

  fdata     = new TFile("/u/user/andres/belle/charm/analysis/ControlPlots/CharmAnalysis/data.root");

  // fsignal   = new TFile("/u/user/andres/belle/charm/scripts/ControlPlots/CharmAnalysis/ccbar.root");
  // fccbar    = new TFile("/u/user/andres/belle/charm/scripts/ControlPlots/CharmAnalysis/ccbar.root");

  // fcharged  = new TFile("/u/user/andres/belle/charm/scripts/ControlPlots/CharmAnalysis/charged.root");
  // fddbar    = new TFile("/u/user/andres/belle/charm/scripts/ControlPlots/CharmAnalysis/ddbar.root");
  // fmixed    = new TFile("/u/user/andres/belle/charm/scripts/ControlPlots/CharmAnalysis/mixed.root");
  // fssbar    = new TFile("/u/user/andres/belle/charm/scripts/ControlPlots/CharmAnalysis/ssbar.root");
  // ftaupair  = new TFile("/u/user/andres/belle/charm/scripts/ControlPlots/CharmAnalysis/taupair.root");
  // fuubar    = new TFile("/u/user/andres/belle/charm/scripts/ControlPlots/CharmAnalysis/uubar.root");

  return;
}

void PrintPlots::execute(Config config){

  std::vector<std::string> kine, nplots;
  kine.push_back("d0_m");
  kine.push_back("deltaM");

  // kine.push_back("pi0_m");
  // kine.push_back("d0_q");

  nplots.push_back("dataMC"); nplots.push_back("MC");
  
  for(int j=0; j<kine.size();j++)
    WStackPlot(config,kine[j],"calib");
       			     
  return;
}

void PrintPlots::WStackPlot(Config config, std::string kine, std::string option)
{
  TH1D *hSignal, *hCcbar, *hCharged, *hDdbar, *hMixed, *hSsbar, *hTaupair, *hUubar;
  TH1D *hData, *sum;

  // hSignal   = (TH1D*)fsignal  ->GetObjectUnchecked(("h_"+kine).c_str());
  // hCcbar    = (TH1D*)fccbar   ->GetObjectUnchecked(("h_"+kine).c_str());
  hData     = (TH1D*)fdata    ->GetObjectUnchecked(("h_"+kine).c_str());//->Clone("hData");  
  // sum       = (TH1D*)hSignal  ->Clone("sum");  
  // hCharged  = (TH1D*)fcharged ->GetObjectUnchecked(("h_"+kine).c_str());
  // hDdbar    = (TH1D*)fddbar   ->GetObjectUnchecked(("h_"+kine).c_str());
  // hMixed    = (TH1D*)fmixed   ->GetObjectUnchecked(("h_"+kine).c_str());
  // hSsbar    = (TH1D*)fssbar   ->GetObjectUnchecked(("h_"+kine).c_str());
  // hTaupair  = (TH1D*)ftaupair ->GetObjectUnchecked(("h_"+kine).c_str());
  // hUubar    = (TH1D*)fuubar   ->GetObjectUnchecked(("h_"+kine).c_str());

  std::string xlabel,ylabel,ratiolabel; double xlow=0., xhigh=0., yhigh=0.;
  bool yRange=false;
  TString leglabel;
  
  //hCcbar->Scale(0.);

  if(config.NormPlots=="True"){
    hData    ->Scale(1./hData   ->Integral());
    hSignal  ->Scale(1./hSignal ->Integral());
    hCcbar   ->Scale(1./hCcbar  ->Integral());
    sum      ->Scale(1./sum     ->Integral());
    hCharged ->Scale(1./hCharged->Integral());
    hDdbar   ->Scale(1./hDdbar  ->Integral());
    hMixed   ->Scale(1./hMixed  ->Integral());
    hSsbar   ->Scale(1./hSsbar  ->Integral());
    hTaupair ->Scale(1./hTaupair->Integral());
    hUubar   ->Scale(1./hUubar  ->Integral());
    ylabel="A.U.";
  }else
    ylabel="Events";

  if(kine=="d0_m") {xlabel="M(K#pi#pi^{0}) [GeV]"; xlow=1.8, xhigh=1.95;}
  if(kine=="deltaM") {xlabel="#DeltaM [GeV]"; xlow=0.14; xhigh=0.16;}
  if(kine=="pi0_m"){xlabel="M(#pi^{0}) [GeV]"; xlow=0.11; xhigh=0.15;}
  if(kine=="d0_q") {xlabel="Q [GeV]"; xlow=0.; xhigh=12;}

  plotAxisLine(hData,kBlue+2,kBlue+2,8,0.5,"",xlabel.c_str(),ylabel.c_str(),true,xlow,xhigh,false,0.,yhigh);
  hData ->SetFillColor(kWhite);

  // plotAxisLine(hSignal,kBlack,kBlack,34,0.5,"",xlabel.c_str(),ylabel.c_str(),true,xlow,xhigh,false,0.,yhigh);
  // hSignal->SetFillColor(kWhite);
  // plotAxisLine(hCcbar,kBlack,kBlack,34,0.5,"",xlabel.c_str(),ylabel.c_str(),true,xlow,xhigh,false,0.,yhigh);
  // hCcbar->SetFillColor(kAzure);
  // plotAxisLine(hCharged,kBlack,kBlack,23,0.5,"",xlabel.c_str(),ylabel.c_str(),true,xlow,xhigh,false,0.,yhigh);
  // hCharged->SetFillColor(kOrange+1);

  // plotAxisLine(hDdbar,kBlack,kBlack,23,0.5,"",xlabel.c_str(),ylabel.c_str(),true,xlow,xhigh,false,0.,yhigh);
  // hDdbar->SetFillColor(kGreen+2);
  // plotAxisLine(hMixed,kBlack,kBlack,23,0.5,"",xlabel.c_str(),ylabel.c_str(),true,xlow,xhigh,false,0.,yhigh);
  // hMixed->SetFillColor(kMagenta+2);
  // plotAxisLine(hSsbar,kBlack,kBlack,23,0.5,"",xlabel.c_str(),ylabel.c_str(),true,xlow,xhigh,false,0.,yhigh);
  // hSsbar->SetFillColor(kYellow+2);
  // plotAxisLine(hTaupair,kBlack,kBlack,23,0.5,"",xlabel.c_str(),ylabel.c_str(),true,xlow,xhigh,false,0.,yhigh);
  // hTaupair->SetFillColor(kCyan+2);
  // plotAxisLine(hUubar,kBlack,kBlack,23,0.5,"",xlabel.c_str(),ylabel.c_str(),true,xlow,xhigh,false,0.,yhigh);
  // hUubar->SetFillColor(kRed+2);

  // THStack *hs = new THStack("hs","");
  // //hs ->Add(hCcbar);
  // hs ->Add(hCharged);
  // hs ->Add(hDdbar); 
  // hs ->Add(hMixed); 
  // hs ->Add(hSsbar);
  // hs ->Add(hTaupair); 
  // hs ->Add(hUubar);
  // hs ->Add(hSignal);

  // sum->Add(hSignal); /*sum->Add(hCcbar);*/ sum->Add(hCharged); sum->Add(hDdbar);
  // sum->Add(hMixed); sum->Add(hSsbar); sum->Add(hTaupair); sum->Add(hUubar);

  leglabel="MC ";
  leglabel="MC W#rightarrow#mu#nu";

  ratiolabel="Data/MC"; 

  TString lumi;
  lumi="9.6";

  TCanvas *c = new TCanvas("canvas","canvas",550,550);
  TLegend* leg = new TLegend(0.7,0.825,0.9,0.575,"");
  leg->SetBorderSize(0); leg->SetTextSize(0.0375); leg->SetFillColor(0);
  TString naming="";

  leg->AddEntry(hData,    "#bf{#scale[0.85]{Data  "+naming+"}}","L");//P for data (points)
  // leg->AddEntry(hSignal,  "#bf{#scale[0.85]{signal  "+naming+"}}","f");//P for data (points)
  // //leg->AddEntry(hCcbar,   "#bf{#scale[0.85]{c#bar{c}   "+naming+"}}","f");//P for data (points)
  // leg->AddEntry(hCharged, "#bf{#scale[0.85]{charged "+naming+"}}","f");//P for data (points)
  // leg->AddEntry(hDdbar,   "#bf{#scale[0.85]{d#bar{d}   "+naming+"}}","f");//P for data (points)
  // leg->AddEntry(hMixed,   "#bf{#scale[0.85]{mixed   "+naming+"}}","f");//P for data (points)
  // leg->AddEntry(hSsbar,   "#bf{#scale[0.85]{s#bar{s}   "+naming+"}}","f");//P for data (points)
  // leg->AddEntry(hTaupair, "#bf{#scale[0.85]{taupair "+naming+"}}","f");//P for data (points)
  // leg->AddEntry(hUubar,   "#bf{#scale[0.85]{u#bar{u}   "+naming+"}}","f");//P for data (points)

  TPaveText *box;
  box = new TPaveText(0.7,0.845,0.855,0.96,"NDC");
  box->SetBorderSize(0); box->SetTextSize(0.035); box->SetFillColor(0);
  box->AddText("#bf{#it{#scale[1.125]{Belle II}}} Work in progress");
  box->AddText("L="+lumi+"fb^{-1}");
  c->cd();

  //main panel
  //TPad *pad = new TPad("pad","pad",0,0.15,1,1);
  TPad *pad = new TPad("pad","pad",0,0,1,1);
  pad->SetTicks(1,1); 
  pad->Draw();
  pad->cd();
  pad->SetLeftMargin(0.1125);
  pad->SetRightMargin(0.03);
  pad->SetTopMargin(0.035);


  hData->SetTitle("");
  hData->GetXaxis()->SetTitleOffset(1.45);
  // sum->Draw();
  // hs->Draw("hist");
  // hs->Draw("hist SAME");
  hData->SetLineWidth(2);
  hData->Draw("hist");
  //hData->Draw("pe X0 SAME");



  // hs->GetXaxis()->SetTitle(xlabel.c_str());
  // hs->GetYaxis()->SetTitle(ylabel.c_str());
  // hs->GetYaxis()->SetTitleOffset(1.55);

  // if(kine=="d0_m")hs->GetXaxis()->SetLimits(xlow,xhigh);
  // hs->Draw("hist");
  // hs->GetYaxis()->SetLimits(0.,yhigh);

  pad->Update();
  pad->Modified();
  box->Draw();
  leg->Draw();
  c->cd();

  //ratio panel
  // TPad *padr = new TPad("padr","padr",0,0.0,1,0.2);
  // padr->SetTopMargin(0);
  // padr->SetBottomMargin(0.2);
  // padr->SetLeftMargin(0.1125);
  // padr->SetRightMargin(0.03);
  // padr->SetGridy();
  // padr->Draw();
  // padr->cd();

  // unsigned int nx = hData->GetXaxis()->GetNbins();
  // Double_t*  xbins = new Double_t[hData->GetXaxis()->GetNbins()+1];
  // for(unsigned int i=0; i< hData->GetXaxis()->GetNbins()+1; i++)  xbins[i]=hData->GetXaxis()->GetBinLowEdge(i+1);
  // xbins[hData->GetXaxis()->GetNbins()]=hData->GetXaxis()->GetBinUpEdge(hData->GetXaxis()->GetNbins());

  // TH1D* ratiodataMC = new TH1D("ratiodataMC","",nx,xbins);

  // for(int b=1; b< (2+(ratiodataMC->GetNbinsX())); b++){

  //   double data=hData->GetBinContent(b);
  //   double mc=sum->GetBinContent(b);
  //   if(mc==0) continue;

  //   double dataratio=data/mc;
  //   double err=hData->GetBinError(b)/mc;

  //   ratiodataMC->SetBinContent(b,dataratio);
  //   ratiodataMC->SetBinError(b,err);
  // }

  // ratioSettings(ratiodataMC,0.95,1.05,"",ratiolabel.c_str(),0.1125,0.1125,0.35,0.15,34,kBlack,0.5,10);
  // ratiodataMC->DrawCopy("");

  // TLine *line;
  // line = new TLine(xlow,1.,xhigh,1.);
  // //line = new TLine(40000.,1.,150000.,1.);//remove
  // line->SetLineColor(kRed+2);
  // line->SetLineStyle(1);
  // line->SetLineWidth(2);
  // line->Draw();
  // padr->Update();  

  // c->cd();
  std::string boson;
  boson="wplus";

  c->Print(("./plots/stack_"+boson+"_"+kine+".pdf").c_str());
  
  //  delete hData; delete hWmunu; delete hWtaunu; delete hZmumu; delete hZtautau; delete hTtbar; delete sum;
  //  delete hs;
  return;
}


void PrintPlots::plotAxisLine(TH1D* hist, int lineColor, int markerColor,
			      int markerStyle, double markerSize,
			      TString title, TString xlabel, TString ylabel, bool xRange,
			      double xlow, double xhigh, bool yRange, double ylow, double yhigh)
{
  hist->SetLineColor(lineColor);
  hist->SetMarkerStyle(markerStyle);
  hist->SetMarkerColor(markerColor);
  hist->SetMarkerSize(markerSize);
  hist->SetTitle(title);
  hist->GetXaxis()->SetTitle(xlabel);
  hist->GetYaxis()->SetTitle(ylabel);
  std::cout<<ylow<<"    "<<yhigh<<std::endl;
  hist->GetXaxis()->SetRangeUser(xlow,xhigh);
  if(xRange==true)
    hist->GetXaxis()->SetRangeUser(xlow,xhigh);
  if(yRange==true)
    hist->GetYaxis()->SetRangeUser(ylow,yhigh);

  return;
}


void PrintPlots::ratioSettings(TH1D* hist, double min, double max, TString xlabel, TString ylabel,
			       double xlabelsize, double ylabelsize, double ytitleof, double ytitlesize,
			       int markerstyle, int color, double markersize, int divisions)
{
  hist->SetMinimum(min);
  hist->SetMaximum(max);
  hist->GetXaxis()->SetTitle(xlabel);

  hist->GetYaxis()->SetTitle(ylabel);
  hist->GetXaxis()->SetLabelSize(xlabelsize);
  hist->GetYaxis()->SetLabelSize(ylabelsize);
  hist->GetYaxis()->SetTitleOffset(ytitleof);
  hist->GetYaxis()->SetTitleSize(ytitlesize);
  hist->SetLineColor(color);

  hist->Sumw2();
  hist->SetMarkerStyle(markerstyle);
  hist->SetMarkerSize(markersize);
  hist->SetMarkerColor(color);

  hist->SetStats(0);
  hist->GetYaxis()->SetNdivisions(divisions);

  return;
}


void PrintPlots::setstyle(){

  gROOT->SetStyle("Plain");
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetOptStat(000000);
  gStyle->SetOptTitle(000000);
  gStyle->SetLabelSize(0.03,"x");
  gStyle->SetLabelSize(0.03,"y");
  gStyle->SetLabelOffset(0.01,"x");
  gStyle->SetLabelOffset(0.01,"y");
  gStyle->SetLabelFont(22,"x");
  gStyle->SetLabelFont(22,"y");

  gStyle->SetTitleSize(0.035,"x");
  gStyle->SetTitleSize(0.035,"y");
  gStyle->SetTitleOffset(1.35,"x");
  gStyle->SetTitleOffset(1.35,"y");

  gStyle->SetPadBottomMargin(0.2);
  gStyle->SetPadRightMargin(0.1);
  gStyle->SetPadTopMargin(0.05);
  gStyle->SetPadLeftMargin(0.18);

  int font = 42;
  gStyle->SetTextFont(font);

  gStyle->SetLabelFont(font,"x");
  gStyle->SetTitleFont(font,"x");
  gStyle->SetLabelFont(font,"y");
  gStyle->SetTitleFont(font,"y");
  gStyle->SetLabelFont(font,"z");
  gStyle->SetTitleFont(font,"z");

  return;
}

#endif
