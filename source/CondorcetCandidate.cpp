//===--- CondorcetCandidate.cpp - Information About A Condorcet Candidate ---===//
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
// A collection of information about a Condorcet Candidate
//
//===----------------------------------------------------------------------===//

#include "CondorcetCandidate.h"

namespace Simulation {
  void CondorcetCandidate::exists(bool does_exist) {
    _exists = does_exist;
  }

  void CondorcetCandidate::identifier(unsigned the_identifier) {
    _identifier = the_identifier;
  }

  CondorcetCandidate::CondorcetCandidate() {}

  CondorcetCandidate::CondorcetCandidate(unsigned the_identifier) {
    identifier(the_identifier);
    exists(true);
  }

  bool CondorcetCandidate::exists() const {
    return _exists;
  }

  unsigned CondorcetCandidate::identifier() const {
    return _identifier;
  }
}
