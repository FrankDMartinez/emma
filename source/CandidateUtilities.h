//===--- CandidateUtilities.h - Utilities Information About A Candidate ---===//
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

namespace Simulation {
  typedef double Utility;
  class CandidateUtilities {
    // The actual utility of the Candidate to the Voter
    Utility actual = 0;
    // The perceived utility of the Candidate by the Voter
    Utility perceived = 0;
    // Initialize the actual utility
    void initializeActualUtility();
    // Initialize the perceived utility
    void initializePerceivedUtility();
  public:
    CandidateUtilities();
    Utility getActualUtility() const;
    Utility getPerceivedUtility() const;
  };
}
