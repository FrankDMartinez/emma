//===--- StatisticsRequired.cpp - "Statistics To Gather" Related Typing ---===//
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
// Typing relating to statistics the application should gather.
// Keeps track of which information the application should
// collect.
//
//===----------------------------------------------------------------------===//

#include "StatisticsRequired.h"

namespace Emma {
  StatisticsRequired::StatisticsRequired() {}
  StatisticsRequired::StatisticsRequired(const RawParsedOptions rpo) {}
  IndividualElectionStatistics StatisticsRequired::getIndividualElectionStatistics() const {
    return each_election;
  }
  OverviewStatistics StatisticsRequired::getOverviewStatistics() const {
    return simulation_wide;
  }
}
