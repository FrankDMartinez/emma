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
#include "Logging.h"
#include "Printing.h"
#include "Pseudorandom.h"
#include "Verify.h"

namespace Simulation {
  Election::Election(const unsigned count_of_Voters,
                     const unsigned count_of_Candidates,
                     const double honest_Voters,
                     const bool be_verbose)
    : number_of_Voters(count_of_Voters),
      number_of_Candidates(count_of_Candidates),
      honesty_fraction(honest_Voters),
      _verbose(be_verbose) {
    Logging::log(this, "creating `Election` object");
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
    Logging::log(this, "creating electorate");
    for (unsigned Voter_number = 0;
         Voter_number < electorateSize();
         Voter_number++) {
        Logging::log(this, "creating `Voter` #", Voter_number);
        Voter a_Voter(number_of_Candidates, verbose());
        the_electorate.push_back(a_Voter);
    }
  }

  void Election::determineUnweightedUtilities() {
    Logging::log(this, "determining unweighted utilities");
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
    Logging::log(this, "determining weighted utilities");
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
    Logging::log(this, "determining True Condorcet Candidate");
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

  double Election::honestyFraction() const {
    return honesty_fraction;
  }

  unsigned Election::numberOfStrategicVotersNeeded() const {
    unsigned number_of_honest_Voters =
      (unsigned) std::rint(electorateSize() * honesty_fraction);
    return electorateSize() - number_of_honest_Voters;
  }

  void Election::setElectorateHonesty() {
    Logging::log(this, "setting electorate honesty");
    const unsigned number_of_strategic_Voters =
      numberOfStrategicVotersNeeded();
    const std::vector<unsigned> strategic_Voter_indicies =
      strategicVoterIndices(number_of_strategic_Voters);
    for (auto each : strategic_Voter_indicies) {
      getVoter(each)->makeStrategic();
    }
  }

  void Election::sortVoterPreferencesByActualUtilities() {
    Logging::log(this, "sorting `Voter` preferences by actual utility");
    for (unsigned Voter_index = 0;
         electorateSize() > Voter_index;
         Voter_index++) {
      Logging::log(this,
                   "sorting `Voter` #",
                   Voter_index,
                   "'s preferences by actual utility");
      Voter* single_Voter = getVoter(Voter_index);
      single_Voter->sortCandidatesByActualUtility();
    }
  }

  void Election::compare1to1(OneToOneComparison comparison) {
    Logging::log(this,
                 "comparing `Candidate` #",
                 comparison.first,
                 " to `Candidate` #",
                 comparison.second);
    unsigned votes_for_A = 0;
    unsigned votes_for_B = 0;
    for (unsigned Voter_index = 0;
         electorateSize() > Voter_index;
         Voter_index++) {
      unsigned position_of_A =
        getVoter(Voter_index)->numberRankingHigher(comparison.first);
      unsigned position_of_B =
        getVoter(Voter_index)->numberRankingHigher(comparison.second);
      if (position_of_A < position_of_B) { votes_for_A++; }
      else { votes_for_B++; }
    }
    if (votes_for_A == votes_for_B) {
      if (Pseudorandom::normalCoinFlip() == true) {
        votes_for_A++;
      } else {
        votes_for_B++;
      }
    }
    unsigned elected;
    if (votes_for_A > votes_for_B) {
      elected = comparison.first;
    } else {
      elected = comparison.second;
    }
    _Condorcet_comparisons[comparison] = elected;
  }

  void Election::compareWithEachOtherCandidate(const unsigned identifier) {
    for (unsigned Candidate_identifier = 0;
         ballotSize() > Candidate_identifier;
         Candidate_identifier++) {
      if (identifier == Candidate_identifier) {
        continue;
      }
      unsigned maximum_identifier = std::max(identifier,
                                             Candidate_identifier);
      unsigned minimum_identifier = std::min(identifier,
                                             Candidate_identifier);
      OneToOneComparison comparison(minimum_identifier,
                                    maximum_identifier);
      if (_Condorcet_comparisons.find(comparison) !=
          _Condorcet_comparisons.end()) {
        continue;
      }
      compare1to1(comparison);
    }
  }

  bool Election::electedOverAllOthers(const unsigned identifier) {
    auto lambda = [identifier](const OneToOneResult result) {
      return identifier == result.second;
    };
    const auto count = std::count_if(_Condorcet_comparisons.begin(),
                                     _Condorcet_comparisons.end(),
                                     lambda);
    return count == (ballotSize() - 1);
  }

  void Election::performOneToOneComparisonsOfCandidates() {
    Logging::log(this, "performing 1-to-1 comparisons");
    for (unsigned Candidate_identifier = 0;
         ballotSize() > Candidate_identifier;
         Candidate_identifier++) {
      compareWithEachOtherCandidate(Candidate_identifier);
    }
  }

  void Election::recordTheOneTrueCondorcetCandidate() {
    Logging::log(this, "recording the True Condorcet Candidate");
    unsigned count = 0;
    for (unsigned Candidate_identifier = 0;
         ballotSize() > Candidate_identifier;
         Candidate_identifier++) {
      if (electedOverAllOthers(Candidate_identifier)) {
        theTrueCondorcetCandidate(Candidate_identifier);
        count++;
        Verify::ensure(1 == count,
                       2,
                       "multiple True Condorcet Candidates");
      }
    }
  }

  CondorcetCandidate Election::theTrueCondorcetCandidate() const {
    return _True_Condorcet_Candidate;
  }

  void Election::theTrueCondorcetCandidate(const unsigned the_identifier) {
    _True_Condorcet_Candidate = CondorcetCandidate(the_identifier);
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

  Candidate Election::sumCandidatesUnweightedUtilities(const unsigned identifier) {
    Logging::log(this,
                 "determining unweighted utilities of `Candidate` #",
                 identifier);
    double actual_sum = 0.;
    double perceived_sum = 0.;
    for (unsigned Voter_index = 0;
         electorateSize() > Voter_index;
         Voter_index++) {
      Logging::log(this,
                   "determining unweighted utilities of `Candidate` #",
                   identifier,
                   " to `Voter` #",
                   Voter_index);
      const Voter* single_Voter = getVoter(Voter_index);
      Candidate the_Candidate =
        single_Voter->getCandidate(identifier);
      actual_sum += the_Candidate.utilities()->actualUtility() * 1;
      perceived_sum += the_Candidate.utilities()->perceivedUtility() *
                         single_Voter->weight();
    }
    Utilities summed_utilities = { actual_sum, perceived_sum };
    return Candidate(identifier, verbose(), &summed_utilities);
  }

  Candidate Election::sumCandidatesWeightedUtilities(const unsigned identifier) {
    Logging::log(this,
                 "determining weighted utilities of `Candidate` #",
                 identifier);
    double actual_sum = 0.;
    double perceived_sum = 0.;
    for (unsigned Voter_index = 0;
         electorateSize() > Voter_index;
         Voter_index++) {
      Logging::log(this,
                   "determining weighted utilities of `Candidate` #",
                   identifier,
                   " to `Voter` #",
                   Voter_index);
      const Voter* single_Voter = getVoter(Voter_index);
      Candidate the_Candidate =
        single_Voter->getCandidate(identifier);
      actual_sum += the_Candidate.utilities()->actualUtility() *
                      single_Voter->weight();
      perceived_sum += the_Candidate.utilities()->perceivedUtility() *
                         single_Voter->weight();
    }
    Utilities summed_utilities = { actual_sum, perceived_sum };
    return Candidate(identifier, verbose(), &summed_utilities);
  }

  bool Election::verbose() const {
    return _verbose;
  }
}
