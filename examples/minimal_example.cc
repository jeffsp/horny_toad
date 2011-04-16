// Another example of using argv module
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

#include "argv.h"
#include <iostream>
#include <stdexcept>

using namespace horny_toad;
using namespace std;

int main (int argc, char **argv)
{
    try
    {
        bool help = false;
        unsigned model_number = 1;
        string inputfn;

        CommandLine cl;
        cl.AddSpec ("help", 'h', help, "Print help message");
        cl.AddSpec ("model", 'm', model_number, "Model Number", "#", "#");
        cl.AddSpec ("", '\0', inputfn, "Input filename", "FN");
        // Group argv's into option groups
        cl.GroupArgs (argc, argv, 1);
        // Convert from strings to their proper type
        cl.ExtractBegin ();
        cl.Extract (help);
        cl.Extract (model_number);
        cl.Extract (inputfn);
        cl.ExtractEnd ();

        if (help || inputfn.empty () || !cl.GetLeftOverArgs ().empty ())
            throw runtime_error ("usage: " + string (argv[0]) + " " + cl.Usage ());

        cout << "inputfn: " << inputfn << endl;
        cout << "model: " << model_number << endl;

        return 0;
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what () << endl;
        return -1;
    }
}
