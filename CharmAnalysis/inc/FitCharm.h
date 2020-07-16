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

 private:

  static double frac_poly(double x, double par);
  //static double frac_poly(double *x, double *par);
  TFile *fdata, *fsignal, *fccbar, *fcharged, *fddbar;

};

#endif


