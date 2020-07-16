#include "CharmAnalysis.h"

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

  //Get the cofiguration from configFile.txt
  LoadSettings *settings = new LoadSettings();
  Config config;
  settings->loadConfig(config, argv[1]);

  //do analysis
  // CharmAnalysis c0(config, "signal");   c0.Loop();
  // CharmAnalysis c1(config, "ccbar");    c1.Loop();
  // CharmAnalysis c2(config, "charged");  c2.Loop();
  // CharmAnalysis c4(config, "ddbar");    c4.Loop();
  // CharmAnalysis c5(config, "mixed");    c5.Loop();
  // CharmAnalysis c6(config, "ssbar");    c6.Loop();
  // CharmAnalysis c7(config, "taupair");  c7.Loop();
  // CharmAnalysis c8(config, "uubar");    c8.Loop();
  // CharmAnalysis c9(config, "data");     c9.Loop();

  // PrintPlots *plots = new PrintPlots();
  // plots->initialize(config);
  // plots->setstyle();
  // plots->execute(config);

  FitCharm *fit = new FitCharm();
  fit->initialize(config);
  fit->execute(config);
  fit->finalize();
  

  return 0;
}
