// Test Rectangle
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

#include "rect.h"
#include "verify.h"
#include <iostream>
#include <stdexcept>

using namespace horny_toad;
using namespace std;

void test1 ()
{
    rect<float> r1 (0, 1, 2, 3);
    rect<float> r2 (1, 0, 2, 3);
    r1.clip (r2);
    VERIFY (r1.get_x () == 1);
    VERIFY (r1.get_y () == 1);
    VERIFY (r1.get_width () == 1);
    VERIFY (r1.get_height () == 2);
    rect<float> r3 (0, 0, 3, 3);
    r1.clip (r3);
    VERIFY (r1.get_x () == 1);
    VERIFY (r1.get_y () == 1);
    VERIFY (r1.get_width () == 1);
    VERIFY (r1.get_height () == 2);
    r3.clip (r1);
    VERIFY (r3.get_x () == 1);
    VERIFY (r3.get_y () == 1);
    VERIFY (r3.get_width () == 1);
    VERIFY (r3.get_height () == 2);
}

void test2 ()
{
    rect<double> r;
    VERIFY (r.empty ());
    r.set_width (0.1);
    r.set_height (0.0);
    VERIFY (r.empty ());
    r.set_width (0.0);
    r.set_height (0.1);
    VERIFY (r.empty ());
    r.set_width (0.1);
    r.set_height (0.1);
    VERIFY (!r.empty ());
}

int main ()
{
    try
    {
        test1 ();
        test2 ();

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}

