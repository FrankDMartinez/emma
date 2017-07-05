//===--- Results.h - Results Output Functionality ---===//
//
// This file is part of the Election Method Mathematics Application (EMMA) project.
//
// Copyright (c) 2015 - 2016 Frank D. Martinez and the EMMA project authors
// Licensed under the GNU Affero General Public License, version 3.0.
//
// See the file called "LICENSE" included with this distribution for license information.
//
//===----------------------------------------------------------------------===//
//
// Functionality relating to reproting results.
// In general, all functionality will eventually pass thru here
// in the process of outputting results.
//
//===----------------------------------------------------------------------===//

#ifndef EMMA_RESULTS_H
#define EMMA_RESULTS_H

#include "Data.h"

namespace Results {
  // Outputs requested results stored in the given scenarios
  void output(const Data::Scenarios*);
}

#endif
