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
#include "CandidateUtilities.h"

namespace Simulation {
  class Voter {
    // The perceived and actual utilities of the Candidates to
    // this Voter
    std::vector<CandidateUtilities> relationToCandidates;

    // The "honest"-versus-"strategic" voting nature of the
    // Voter
    enum VotingNature { Honest, Strategic };

    // If this Voter is an "honest" Voter or a "strategic" Voter
    VotingNature voting_nature = VotingNature::Honest;

    // Create the Candidates and Their utilities to this Voter
    void initializeRelations(const unsigned numberOfCandidates);

    // Sets the voting nature of the Voter with the given
    // probability this Voter votes "honestly" and not
    // "strategically"
    void setVotingNature(const double honesty_probability);
  public:
    Voter(const unsigned number_of_Candidates,
          const double honesty_probability);
    CandidateUtilities& operator[](const int index);
    const CandidateUtilities& operator[](const int index) const;
    bool votesHonestly() const;
  };
}