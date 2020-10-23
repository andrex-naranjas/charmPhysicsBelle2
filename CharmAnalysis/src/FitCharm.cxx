//FitCharm includes
#ifndef FITCHARM_CXX
#define FITCHARM_CXX

#include "FitCharm.h"

// #include "RooTFnBinding.h"
// #include "RooTFnPdfBinding.h"
// #include "RooFunctorBinding.h"
#include "RooCFunction2Binding.h"
#include "RooFitResult.h"
#include "RooChi2Var.h"

#include <TStyle.h> 

#include <ostream>
#include "TCanvas.h"

using namespace RooFit;


FitCharm::FitCharm()
{
}

FitCharm::~FitCharm(){}

void FitCharm::initialize(Config config){

  std::cout<<"Start fit"<<std::endl;
  fcontrol_data = new TFile((config.OutputFileDir+"total/data_"+config.Channel+"_Right.root").c_str());
  fsignal_data  = new TFile((config.OutputFileDir+"total/data_"+config.Channel+"_Wrong.root").c_str());

  fcontrol_mc   = new TFile((config.OutputFileDir+"total/total_"+config.Channel+"_rs.root").c_str());
  fsignal_mc    = new TFile((config.OutputFileDir+"total/total_"+config.Channel+"_ws.root").c_str());
}


void FitCharm::execute(Config config){

  std::vector<double> control_chi2, signal_chi2, control_result, signal_result;
  std::vector<std::string> label_dataMC; label_dataMC.push_back("data"); label_dataMC.push_back("MC");
  
  ControlChannel(config, "data"); control_chi2.push_back(chi2_test); control_result.push_back(signal_n);
  SignalChannel(config,  "data");  signal_chi2.push_back(chi2_test);  signal_result.push_back(signal_n);
  ControlChannel(config, "MC");   control_chi2.push_back(chi2_test); control_result.push_back(signal_n);
  SignalChannel(config,  "MC");    signal_chi2.push_back(chi2_test);  signal_result.push_back(signal_n);

  for(int i=0; i<control_chi2.size(); i++)
    std::cout<<control_chi2.at(i)<<"   "<<signal_chi2.at(i)<<"    "<<label_dataMC.at(i)<<"   "<<control_result.at(i)<<"    "<<signal_result.at(i)<<"    "<<signal_result.at(i)/control_result.at(i)<<std::endl;

}

