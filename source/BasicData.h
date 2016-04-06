//===--- BasicData.h - "Basic Data" Related Typing ---===//
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
// Typing relating to the "basic data" of the application.
// Keeps track of the basic data needed for the application run.
//
//===----------------------------------------------------------------------===//

#include <ctime>

namespace Emma {
  // Tracks the basic data needed for the application run
  class BasicData  {
    unsigned number_of_elections = 1;
    unsigned number_of_candidates = 3;
    unsigned number_of_voters = 64;
    unsigned prng_seed = std::time(nullptr);
  public:
    BasicData(unsigned elections, unsigned candidates,
              unsigned voters, unsigned seed) :
              number_of_elections(elections),
              number_of_candidates(candidates),
              number_of_voters(voters),
              prng_seed(seed) {}
  }
}
