//===--- Printing.h - Print Related Functionality ---===//
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
// Functionality relating to general output.
//
//===----------------------------------------------------------------------===//

#include <string>
#include <vector>

namespace Printing {
  // Prints the given strings in the given order as one line,
  // moving the printing position to the start of the next line
  // when finished
  void printAsOneLine(std::vector<std::string> strings);

  // Prints each of the given strings on a separate line in the
  // given order
  void printLines(std::vector<std::string> strings);
}
