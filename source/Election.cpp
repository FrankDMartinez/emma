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
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include "Printing.h"
#include "Pseudorandom.h"
#include "Verify.h"

namespace Simulation {
  Election::Election(const unsigned count_of_Voters,
                     const unsigned count_of_Candidates,
                     const double honest_Voters)
    : number_of_Voters(count_of_Voters),
      number_of_Candidates(count_of_Candidates),
      honesty_fraction(honest_Voters) {
    createElectorate();
    setElectorateHonesty();
    determineWeightedUtilities();
    determineUnweightedUtilities();
    determineTrueCondorcetCandidate();
  }

  unsigned Election::ballotSize() const {
    return number_of_Candidates;
  }

  void Election::createElectorate() {
    for (unsigned Voter_number = 0;
         Voter_number < electorateSize();
         Voter_number++) {
        Voter a_Voter(number_of_Candidates);
        the_electorate.push_back(a_Voter);
    }
  }

  void Election::determineUnweightedUtilities() {
    std::vector<Candidate> unweighted_utilities;
    for (unsigned Candidate_identifier = 0;
         ballotSize() > Candidate_identifier;
         Candidate_identifier++) {
      Candidate each =
        sumCandidatesUnweightedUtilities(Candidate_identifier);
      unweighted_utilities.push_back(each);
    }
    _unweighted_societal_utility_values = unweighted_utilities;
  }

  void Election::determineWeightedUtilities() {
    std::vector<Candidate> weighted_utilities;
    for (unsigned Candidate_identifier = 0;
         ballotSize() > Candidate_identifier;
         Candidate_identifier++) {
      Candidate each =
        sumCandidatesWeightedUtilities(Candidate_identifier);
      weighted_utilities.push_back(each);
    }
    _weighted_societal_utility_values = weighted_utilities;
  }

  void Election::determineTrueCondorcetCandidate() {
    sortVoterPreferencesByActualUtilities();
    performOneToOneComparisonsOfCandidates();
    recordTheOneTrueCondorcetCandidate();
  }

  unsigned Election::electorateSize() const {
    return number_of_Voters;
  }

  Voter* Election::getVoter(unsigned index) {
    return &(the_electorate[index]);
  }

  unsigned Election::numberOfStrategicVotersNeeded() const {
    unsigned number_of_honest_Voters =
      (unsigned) std::rint(electorateSize() * honesty_fraction);
    return electorateSize() - number_of_honest_Voters;
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

  void Election::sortVoterPreferencesByActualUtilities() {
    for (unsigned Voter_index = 0;
         electorateSize() > Voter_index;
         Voter_index++) {
      Voter* single_Voter = getVoter(Voter_index);
      single_Voter->sortCandidatesByActualUtility();
    }
  }

  void Election::performOneToOneComparisonsOfCandidates() {
    std::cout << __func__ << " is not yet implemented" << std::endl;
  }

  void Election::recordTheOneTrueCondorcetCandidate() {
    std::cout << __func__ << " is not yet implemented" << std::endl;
  }

  std::vector<unsigned> Election::strategicVoterIndices(const unsigned strategic_count) {
    std::vector<unsigned> indices;
    for (unsigned count = 0; count < electorateSize(); count++) {
      indices.push_back(count);
    }
    std::shuffle(indices.begin(),
                 indices.end(),
                 Pseudorandom::prn_generator);
    return std::vector<unsigned>(indices.begin(), indices.begin() + strategic_count);
  }

  double Election::sumActualUtilitiesOfCandidate(const unsigned identifier) {
    double sum = 0.;
    for (unsigned Voter_index = 0;
         electorateSize() > Voter_index;
         Voter_index++) {
      const Voter* single_Voter = getVoter(Voter_index);
      Candidate the_Candidate =
        single_Voter->getCandidate(identifier);
      sum += the_Candidate.utilities()->actualUtility();
    }
    return sum;
  }

  Candidate Election::sumCandidatesUnweightedUtilities(const unsigned identifier) {
    double actual_sum = 0.;
    double perceived_sum = 0.;
    for (unsigned Voter_index = 0;
         electorateSize() > Voter_index;
         Voter_index++) {
      const Voter* single_Voter = getVoter(Voter_index);
      Candidate the_Candidate =
        single_Voter->getCandidate(identifier);
      actual_sum += the_Candidate.utilities()->actualUtility() * 1;
      perceived_sum += the_Candidate.utilities()->perceivedUtility() *
                         single_Voter->weight();
    }
    Utilities summed_utilities = { actual_sum, perceived_sum };
    return Candidate(identifier, &summed_utilities);
  }

  Candidate Election::sumCandidatesWeightedUtilities(const unsigned identifier) {
    double actual_sum = 0.;
    double perceived_sum = 0.;
    for (unsigned Voter_index = 0;
         electorateSize() > Voter_index;
         Voter_index++) {
      const Voter* single_Voter = getVoter(Voter_index);
      Candidate the_Candidate =
        single_Voter->getCandidate(identifier);
      actual_sum += the_Candidate.utilities()->actualUtility() *
                      single_Voter->weight();
      perceived_sum += the_Candidate.utilities()->perceivedUtility() *
                         single_Voter->weight();
    }
    Utilities summed_utilities = { actual_sum, perceived_sum };
    return Candidate(identifier, &summed_utilities);
  }
}
