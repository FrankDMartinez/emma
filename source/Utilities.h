//===--- Utilities.h - Utilities Information About A Candidate ---===//
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

#ifndef EMMA_UTILITIES_H
#define EMMA_UTILITIES_H

namespace Simulation {
  typedef double UtilityValue;
  class Utilities {
    // The actual utility of the Candidate to the Voter
    UtilityValue _actual = 0;

    // The perceived utility of the Candidate by the Voter
    UtilityValue _perceived = 0;
  public:
    Utilities();
    Utilities(UtilityValue actual, UtilityValue perceived);

    // sets the actual utility of the Candidate to the Voter
    void actualUtility(UtilityValue);

    // returns the actual utility of the Candidate to the Voter
    UtilityValue actualUtility() const;

    // sets the perceived utility of the Candidate to the Voter
    void perceivedUtility(UtilityValue);

    // returns the perceived utility of the Candidate to the
    // Voter
    UtilityValue perceivedUtility() const;
  };
}

#endif
