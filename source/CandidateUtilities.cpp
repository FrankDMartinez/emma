//===--- CandidateUtilities.cpp - Utilities Information About A Candidate ---===//
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
// A collection of utilities, actual and perceived, of a
// particular Candidate to a particular Voter
//
//===----------------------------------------------------------------------===//

#include "CandidateUtilities.h"
#include "Pseudorandom.h"

namespace Simulation {
  CandidateUtilities::CandidateUtilities() {
    initializeActualUtility();
    initializePerceivedUtility();
  }

  Utility CandidateUtilities::getActualUtility() const {
    return actual;
  }

  Utility CandidateUtilities::getPerceivedUtility() const {
    return perceived;
  }

  void CandidateUtilities::initializeActualUtility() {
    actual = Pseudorandom::normallyDistributedDouble();
  }

  void CandidateUtilities::initializePerceivedUtility() {
    perceived = Pseudorandom::normallyDistributedDouble();
  }
}
