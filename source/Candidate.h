//===--- Candidate.h - Information About A Candidate ---===//
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
// A collection of information about a particular Candidate,
// such as identification and utility to a particular Voter;
// used to help guide votes in simulations.
//
//===----------------------------------------------------------------------===//

#ifndef EMMA_CANDIDATE_H
#define EMMA_CANDIDATE_H

#include "Utilities.h"

namespace Simulation {
  class Candidate {
    // utility values
    Utilities _utilities;

    // designation number
    unsigned _designation;

    // whether to be verbose in actions or not
    bool _verbose = false;

    // initializes utility values with randomly generated
    // numbers
    void initializeUtilities();
public:
    Candidate(unsigned the_designation,
              bool be_verbose,
              Utilities* = nullptr);

    // sets the utility information to the given value if
    // non-null or to random normally distributed values if null
    void utilities(Utilities*);

    // returns the utility information
    Utilities* utilities();

    // sets the Candidate designation number to the given value
    void designation(unsigned);

    // returns the Candidate's designation
    unsigned designation() const;

    // returns `true` if this object should be verbose in its
    // actions or `false` otherwise; note: even if this function
    // returns `true`, this method itself is not verbose by
    // design
    bool verbose() const;
  };
}

#endif
