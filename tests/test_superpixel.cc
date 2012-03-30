// Test Superpixel
//
// Copyright (C) 2008 Jeffrey S. Perry
//
// This program is free software: you can redistribute it
// and/or modify it under the terms of the GNU General
// Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your
// option) any later version.
//
// This program is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A
// PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public
// License along with this program.  If not, see
// <http://www.gnu.org/licenses/>.
//
// contact: jeffsp@gmail.com

#include "superpixel.h"
#include "verify.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace horny_toad;
using namespace std;

void test0 ()
{
    superpixel s1 (0, 0, 0);
    VERIFY (s1.get_row () == 0);
    VERIFY (s1.get_col () == 0);
    VERIFY (s1.get_size () == 0);
    superpixel s2 (1, 2, 3);
    VERIFY (s2.get_row () == 1);
    VERIFY (s2.get_col () == 2);
    VERIFY (s2.get_size () == 3);
}

int main ()
{
    try
    {
        test0 ();

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
