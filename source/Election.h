//===--- Election.h - Information About A Single Election ---===//
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
// A collection of information about a particular election, such
// as Voters and Candidates
//
//===----------------------------------------------------------------------===//

#include <vector>
#include "Voter.h"

namespace Simulation {
  class Election {
    // The Voters
    std::vector<Voter> the_electorate;

    // The number of Voters
    unsigned number_of_Voters;

    // The number of Candidates
    unsigned number_of_Candidates;

    // The probability a Voter is an "honest" Voter and not a
    // "strategic" Voter
    double honesty_fraction = 1.0;
  public:
    Election(const unsigned count_of_Voters,
             const unsigned count_of_Candidates,
             const double honest_Voters);

    // Returns a pointer to the requested Voter
    Voter* getVoter(const unsigned index);
  };
}