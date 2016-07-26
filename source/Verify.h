//===--- Verify.h - Utilities to ensure expectations are met ---===//
//
// This file is part of the Election Method Mathematics
// Application (EMMA) project.
//
// Copyright (c) 2015 - 2016 Frank D. Martinez and the EMMA project authors
// Licensed under the GNU Affero General Public License, version 3.0.
//
// See the file called "LICENSE" included with this distribution
// for license information.
//
//===----------------------------------------------------------------------===//
//
// A collection of utilities to help ensure expectations are met
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include "Printing.h"

namespace Verify {
  template <class T>
  static void ensure(const bool condition_met,
                     const int error_number,
                     T* callable = nullptr) {
    if (condition_met == false) {
      std::string error_string = std::to_string(error_number);
      Printing::printAsOneLine({"internal error #",
                                error_string});
      if (callable) { (*callable)(); }
      Printing::printAsOneLine({"'EMMA' will shut down now"});
      std::exit(0);
    }
  }
}
