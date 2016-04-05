//===--- RequestedInformation.cpp - Requested Information Utilities ---===//
//
// This file is part of the Election Method Mathematics Application (EMMA) project.
//
// Copyright (c) 2015 - 2016 Frank D. Martinez and the EMMA project authors
// Licensed under the GNU Affero General Public License, version 3.0.
//
// See the file called "LICENSE" included with this distribution for license information.
//
//===----------------------------------------------------------------------===//
//
// Functionality related to determining requested information.
// Analyzes information passed to the application and determines
// how the application should act.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include "RequestedInformation.h"

namespace RequestedInformation {
  // Parses given options; `argc` and `argv` are the arguments
  // from `main()`.
  void parseOptions(int argc, char **argv);
  void displayUsageInformation();
  void determineMode();
  void determineStatisticsToCollect();

  void determine(int argc, char **argv) {
    std::cout << "determine what is requested from simulations" << std::endl;
    parseOptions(argc, argv);
    displayUsageInformation();
    determineMode();
    determineStatisticsToCollect();
  }

  void determineMode() {
    std::cout << "\tdetermine the mode to run in based on such parsing" << std::endl;
  }

  void determineStatisticsToCollect() {
    std::cout << "\tdetermine what statistics to collect based on such parsing" << std::endl;
  }

  void displayUsageInformation() {
    std::cout << "\tdisplay usage information and exit, if required" << std::endl;
  }

  void parseOptions(int argc, char **argv) {
    std::cout << "\tparse given options" << std::endl;
  }
}
