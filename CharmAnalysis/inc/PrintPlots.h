//PrintPlots includes
#ifndef PRINTPLOTS_H
#define PRINTPLOTS_H

#include "ConfigSettings.h"

#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TStyle.h>
#include <TFile.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <THStack.h>

#include <string>
#include <vector>

#include "TCanvas.h"
#include "TPad.h"
#include <TStyle.h>
#include <TROOT.h>
#include "TLine.h"
#include "TLegend.h"
#include "TString.h"
#include "TPaveText.h"

#include <string>
#include <vector>


class PrintPlots{

 public:
  PrintPlots();
  virtual ~PrintPlots();

  virtual void  initialize(Config config);
  virtual void  execute(Config config);
  virtual void  setstyle();

 private:

  TFile *fdata, *fsignal, *fccbar, *fcharged, *fddbar;
  TFile *fmixed, *fssbar, *ftaupair, *fuubar;

  TFile *wzdata, *wzmcor, *wzmc, *wzmccal, *wzmcfull;
  TFile *wtaunu, *zmumu, *ztautau, *ttbar;
  TFile *pwtaunu, *pzmumu, *pztautau, *pttbar;

  virtual void WStackPlot(Config config, std::string kine, std::string option);
  
  virtual void plotAxisLine(TH1D* hist, int lineColor, int markerColor,
			    int markerStyle, double markerSize,
			    TString title, TString xlabel, TString ylabel, bool xRange,
			    double xlow, double xhigh, bool yRange, double ylow, double yhigh);

  virtual void ratioSettings(TH1D* hist, double min, double max, TString xlabel, TString ylabel,
			     double xlabelsize, double ylabelsize, double ytitleof, double ytitlesize,
			     int markerstyle, int color, double markersize, int divisions);
};

#endif //> !PRINTPLOTS_H
