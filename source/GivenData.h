//===--- GivenData.cpp - "Given Data" Related Typing ---===//
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
// Typing relating to the data given to the application.
// Keeps track of the basic data needed for the application run.
//
//===----------------------------------------------------------------------===//

#ifndef EMMA_GIVENDATA_H
#define EMMA_GIVENDATA_H

#include "RawParsedOptions.h"

#include <ctime>

namespace Emma {
  // Tracks the basic data needed for the application run
  class GivenData  {
    // Number of Candidates per simulated election run
    unsigned number_of_candidates = 3;
    // Number of simulated elections to run
    unsigned number_of_elections = 1;
    // Number of Voters per simulated election run
    unsigned number_of_voters = 64;
    // Seed value for the pseudo-random number generator
    unsigned prng_seed = std::time(nullptr);
  public:
    GivenData();
    GivenData(RawParsedOptions rpo);
    // Returns the number of Candidates per simulated election
    // run
    unsigned numberOfCandidates() const;
    // Returns the number of simulated elections to run
    unsigned numberOfElections() const;
    // Returns the number of Voters per simulated election run
    unsigned numberOfVoters() const;
    // Returns the seed value for the pseudo-random number
    // generator
    unsigned seedForPRNG() const;
  };
}

#endif
