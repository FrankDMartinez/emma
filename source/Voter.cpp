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

#include <iostream>
#include "Voter.h"

namespace Simulation {
  Voter::Voter(const unsigned number_of_Candidates) {
    initializeRelations(number_of_Candidates);
  }

  void Voter::initializeRelations(const unsigned numberOfCandidates) {
    for (unsigned Candidate_number = 0;
         Candidate_number < numberOfCandidates;
         Candidate_number++) {
      CandidateUtilities a_Candidate(Candidate_number);
      relationToCandidates.push_back(a_Candidate);
    }
  }

  void Voter::makeStrategic() {
    voting_nature = VotingNature::Strategic;
  }

  CandidateUtilities& Voter::operator[](const int index) {
    return relationToCandidates[index];
  }

  const CandidateUtilities& Voter::operator[](const int index) const {
    return relationToCandidates[index];
  }

  bool Voter::votesHonestly() const {
    return voting_nature == VotingNature::Honest;
  }
}
