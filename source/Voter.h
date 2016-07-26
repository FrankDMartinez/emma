//===--- Voter.h - Information About A Single Voter ---===//
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

#include <vector>
#include "Candidate.h"

namespace Simulation {
  class Voter {
    // The perceived and actual utilities of the Candidates to
    // this Voter
    std::vector<Candidate> relationToCandidates;

    // The "honest"-versus-"strategic" voting nature of the
    // Voter
    enum VotingNature { Honest, Strategic };

    // If this Voter is an "honest" Voter or a "strategic" Voter
    VotingNature voting_nature = VotingNature::Honest;

    // Create the Candidates and Their utilities to this Voter
    void initializeRelations(const unsigned numberOfCandidates);
  public:
    Voter(const unsigned number_of_Candidates);

    // Records the voting nature of the Voter as "strategic" as
    // opposed to "honest"
    void makeStrategic();

    // Returns the information with respect to the current Voter
    // about a Candidate identified by the given identifier
    Candidate getCandidate(const int identifier) const;

    Candidate& operator[](const int index);
    const Candidate& operator[](const int index) const;
    bool votesHonestly() const;
  };
}
