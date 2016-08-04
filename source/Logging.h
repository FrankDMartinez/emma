//===--- Logging.h - Logging Utilities ---===//
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
// Functionality related to logging information.
//
//===----------------------------------------------------------------------===//

#include "Election.h"
#include "Printing.h"
#include "RunState.h"

namespace Logging {
  static const std::string tab_string = "\t";

  template <class... Others>
  void log(const std::string the_string, Others... others) {
    Printing::printAsOneLine(the_string, others...);
  }

  template <class... Others>
  void log(const Emma::RunState* state, Others... others) {
    if (state->mode().beVerbose() == true) {
      log(others...);
    }
  }

  template <class... Others>
  void log(const Simulation::Election* e, Others... others) {
    if (e->verbose() == true) {
      log(tab_string, others...);
    }
  }

  template <class... Others>
  void log(const Simulation::Voter* v, Others... others) {
    if (v->verbose() == true) {
      log(tab_string, tab_string, others...);
    }
  }
}
