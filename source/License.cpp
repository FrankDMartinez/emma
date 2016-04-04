//===--- License.cpp - License Related Functionality ---===//
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
// Functionality relating to the license of the application.
//
//===----------------------------------------------------------------------===//

#include <iostream>
#include "License.h"
#include "Printing.h"

namespace License {
  void display() {
    Printing::printLines({ "You may distribute/use this application only in accordance with the GNU Affero General",
                           "Public License, version 3.0." });
  }
}
