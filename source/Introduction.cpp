//===--- Introduction.cpp - Introduction Related Functionality ---===//
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
// Functionality relating to the introduction.
// This functionality includes displaying the title, copyright,
// and license of the application.
//
//===----------------------------------------------------------------------===//

#include "Introduction.h"
#include "Copyright.h"
#include "License.h"
#include "Title.h"
#include "Printing.h"

namespace Introduction {
  void display() {
    Title::display();
    Copyright::display();
    License::display();
    Printing::printLines({ "" });
  }
}
