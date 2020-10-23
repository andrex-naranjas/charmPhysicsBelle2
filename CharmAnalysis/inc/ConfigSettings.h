//Config Settings
#ifndef CONFIGSETTINGS_H
#define CONFIGSETTINGS_H

#include <vector>
#include <string>

struct Config{

  std::string NormPlots;
  std::string DoOnlyPlots;
  std::string InputFileDir;
  std::string OutputFileDir;
  std::string Channel;
  std::string Sign;
  std::string PrintPlots;
  std::string DoRooFit;
  long int NumberOfEvents;

  std::vector<double> xBinsCw;

  std::string OnlyMC;
  std::string OnlyData;

};

#endif
