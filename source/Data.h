//===--- Data.h - Serialized and Generated Data Functionality ---===//
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

#ifndef EMMA_DATA_H
#define EMMA_DATA_H

#include <vector>
#include "Election.h"

namespace Emma {
  class RunState;
}

namespace Data {
  using Scenarios = std::vector<Simulation::Election>;

  // Generates election data
  Scenarios generate(const Emma::RunState*);
}

#endif
