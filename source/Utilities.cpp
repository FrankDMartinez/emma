//===--- Utilities.cpp - Utilities Information About A Candidate ---===//
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
// particular Candidate to a particular Voter; used to help
// guide votes in simulations.
//
//===----------------------------------------------------------------------===//

#include "Utilities.h"

namespace Simulation {
  void Utilities::actualUtility(UtilityValue value) {
    _actual = value;
  }

  UtilityValue Utilities::actualUtility() const {
    return _actual;
  }

  void Utilities::perceivedUtility(UtilityValue value) {
    _perceived = value;
  }

  UtilityValue Utilities::perceivedUtility() const {
    return _perceived;
  }
}
