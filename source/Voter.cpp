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
  Voter::Voter(const unsigned number_of_Candidates,
               const double honesty_probability) {
    initializeRelations(number_of_Candidates);
    setVotingNature(honesty_probability);
  }

  void Voter::initializeRelations(const unsigned numberOfCandidates) {
    std::cout << __func__ << " is not yet implemented" << std::endl;
  }

  CandidateUtilities& Voter::operator[](const int index) {
    return relationToCandidates[index];
  }

  const CandidateUtilities& Voter::operator[](const int index) const {
    return relationToCandidates[index];
  }

  void Voter::setVotingNature(const double honesty_probability) {
    std::cout << __func__ << " is not yet implemented" << std::endl;
  }

  bool Voter::votesHonestly() const {
    return voting_nature == VotingNature::Honest;
  }
}
