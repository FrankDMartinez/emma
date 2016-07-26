//===--- Candidate.cpp - Information About A Candidate ---===//
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

#include "Candidate.h"
#include "Pseudorandom.h"

namespace Simulation {
  Candidate::Candidate(unsigned the_designation, Utilities* the_utilities) {
    designation(the_designation);
    utilities(the_utilities);
  }

  Utilities* Candidate::utilities() {
    return &_utilities;
  }

  void Candidate::utilities(Utilities* the_utilities) {
    if (the_utilities) {
      _utilities = *the_utilities;
    } else {
      double value;
      value = Pseudorandom::normallyDistributedDouble();
      utilities()->actualUtility(value);
      value = Pseudorandom::normallyDistributedDouble();
      utilities()->perceivedUtility(value);
    }
  }

  void Candidate::designation(unsigned the_designation) {
    _designation = the_designation;
  }

  unsigned Candidate::designation() const {
    return _designation;
  }
}
