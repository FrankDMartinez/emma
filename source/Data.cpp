//===--- Data.cpp - Serialized and Generated Data Utilities ---===//
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
// Functionality related to generated and serialized data.
// Used for testing generation/comparison and for general
// election simulation.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include "Data.h"

namespace Data {
  namespace Serialized {
    void compareGeneratedData() {
      std::cout << "compare generated data with serialized data if required, reporting any difference" << std::endl;
    }
    void load(const Emma::RunState* state) {
      std::cout << "load serialized data if required" << std::endl;
    }
    void unload() {
      std::cout << "serialize data if required" << std::endl;
    }
  }
  namespace Generated {
    void generate() {
      std::cout << "generate data" << std::endl;
    }
  }
}
