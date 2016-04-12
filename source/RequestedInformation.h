//===--- RequestedInformation.h - Requested Information Functionality ---===//
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
// Functionality related to determining requested information.
// Analyzes information passed to the application and determines
// how the application should act.
//
//===----------------------------------------------------------------------===//

#include "RunState.h"

namespace RequestedInformation {
  // Analyzes arguments passed to the application, returning
  // information on how to act based on those options
  Emma::RunState determine(int argc, char **argv);
}
