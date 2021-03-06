//===--- Pseudorandom.cpp - Pseudorandom Utility Functions ---===//
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
// A collection of utility functions for when pseudorandom
// number generation and/or selection are required, such normal
// distributions, selection from a collection, etc.
//
//===----------------------------------------------------------------------===//

#include "Pseudorandom.h"

namespace Pseudorandom {
  std::mt19937_64            prn_generator;
  std::normal_distribution<> the_normal_distribution;
  std::bernoulli_distribution the_coin_flip_distribution;

  bool normalCoinFlip() {
    return the_coin_flip_distribution(prn_generator);
  }

  double normallyDistributedDouble() {
    return the_normal_distribution(prn_generator);
  }
}
