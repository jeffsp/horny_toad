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
    raster<unsigned> m1 (23, 23, 255);
    subscript_unary_function<double,gaussian_window> g1 (m1.rows (), m1.cols ());
    g1.stddev (m1.rows () / 7.0);
    transform (m1.begin (), m1.end (), m1.begin (), g1);
    if (verbose)
        print2d (clog, m1);
    raster<double> n (m1.rows () * 2, m1.cols () * 2);
    bicubic_interp (m1, n);
    if (verbose)
        print2d (clog, n);
    raster<unsigned> m2 (m1.rows () * 2, m1.cols () * 2, 255);
    subscript_unary_function<double,gaussian_window> g2 (m2.rows (), m2.cols ());
    g2.stddev (m2.rows () / 7.0);
    transform (m2.begin (), m2.end (), m2.begin (), g2);
    if (verbose)
        print2d (clog, m2);
    int max_diff = 0;
    for (size_t i = 3; i + 3 < n.rows (); ++i)
    {
        for (size_t j = 3; j + 3 < n.cols (); ++j)
        {
            int diff = abs (n (i, j) - m2 (i, j));
            if (diff > max_diff)
                max_diff = diff;
        }
    }
    if (verbose)
        clog << max_diff << endl;
    VERIFY (max_diff < 1);
}

int main (int argc, char **)
{
    try
    {
        const bool verbose = (argc != 1);
        test1 (verbose);

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
