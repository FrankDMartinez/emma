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

    // Identifies and records the Candidate, when compared with
    // every other Candidate, having greater actual utility for
    // more Voters
    void determineTrueCondorcetCandidate();

    // Returns the number of Voters
    unsigned electorateSize() const;

    // Returns the number of Voters voting "strategically" in
    // this election
    unsigned numberOfStrategicVotersNeeded() const;

    // the utility values of Each Candidate, weighted by Each
    // Voter's relative voting weights
    std::vector<Candidate> _weighted_societal_utility_values;

    // the utility values of Each Candidate, calculated without
    // regard to weighting by Each Voter's relative voting
    // weight
    std::vector<Candidate> _unweighted_societal_utility_values;

    // calculates the utility values of Each Candidate without
    // regard to weighting by Each Voter's relative voting
    // weights
    void determineUnweightedUtilities();

    // calculates the utility values of Each Candidate, weighted
    // by Each Voter's relative voting weights
    void determineWeightedUtilities();

    // calculates the sum of the utility values (without regard
    // to weighting by Each Voter's relative voting weights) of
    // the indicated Candidate and returns that information
    // combined with the given Candidate identifier
    Candidate sumCandidatesUnweightedUtilities(const unsigned);

    // calculates the sum of the utility values (as weighted by
    // Each Voter's relative voting weight) of the indicated
    // Candidate and returns that information combined with the
    // given Candidate identifier
    Candidate sumCandidatesWeightedUtilities(const unsigned);

    // Choose Voters at random and sets Their voting nature
    // until the fraction of Voters voting "honestly" instead of
    // "strategically" most closely approximates the
    // `honesty_fraction`
    void setElectorateHonesty();

    // For Each Voter, sorts the Candidates in accordance with
    // Their actual utilities to the Voter
    void sortVoterPreferencesByActualUtilities();

    // For each Candidate, performs a 1-on-1 comparison to
    // determine which Candidate in each such comparison is
    // ranked as prefered by more Voters; ties are broken by
    // randomly selecting from the 2 Candidates in such
    // situations
    void performOneToOneComparisonsOfCandidates();

    // Records the True Condorcet Candidate, if any, noting
    // whether or not there is such a Candidate
    void recordTheOneTrueCondorcetCandidate();

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
