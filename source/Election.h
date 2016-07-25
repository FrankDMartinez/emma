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

    // Returns the number of Candidates
    unsigned ballotSize() const;

    // Creates the collection of Voters, initializing Their
    // relationship with the Candidates in terms of utility
    // values
    void createElectorate();

    // Identifies and records the identifier of the Candidate
    // with the optimum societal utility
    void determineOptimumCandidate();

    // Returns the number of Voters
    unsigned electorateSize() const;

    // Returns the number of Voters voting "strategically" in
    // this election
    unsigned numberOfStrategicVotersNeeded() const;

    // the Candidate which has the highest summed actual utility
    // across Voters
    unsigned societally_optimum_Candidate;

    // Choose Voters at random and sets Their voting nature
    // until the fraction of Voters voting "honestly" instead of
    // "strategically" most closely approximates the
    // `honesty_fraction`
    void setElectorateHonesty();

    // Records the Candidate indicated by the given identifier
    // as the Candidate which has the highest summed actual
    // utility across Voters
    void setSocietallyOptimumCandidate(const unsigned identifier);

    // Returns the indices Voters voting "strategically" as
    // opposed to "honestly"; the value passed is in the number
    // of indices to return, selected at random
    std::vector<unsigned> strategicVoterIndices(const unsigned);

    // Returns the sum of the actual utilities of the Candidate
    // designated by the given identifier to the Voters in this
    // election
    double sumActualUtilitiesOfCandidate(const unsigned identifier);
  public:
    Election(const unsigned count_of_Voters,
             const unsigned count_of_Candidates,
             const double honest_Voters);

    // Returns a pointer to the requested Voter
    Voter* getVoter(const unsigned index);
  };
}
