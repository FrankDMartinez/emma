//===--- Election.cpp - Information About A Single Election ---===//
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

#include "Election.h"
#include <cfenv>
#include <vector>
#include "Pseudorandom.h"

namespace Simulation {
  Election::Election(const unsigned count_of_Voters,
                     const unsigned count_of_Candidates,
                     const double honest_Voters)
    : number_of_Voters(count_of_Voters),
      number_of_Candidates(count_of_Candidates),
      honesty_fraction(honest_Voters) {
    createElectorate();
    setElectorateHonesty();
  }

  void Election::createElectorate() {
    for (unsigned Voter_number = 0;
         Voter_number < number_of_Voters;
         Voter_number++) {
        Voter a_Voter(number_of_Candidates);
        the_electorate.push_back(a_Voter);
    }
  }

  Voter* Election::getVoter(unsigned index) {
    return &(the_electorate[index]);
  }

  unsigned Election::numberOfStrategicVotersNeeded() const {
    unsigned number_of_honest_Voters =
      (unsigned) std::rint(number_of_Voters * honesty_fraction);
    return number_of_Voters - number_of_honest_Voters;
  }

  void Election::setElectorateHonesty() {
    const unsigned number_of_strategic_Voters =
      numberOfStrategicVotersNeeded();
    const std::vector<unsigned> strategic_Voter_indicies =
      strategicVoterIndices(number_of_strategic_Voters);
    for (auto each : strategic_Voter_indicies) {
      getVoter(each)->makeStrategic();
    }
  }

  std::vector<unsigned> Election::strategicVoterIndices(const unsigned strategic_count) {
    std::vector<unsigned> indices;
    for (unsigned count = 0; count < number_of_Voters; count++) {
      indices.push_back(count);
    }
    std::shuffle(indices.begin(),
                 indices.end(),
                 Pseudorandom::prn_generator);
    return std::vector<unsigned>(indices.begin(), indices.begin() + strategic_count);
  }
}
