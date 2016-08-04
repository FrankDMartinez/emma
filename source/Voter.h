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

#ifndef EMMA_VOTER_H
#define EMMA_VOTER_H

#include <vector>
#include "Candidate.h"

namespace Simulation {
  class Voter {
    // The perceived and actual utilities of the Candidates to
    // this Voter
    std::vector<Candidate> relationToCandidates;

    // whether to be verbose in actions or not
    bool _verbose = false;

    // The "honest"-versus-"strategic" voting nature of the
    // Voter
    enum VotingNature { Honest, Strategic };

    // If this Voter is an "honest" Voter or a "strategic" Voter
    VotingNature voting_nature = VotingNature::Honest;

    // the relative weight of the Voter's votes; traditionally, 1
    unsigned _weight = 1;

    // Create the Candidates and Their utilities to this Voter
    void initializeRelations(const unsigned numberOfCandidates);
  public:
    Voter(const unsigned number_of_Candidates, bool be_verbose);

    // Records the voting nature of the Voter as "strategic" as
    // opposed to "honest"
    void makeStrategic();

    // Returns the information with respect to the current Voter
    // about a Candidate identified by the given identifier
    Candidate getCandidate(const unsigned identifier) const;

    // returns the number of Candidate this Voter ranks higher
    // than the Candidate indicated by the given designation
    unsigned numberRankingHigher(unsigned) const;

    Candidate& operator[](const int index);
    const Candidate& operator[](const int index) const;
    bool votesHonestly() const;

    // sorts the collection of Candidate information based on
    // Each Candidate's actual utility to this Voter
    void sortCandidatesByActualUtility();

    // returns `true` if this object should be verbose in its
    // actions or `false` otherwise; note: even if this function
    // returns `true`, this method itself is not verbose by
    // design
    bool verbose() const;

    // returns the relative weight of the Voter's votes
    unsigned weight() const;
  };
}

#endif
