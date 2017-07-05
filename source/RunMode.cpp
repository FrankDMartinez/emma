//===--- RunMode.cpp - "Running Mode" Related Typing ---===//
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
// Typing relating to the "running mode" of the application.
// Keeps track of the state of the different modes in which the
// application can run.
//
//===----------------------------------------------------------------------===//

#include "RunMode.h"

#include "TranslateOption.h"

#include <iostream>

namespace Emma {
  RunMode::RunMode() {}
  RunMode::RunMode(RawParsedOptions rpo) {
    testing = translateOption(rpo, "--test", testing);
    verbose = translateOption(rpo, "--verbose", verbose);
    if (verbose == true) {
      std::cout << "parsing mode options: success" << std::endl;
    }
  }
  bool RunMode::isTesting() const { return testing; }
  bool RunMode::beVerbose() const { return verbose; }
}