void FitCharm::ControlChannel(Config config, std::string dataMC){

  // Define the fitting variable
  Float_t xmin = 0.14, xmax = 0.16; //Float_t xmin = -10, xmax = 10; //(test)
  RooRealVar x("x","#Delta M [GeV]",xmin,xmax);

  // Import data
  TTree* tree;
  if(dataMC=="MC")         tree = (TTree*) fcontrol_mc  ->Get("deltaM");
  else if(dataMC=="data")  tree = (TTree*) fcontrol_data->Get("deltaM");
  RooDataSet data("data","dataset with x",tree,x);
  // TH1D *hData; //binned data

  // SIGNAL
  //build first gaussian pdf
  RooRealVar  mean1("mean1","Mean of Gaussian",0.1459,0.143,0.147);
  RooRealVar  sigma1("sigma1","Width of Gaussian",0.0,0,0.001);
  RooGaussian gauss1("gauss1","gauss(x,mean,sigma)",x,mean1,sigma1);

  //build second gaussian pdf
  RooRealVar  mean2("mean2","Mean of Gaussian",0.1459,0.143,0.147);//0.14,0.16
  RooRealVar  sigma2("sigma2","Width of Gaussian",0.0,0.0,0.001);
  RooGaussian gauss2("gauss2","gauss(x,mean,sigma)",x,mean2,sigma2);

  //gaussian fraction to be used
  RooRealVar f_gauss("f_gauss","gaussian fraction",0.5,0.,1.);

  //gaussian_component(x) = f_gauss*gauss1(x) + (1-f_gauss)*gauss2(x)
  RooAddPdf  sum_gauss("model","model",RooArgList(gauss1,gauss2),f_gauss);

  //build Jhonson Su pdf
  RooRealVar  mu_john("john_mu","mu para",0.1459,0.143,0.147);//0.14,0.16
  RooRealVar  lambda_john("john_lamda","lambda para",0,0,0.0025);//sigma
  RooRealVar  gamma_john("john_gamma","gamma para",1,1,5);
  RooRealVar  delta_john("john_delta","delta para",0,5,10);
  RooJohnson john("john","model john",x, mu_john,lambda_john,gamma_john,delta_john,0.139570);

  //combine gaussian part and jhonson to form the signal
  //signal fraction to be used
  RooRealVar f_sig("f_signal","signal fraction",0.5,0.,1.);

  //signal component
  RooAddPdf  signal("signal","signal",RooArgList(john,sum_gauss),f_sig);

  //BACKGROUND
  //build polynomial
  RooRealVar alpha("alpha","alpha",0,-50,50);
  RooAbsPdf *bkg = bindPdf("bkg", frac_poly, x, alpha); 
  RooAbsPdf &back = *bkg;//make pointer to reference to make RooAddPdf happy

  // construct signal+background PDF 
  RooRealVar nsig("nsig","#signal events",1000,2000,40000);//1000,120000);
  RooRealVar nbkg("nbkg","#background events",100,1000,5000);//500,5000);
  RooAddPdf total("total","total",RooArgList(signal,back),RooArgList(nsig,nbkg));

  // do the fit
  RooFitResult* r = total.fitTo(data, Save());//, Extended());//, Range(0.143,0.1475));

  //Set parameters to fit signal
  delta_j = delta_john.getValV();
  mu_j    = mu_john.getValV();
  gamma_j = gamma_john.getValV();
  sigma_j = lambda_john.getValV();
  f_john  = f_sig.getValV();
  mu1     = mean1.getValV();
  mu2     = mean2.getValV();
  sig1    = sigma1.getValV();
  sig2    = sigma2.getValV();
  f_gaus  = f_gauss.getValV();
  
  //Final yield
  signal_n= nsig.getValV();

  TH1D *hData; //bin data to do chi2 test
  if(dataMC=="MC")        hData = (TH1D*)fcontrol_mc    ->GetObjectUnchecked("h_deltaM");
  else if(dataMC=="data") hData = (TH1D*)fcontrol_data  ->GetObjectUnchecked("h_deltaM");
  RooDataHist data_bin("data_bin","dataset with x",x,Import(*hData));

  //Plotting 
  RooPlot *xframe = x.frame();
  data_bin.plotOn(xframe, Name("data_binned"));
  // sum_gauss.plotOn(xframe, Components(gauss1),LineColor(kCyan));
  // sum_gauss.plotOn(xframe, Components(gauss2),LineColor(kGreen));
  // signal.plotOn(xframe, Components(john),LineColor(kOrange));
  // signal.plotOn(xframe, Components(sum_gauss),LineColor(kMagenta));

  total.plotOn(xframe, Components(signal),LineColor(kGreen),LineStyle(kDashed), Name("signal"));
  total.plotOn(xframe, Components(back),LineColor(kBlue),LineStyle(kDashed), Name("background"));
  total.plotOn(xframe, LineColor(kRed), Name("finalfit"));

  // chi2/ndf
  chi2_test = xframe->chiSquare("finalfit", "data_binned", 13);

  //Plot
  Plotting(config, dataMC, "rs", xframe);

}


