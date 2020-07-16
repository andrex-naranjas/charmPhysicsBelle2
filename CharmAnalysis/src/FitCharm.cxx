//FitCharm includes
#ifndef FITCHARM_CXX
#define FITCHARM_CXX

#include "FitCharm.h"

// #include "RooTFnBinding.h"
// #include "RooTFnPdfBinding.h"
// #include "RooFunctorBinding.h"
//#include "RooCFunction1Binding.h"
//#include "RooFunctor1DBinding.h"

#include "RooCFunction2Binding.h"


#include <ostream>
#include "TCanvas.h"

using namespace RooFit;


FitCharm::FitCharm()
{
}

FitCharm::~FitCharm(){}

void FitCharm::initialize(Config config){

  std::cout<<"Start fit"<<std::endl;
  fdata   = new TFile("/u/user/andres/belle/charm/analysis/CharmAnalysis/Files/total_rs.root");

}


void FitCharm::execute(Config config){
  
  Float_t xmin = 0.14, xmax = 0.16; //Float_t xmin = -10, xmax = 10; //(test)
  RooRealVar x("x","#Delta M [GeV]",xmin,xmax);

  // Import data
  TH1D *hData; //binned data
  hData   = (TH1D*)fdata  ->GetObjectUnchecked("h_deltaM"); //test h_gauss(OK)
  RooDataHist data("data","dataset with x",x,Import(*hData));

  // SIGNAL
  //build first gaussian pdf
  RooRealVar  mean1("mean1","Mean of Gaussian",0.1459,0.14,0.16);
  RooRealVar  sigma1("sigma1","Width of Gaussian",0.0,0,0.001);
  RooGaussian gauss1("gauss1","gauss(x,mean,sigma)",x,mean1,sigma1);

  //build second gaussian pdf
  RooRealVar  mean2("mean2","Mean of Gaussian",0.1459,0.14,0.16);
  RooRealVar  sigma2("sigma2","Width of Gaussian",0.0,0.0,0.001);
  RooGaussian gauss2("gauss2","gauss(x,mean,sigma)",x,mean2,sigma2);

  //gaussian fraction to be used
  RooRealVar f_gauss("f_gauss","gaussian fraction",0.5,0.,1.);

  //gaussian_component(x) = f_gauss*gauss1(x) + (1-f_gauss)*gauss2(x)
  RooAddPdf  sum_gauss("model","model",RooArgList(gauss1,gauss2),f_gauss);

  //build Jhonson Su pdf
  RooRealVar  mu_john("john_mu","mu para",0.1459,0.14,0.16);
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
  RooRealVar nsig("nsig","#signal events",1000,1000,50000);
  RooRealVar nbkg("nbkg","#background events",100,200,5000);
  RooAddPdf total("total","total",RooArgList(signal,back),RooArgList(nsig,nbkg));

  // do the fit
  total.fitTo(data);//, Extended());//, Range(0.143,0.1475));

  //Plotting 
  RooPlot *xframe = x.frame();
  data.plotOn(xframe);
  // sum_gauss.plotOn(xframe, Components(gauss1),LineColor(kCyan));
  // sum_gauss.plotOn(xframe, Components(gauss2),LineColor(kGreen));
  // signal.plotOn(xframe, Components(john),LineColor(kOrange));
  // signal.plotOn(xframe, Components(sum_gauss),LineColor(kMagenta));

  total.plotOn(xframe, Components(signal),LineColor(kGreen),LineStyle(kDashed));
  total.plotOn(xframe, Components(back),LineColor(kBlue),LineStyle(kDashed));
  total.plotOn(xframe, LineColor(kRed));

  TCanvas c;
  //c.SetLogy();
  xframe->Draw();
  c.SaveAs("plot_data.pdf");


  // // Generate a dataset of 1000 events in x from gauss
  // RooDataSet *data = gauss.generate(x, 10000);
  
  // // Make a second plot frame in x and draw both the
  // // data and the p.d.f in the frame
  // RooPlot *xframe2 = x.frame(Title("Gaussian p.d.f. with data"));
  // data->plotOn(xframe2);
  // gauss.plotOn(xframe2);
  
  // // --- Build Gaussian signal PDF ---
  // RooRealVar sigmean("sigmean","B^{#pm} mass",5.28,5.20,5.30) ;
  // RooRealVar sigwidth("sigwidth","B^{#pm} width",0.0027,0.001,1.) ;
  // RooGaussian gauss("gauss","gaussian PDF",mes,sigmean,sigwidth) ;
  
  // // --- Build Argus background PDF ---
 // RooRealVar argpar("argpar","argus shape parameter",-20.0,-100.,-1.) ;
 // RooArgusBG argus("argus","Argus PDF",mes,RooConst(5.291),argpar) ;

 // // // --- Construct signal+background PDF ---
 // RooRealVar nsig("nsig","#signal events",200,0.,10000) ;
 // RooRealVar nbkg("nbkg","#background events",800,0.,10000) ;
 // RooAddPdf sum("sum","g+a",RooArgList(gauss,argus),RooArgList(nsig,nbkg)) ;

 // // // --- Generate a toyMC sample from composite PDF ---
 // RooDataSet *data = sum.generate(mes,2000) ;

 // // // --- Perform extended ML fit of composite PDF to toy data ---
 // sum.fitTo(*data,Extended()) ;

 // // // --- Plot toy data and composite PDF overlaid ---
 // RooPlot* mesframe = mes.frame() ;
 // data->plotOn(mesframe) ;
 // sum.plotOn(mesframe) ;
 // sum.plotOn(mesframe,RooFit::Components(argus),RooFit::LineStyle(kDashed)) ; 
 
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

#endif
