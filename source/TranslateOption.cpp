//===--- TranslateOption.cpp - "Translating Raw Options" Related Functionality ---===//
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
// Functionality relating to translating raw options.
// Translates the raw options given to the application.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include "TranslateOption.h"

namespace Emma {
  unsigned translateOption(RawParsedOptions rpo, const std::string option, unsigned default_value) {
    unsigned value;
    if (rpo[option].isLong()) {
      value = rpo[option].asLong();
    } else {
      value = default_value;
    }
    if (rpo["--verbose"].asLong() == 1) {
      std::cout << "translating option " << option << ": success" << std::endl;
    }
    return value;
  }
}
