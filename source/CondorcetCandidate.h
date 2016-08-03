//===--- CondorcetCandidate.h - Information About A Condorcet Candidate ---===//
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
// A collection of information about a Condorcet Candidate
//
//===----------------------------------------------------------------------===//

namespace Simulation {
  class CondorcetCandidate {
    // whether or not this Condorcet Candidate exists
    bool _exists = false;
    // records this Condorcet Candidate as existing or not
    void exists(bool does_exist);
    // the identifier indicating the Condorcet Candidate; not
    // meaningful if the Condorcet Candidate does not exist
    unsigned _identifier = 0;
    // records the identifier of this Condorcet Candidate
    void identifier(unsigned the_identifier);
  public:
    CondorcetCandidate();
    CondorcetCandidate(unsigned the_identifier);
    // returns `true` if this Condorcet Candidate exists and
    // `false` if not
    bool exists() const;
    // returns the identifier of the Candidate
    unsigned identifier() const;
  };
}
