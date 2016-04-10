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

#include "GivenData.h"

namespace Emma {
  GivenData::GivenData() {}
  GivenData::GivenData(unsigned candidates, unsigned elections,
                       unsigned voters, unsigned seed) :
                       number_of_candidates(candidates),
                       number_of_elections(elections),
                       number_of_voters(voters),
                       prng_seed(seed) {}
  unsigned GivenData::numberOfCandidates() const {
    return number_of_candidates;
  }
  unsigned GivenData::numberOfElections() const {
    return number_of_elections;
  }
  unsigned GivenData::numberOfVoters() const {
    return number_of_voters;
  }
  unsigned GivenData::seedForPRNG() const {
    return prng_seed;
  }
}
