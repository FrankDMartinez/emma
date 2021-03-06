//===--- VoteWeighting.h - Information About How To Weigh Votes ---===//
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
// Information about whether or not votes should be weighted
// according to the relative weight of Each `Voter`'s votes
//
//===----------------------------------------------------------------------===//

namespace Simulation {
  enum VoteWeighting {
    Weighted,
    Unweighted
  };
}
