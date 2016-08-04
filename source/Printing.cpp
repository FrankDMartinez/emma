//===--- Printing.h - Print Related Functionality ---===//
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
// Functionality relating to general output.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include "Printing.h"

namespace Printing {
  void print() { }

  void print(std::string the_string) {
    std::cout << the_string;
  }

  void print(const unsigned u) {
    std::cout << u;
  }

  void printAsOneLine(std::vector<std::string> strings) {
    for (auto each : strings) {
      print(each);
    }
    print({"\n"});
  }

  void printLines(std::vector<std::string> strings) {
    for (auto each : strings) {
      printAsOneLine({each});
    }
  }
}
