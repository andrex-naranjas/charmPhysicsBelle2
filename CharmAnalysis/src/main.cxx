#include "CharmAnalysis.h"
#include "CharmStrangeAnalysis.h"

#include "ConfigSettings.h"
#include "LoadSettings.h"

#include "PrintPlots.h"
#include "FitCharm.h"

#include <string>
#include <vector>
#include <iostream>


int main(int argc, char** argv){

  if(argc!=2){
    std::cout<<"Please provide a config file, you provided "<<argc-1<<" files/arguments"<<std::endl;
    std::cout<<"Try again. BYE!"<<std::endl;
    return 1;
  }

  std::vector<std::string> samples; samples.push_back("ccbar");// samples.push_back("data");
  // samples.push_back("charged");  samples.push_back("ddbar");
  // samples.push_back("mixed");    samples.push_back("ssbar");
  // samples.push_back("taupair");  samples.push_back("uubar");
  // samples.push_back("3500420000");     samples.push_back("3700001000");

  //Get the cofiguration from configFile.txt
  LoadSettings *settings = new LoadSettings();
  Config config;
  settings->loadConfig(config, argv[1]);


  if(config.DoOnlyPlots=="False"){  //do analysis
    if(config.Channel == "kpi" or config.Channel == "kpipi0")
      for(int iSamples=0; iSamples<samples.size(); iSamples++){
	CharmAnalysis r(config, samples[iSamples]); r.Loop();}

    if(config.Channel == "kkpi" or config.Channel == "kpipi")
      for(int iSamples=0; iSamples<samples.size(); iSamples++){
	CharmStrangeAnalysis r(config, samples[iSamples]); r.Loop();}    
  }


  if(config.PrintPlots=="True"){
    PrintPlots *plots = new PrintPlots();
    plots->initialize(config);
    plots->setstyle();
    plots->execute(config);
  }

  if(config.DoRooFit=="True"){
    FitCharm *fit = new FitCharm();
    fit->initialize(config);
    fit->setstyle();
    fit->execute(config);
    fit->finalize();
  }
  
  return 0;
}
