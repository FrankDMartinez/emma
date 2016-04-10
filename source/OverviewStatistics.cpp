//===--- OverviewStatistics.cpp - "Statistics for Each Method Overall" Related Typing ---===//
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
// Typing relating to statistics for each method overall the
// application should gather.
// Keeps track of which information about each method overall
// the application should collect.
//
//===----------------------------------------------------------------------===//

#include "OverviewStatistics.h"

namespace Emma {
  bool OverviewStatistics::collectBayesianRegret() const {
    return _BayesianRegret;
  }
  bool OverviewStatistics::collectBayesianRegretStandardDeviation() const {
    return _BayesianRegretStandardDeviation;
  }
  bool OverviewStatistics::collectCondorcetAgreementRates() const {
    return _CondorcetAgreementRates;
  }
  bool OverviewStatistics::collectCondorcetCandidateFraction() const {
    return _CondorcetCandidateFraction;
  }
  bool OverviewStatistics::collectIBR() const {
    return _IBR;
  }
  bool OverviewStatistics::collectIBRStandardDeviation() const {
    return _IBRStandardDeviation;
  }
  bool OverviewStatistics::collectLeastIBRFractionForLargestFraction() const {
    return leastIBRFractionForLargestFraction;
  }
  bool OverviewStatistics::collectLeastIBRFractionOfVoters() const {
    return leastIBRFractionOfVoters;
  }
  bool OverviewStatistics::collectMeanBayesianRegret() const {
    return meanBayesianRegret;
  }
  bool OverviewStatistics::collectMeanIBR() const {
    return meanIBR;
  }
  bool OverviewStatistics::collectTrueCondorcetCandidateFraction() const {
    return trueCondorcetCandidateFraction;
  }
}
