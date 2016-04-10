//===--- IndividualElectionStatistics.cpp - "Statistics for Each Election" Related Typing ---===//
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
// Typing relating to statistics for each method in each
// election the application should gather.
// Keeps track of which information about each method for each
// election the application should collect.
//
//===----------------------------------------------------------------------===//

#include "IndividualElectionStatistics.h"

namespace Emma {
  bool IndividualElectionStatistics::collectBayesianRegret() const {
    return _BayesianRegret;
  }
  bool IndividualElectionStatistics::collectBayesianRegretPerVoter() const {
    return _BayesianRegretPerVoter;
  }
  bool IndividualElectionStatistics::collectCondorcetCandidate() const {
    return _CondorcetCandidate;
  }
  bool IndividualElectionStatistics::collectIBR() const {
    return _IBR;
  }
  bool IndividualElectionStatistics::collectLeastIBRFraction() const {
    return leastIBRFraction;
  }
  bool IndividualElectionStatistics::collectMeanIBR() const {
    return meanIBR;
  }
  bool IndividualElectionStatistics::collectStandardDeviationOfIBR() const {
    return standardDeviationOfIBR;
  }
  bool IndividualElectionStatistics::collectTrueCondorcetCandidate() const {
    return trueCondorcetCandidate;
  }
}