void FitCharm::SignalChannel(Config config, std::string dataMC){

  // Define the fitting variable
  Float_t xmin = 0.14, xmax = 0.16; //Float_t xmin = -10, xmax = 10; //(test)
  RooRealVar x("x","#Delta M [GeV]",xmin,xmax);

  // Import data
  TTree* tree;
  if(dataMC=="MC")         tree = (TTree*) fsignal_mc  ->Get("deltaM");
  else if(dataMC=="data")  tree = (TTree*) fsignal_data->Get("deltaM");
  RooDataSet data("data","dataset with x",tree,x);

  // SIGNAL
  //build first gaussian pdf
  RooRealVar  mean1("mean1","Mean of Gaussian",mu1,0.143,0.147); mean1.setConstant(kTRUE);
  RooRealVar  sigma1("sigma1","Width of Gaussian",sig1,0,0.001); sigma1.setConstant(kTRUE);
  RooGaussian gauss1("gauss1","gauss(x,mean,sigma)",x,mean1,sigma1);

  //build second gaussian pdf
  RooRealVar  mean2("mean2","Mean of Gaussian",mu2,0.143,0.147); mean2.setConstant(kTRUE);
  RooRealVar  sigma2("sigma2","Width of Gaussian",sig2,0.0,0.001); sigma2.setConstant(kTRUE);
  RooGaussian gauss2("gauss2","gauss(x,mean,sigma)",x,mean2,sigma2);

  //gaussian fraction to be used
  RooRealVar f_gauss("f_gauss","gaussian fraction",f_gaus,0.,1.); f_gauss.setConstant(kTRUE);

  //gaussian_component(x) = f_gauss*gauss1(x) + (1-f_gauss)*gauss2(x)
  RooAddPdf  sum_gauss("model","model",RooArgList(gauss1,gauss2),f_gauss);

  //build Jhonson Su pdf
  RooRealVar  mu_john("john_mu","mu para",mu_j,0.143,0.147); mu_john.setConstant(kTRUE);
  RooRealVar  lambda_john("john_lamda","lambda para",sigma_j,0,0.0025);lambda_john.setConstant(kTRUE);
  RooRealVar  gamma_john("john_gamma","gamma para",gamma_j,1,5); gamma_john.setConstant(kTRUE);
  RooRealVar  delta_john("john_delta","delta para",delta_j,5,10); delta_john.setConstant(kTRUE);
  RooJohnson john("john","model john",x, mu_john,lambda_john,gamma_john,delta_john,0.139570);

  //combine gaussian part and jhonson to form the signal
  //signal fraction to be used
  RooRealVar f_sig("f_signal","signal fraction",f_john,0.,1.); f_sig.setConstant(kTRUE);

  //signal component
  RooAddPdf  signal("signal","signal",RooArgList(john,sum_gauss),f_sig);

  //BACKGROUND
  //build polynomial
  RooRealVar alpha("alpha","alpha",0,-50,50);
  RooAbsPdf *bkg = bindPdf("bkg", frac_poly, x, alpha); 
  RooAbsPdf &back = *bkg;//make pointer to reference to make RooAddPdf happy

  // construct signal+background PDF 
  RooRealVar nsig("nsig","#signal events",10,10,100);//10,10,50000);
  RooRealVar nbkg("nbkg","#background events",1000,1000,500000);//1000,100,500000);
  RooAddPdf total("total","total",RooArgList(signal,back),RooArgList(nsig,nbkg));

  // do the fit
  RooFitResult* r = total.fitTo(data, Save());//, Extended());//, Range(0.143,0.1475));

  signal_n= nsig.getValV();

  TH1D *hData; //bin data to do chi2 test
  if(dataMC=="MC")        hData = (TH1D*)fsignal_mc    ->GetObjectUnchecked("h_deltaM");
  else if(dataMC=="data") hData = (TH1D*)fsignal_data  ->GetObjectUnchecked("h_deltaM");
  RooDataHist data_bin("data_bin","dataset with x",x,Import(*hData));

  //Plotting 
  RooPlot *xframe = x.frame();
  data_bin.plotOn(xframe, Name("data_binned"));
  total.plotOn(xframe, Components(signal),LineColor(kGreen),LineStyle(kDashed), Name("signal"));
  total.plotOn(xframe, Components(back),LineColor(kBlue),LineStyle(kDashed), Name("background"));
  total.plotOn(xframe, LineColor(kRed), Name("finalfit"));

  // chi2/ndf
  chi2_test = xframe->chiSquare("finalfit", "data_binned", 3);

  //Plot
  Plotting(config, dataMC, "ws", xframe);

}

double FitCharm::frac_poly(double x, double par){

  double xx =  x;//[0];
  double alpha = par;//[0];
  double x0 =  0.139570;
  double value =  std::pow(xx-x0,0.5) + alpha * (std::pow(xx-x0,1.5));
  return value;
}


void FitCharm::finalize(){

  std::cout<<"End of fitting"<<std::endl;
}

void FitCharm::Plotting(Config config, std::string dataMC, std::string sign, RooPlot *xframe){

  TString lumi; lumi="9.6";

  TString naming="";
  if(dataMC=="data") naming = "Data";
  if(dataMC=="MC")   naming = "MC";

  TCanvas *c = new TCanvas("canvas","canvas",550,500);
  TLegend* leg = new TLegend(0.7,0.825,0.9,0.575,"");
  leg->SetBorderSize(0); leg->SetTextSize(0.0375); leg->SetFillColor(0);
  leg->AddEntry(xframe->findObject("data_binned"),"#bf{#scale[0.85]{"+naming+"}}","PE");
  naming="Signal";    leg->AddEntry(xframe->findObject("signal"),"#bf{#scale[0.85]{"+naming+"}}","L");
  naming="Background";leg->AddEntry(xframe->findObject("background"),"#bf{#scale[0.85]{"+naming+"}}","L");
  naming="Total";     leg->AddEntry(xframe->findObject("finalfit"),"#bf{#scale[0.85]{"+naming+"}}","L");

  TPaveText *box;
  box = new TPaveText(0.7,0.845,0.855,0.96,"NDC");
  box->SetBorderSize(0); box->SetTextSize(0.035); box->SetFillColor(0);
  box->AddText("#bf{#it{#scale[1.125]{Belle II}}} Work in progress");
  box->AddText("#int L="+lumi+"fb^{-1}");
  c->cd();

  //main panel
  TPad *pad = new TPad("pad","pad",0,0,1,1);
  pad->SetTicks(1,1); 
  pad->Draw();
  pad->cd();
  pad->SetLeftMargin(0.1155);
  pad->SetRightMargin(0.03);
  pad->SetTopMargin(0.02);
  pad->SetBottomMargin(0.1);

  xframe->Draw();
  xframe->SetTitle("");

  pad->Update();
  pad->Modified();
  box->Draw();
  leg->Draw();
  c->SetLogy();
  c->cd();
  c->Print(("fit_"+config.Channel+"_"+dataMC+"_"+sign+".pdf").c_str());

}

void FitCharm::setstyle(){

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
