// Test Bicubic Interpolation
//
// Copyright (C) 2004-2011
// Center for Perceptual Systems
// University of Texas at Austin
//
// contact: jeffsp@gmail.com

#include "about_equal.h"
#include "bicubic.h"
#include "raster.h"
#include "raster_utils.h"
#include "subscript_function.h"
#include "verify.h"
#include <iostream>

using namespace std;
using namespace jack_rabbit;
using namespace horny_toad;

void test1 (bool verbose)
{
    raster<unsigned> m (5, 5, 255);
    subscript_unary_function<double,gaussian_window> g (m.rows (), m.cols ());
    g.stddev (m.rows () / 7.0);
    transform (m.begin (), m.end (), m.begin (), g);
    if (verbose)
        print2d (clog, m);
    raster<double> n (m.rows () * 2, m.cols () * 2);
    bicubic_interp (m, n);
    if (verbose)
        print2d (clog, n);
    VERIFY (true);
}

int main (int argc, char **)
{
    try
    {
        const bool verbose = (argc != 2);
        test1 (verbose);

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
