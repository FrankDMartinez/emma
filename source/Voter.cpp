//===--- Voter.cpp - Information About A Single Voter ---===//
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
// A collection of information about a particular Voter, such as
// honesty and utility values of each Candidate
//
//===----------------------------------------------------------------------===//

#include "Voter.h"
#include <iostream>
#include "Logging.h"
#include "Pseudorandom.h"
#include "Verify.h"

namespace Simulation {
  Voter::Voter(const unsigned number_of_Candidates,
               const bool be_verbose)
    : _verbose(be_verbose) {
    Logging::log(this, "creating `Voter` object");
    initializeRelations(number_of_Candidates);
  }

  Candidate Voter::getCandidate(const unsigned identifier) const {
    Logging::log(this, "getting `Candidate` #", identifier);
    auto predicate = [identifier](const Candidate cu) {
      return cu.designation() == identifier;
    };
    auto the_Candidate = std::find_if(relationToCandidates.begin(),
                                      relationToCandidates.end(),
                                      predicate);
    Verify::ensure(the_Candidate != relationToCandidates.end(),
                   1,
                   "searching for identifier:",
                   identifier,
                   "instead found:",
                   relationToCandidates);
    return *the_Candidate;
  }

  void Voter::initializeRelations(const unsigned numberOfCandidates) {
    Logging::log(this, "initializing relations to `Candidate`s");
    for (unsigned Candidate_number = 0;
         Candidate_number < numberOfCandidates;
         Candidate_number++) {
      Logging::log(this, "initializing relation #", Candidate_number);
      Candidate a_Candidate(Candidate_number, verbose());
      relationToCandidates.push_back(a_Candidate);
    }
  }

  void Voter::makeStrategic() {
    voting_nature = VotingNature::Strategic;
  }

  unsigned Voter::numberRankingHigher(unsigned identifier) const {
    auto lambda = [identifier](const Candidate the_Candidate) {
      return the_Candidate.designation() == identifier;
    };
    auto it = std::find_if(relationToCandidates.begin(),
                           relationToCandidates.end(),
                           lambda);
    return std::distance(relationToCandidates.begin(), it);
  }

  Candidate& Voter::operator[](const int index) {
    return relationToCandidates[index];
  }

  const Candidate& Voter::operator[](const int index) const {
    return relationToCandidates[index];
  }

  bool Voter::votesHonestly() const {
    return voting_nature == VotingNature::Honest;
  }

  void Voter::sortCandidatesByActualUtility() {
    auto comparison = [](Candidate one, Candidate two) {
      if (one.utilities()->actualUtility() >
          two.utilities()->actualUtility()) {
        return true;
      } else if (one.utilities()->actualUtility() <
                 two.utilities()->actualUtility()) {
        return false;
      } else {
        return Pseudorandom::normalCoinFlip();
      }
    };
    std::stable_sort(relationToCandidates.begin(),
                     relationToCandidates.end(),
                     comparison);
  }

  bool Voter::verbose() const {
    return _verbose;
  }

  unsigned Voter::votes(const VoteWeighting w) const {
    if (w == VoteWeighting::Weighted) {
      return _weight;
    } else {
      return 1;
    }
  }

  unsigned Voter::weight() const {
    return _weight;
  }
}
