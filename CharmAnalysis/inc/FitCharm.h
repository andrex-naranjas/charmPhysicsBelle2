//FitCharm includes
#ifndef FITCHARM_H
#define FITCHARM_H

#include "ConfigSettings.h"

//RooFit includes
#include "RooFit.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooPolyVar.h"
#include "RooProdPdf.h"
#include "RooPlot.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH1.h"

#include "RooAddPdf.h"
#include "RooArgusBG.h"
#include "RooArgList.h"
#include "RooAbsReal.h"
#include "RooJohnson.h"

#include <TMath.h>
#include <TF1.h>
#include <TStyle.h>
#include <TFile.h>

#include "TPad.h"
#include <TROOT.h>
#include "TLine.h"
#include "TLegend.h"
#include "TString.h"
#include "TPaveText.h"

#include <string>
#include <vector>


class FitCharm{

 public:
  FitCharm();
  virtual ~FitCharm();

  virtual void initialize(Config config);
  virtual void execute(Config config);
  virtual void finalize();
  virtual void setstyle();

 private:

  void ControlChannel(Config config, std::string dataMC);
  void SignalChannel(Config config, std::string dataMC);
  void Plotting(Config config, std::string dataMC, std::string sign, RooPlot *xframe);

  static double frac_poly(double x, double par);
  //static double frac_poly(double *x, double *par);
  TFile *fsignal_data, *fcontrol_data, *fsignal_mc, *fcontrol_mc;
  double delta_j=0., mu_j=0., gamma_j=0., sigma_j=0., f_john=0.;
  double mu1=0., mu2=0, sig1=0., sig2=0., f_gaus=0.;
  double chi2_test=0;
  double signal_n=0;
      
      


};

#endif


