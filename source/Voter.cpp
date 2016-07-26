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
#include "Verify.h"

namespace Simulation {
  Voter::Voter(const unsigned number_of_Candidates) {
    initializeRelations(number_of_Candidates);
  }

  Candidate Voter::getCandidate(const int identifier) const {
    auto predicate = [identifier](const Candidate cu) {
      return cu.designation() == identifier;
    };
    auto the_Candidate = std::find_if(relationToCandidates.begin(),
                                      relationToCandidates.end(),
                                      predicate);
    auto lambda = [the_Candidate, identifier, this] () {
      std::string identifier_string = std::to_string(identifier);
      Printing::printAsOneLine({"searching for ",
                                identifier_string});
      Printing::printAsOneLine({"instead found:"});
      for (auto each : relationToCandidates) {
        auto designation = each.designation();
        std::string designation_string =
          std::to_string(designation);
        Printing::printAsOneLine({"\t",
                                  designation_string});
      }
    };
    Verify::ensure(the_Candidate != relationToCandidates.end(), 1, &lambda);
    return *the_Candidate;
  }

  void Voter::initializeRelations(const unsigned numberOfCandidates) {
    for (unsigned Candidate_number = 0;
         Candidate_number < numberOfCandidates;
         Candidate_number++) {
      Candidate a_Candidate(Candidate_number);
      relationToCandidates.push_back(a_Candidate);
    }
  }

  void Voter::makeStrategic() {
    voting_nature = VotingNature::Strategic;
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
}
