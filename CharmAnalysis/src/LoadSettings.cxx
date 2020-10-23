//Simple class to parse arguments from config file
#ifndef LOADSETTINGS_CXX
#define LOADSETTINGS_CXX

#include "LoadSettings.h"
#include "ConfigSettings.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


LoadSettings::LoadSettings()
{
}

LoadSettings::~LoadSettings(){}

void LoadSettings::loadConfig(Config& config, std::string fileName){

  std::ifstream fin(fileName);
  std::string line;
  while (getline(fin,line)) {
    std::istringstream sin(line.substr(line.find("=") + 1));
    if (line.find("NormPlots") != -1)
       sin >> config.NormPlots;
    else if (line.find("DoOnlyPlots") != -1)
       sin >> config.DoOnlyPlots;
    else if (line.find("InputFileDir") != -1)
       sin >> config.InputFileDir;
    else if (line.find("OutputFileDir") != -1)
       sin >> config.OutputFileDir;
    else if (line.find("Channel") != -1)
       sin >> config.Channel;
    else if (line.find("Channel") != -1)
       sin >> config.Channel;
    else if (line.find("Sign") != -1)
       sin >> config.Sign;
    else if (line.find("PrintPlots") != -1)
       sin >> config.PrintPlots;
    else if (line.find("DoRooFit") != -1)
       sin >> config.DoRooFit;
    else if (line.find("NumberOfEvents") != -1)
       sin >> config.NumberOfEvents;
    else if (line.find("xBinsCw") != -1){
      double number;
      while(sin >> number)
	config.xBinsCw.push_back(number);
    }
    else if (line.find("OnlyMC") != -1)
       sin >> config.OnlyMC;
    else if (line.find("OnlyData") != -1)
       sin >> config.OnlyData;
  }//firstwhile
}//loadConfig

#endif
