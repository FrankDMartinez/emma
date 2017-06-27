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
#include "RunState.h"

namespace Data {
  namespace Serialized {
    // Compares data generated by the application with
    // serialized data
    void compareGeneratedData();
    // Loads serialized data into memory, if required by the
    // given `RunState`
    void load(const Emma::RunState*);
    // Serializes (unloads) data in memory
    void unload();
  }
  namespace Generated {
    using Scenarios = std::vector<Simulation::Election>;

    // Generates election data
    Scenarios generate(const Emma::RunState*);
  }
}

#endif
