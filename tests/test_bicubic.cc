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
    double max_diff = 0;
    for (size_t i = 3; i + 3 < n.rows (); ++i)
    {
        for (size_t j = 3; j + 3 < n.cols (); ++j)
        {
            double diff = abs (n (i, j) - m2 (i, j));
            if (diff > max_diff)
                max_diff = diff;
        }
    }
    if (verbose)
        clog << max_diff << endl;
    VERIFY (max_diff < 1);
}

void test2 (bool verbose)
{
    raster<unsigned> m1 (11, 11, 255);
    subscript_unary_function<double,gaussian_window> g1 (m1.rows (), m1.cols ());
    g1.stddev (m1.rows () / 4.0);
    transform (m1.begin (), m1.end (), m1.begin (), g1);
    if (verbose)
        print2d (clog, m1);
    raster<unsigned> m2 (m1.rows () - 1, m1.cols () - 1, 255);
    subscript_unary_function<double,gaussian_window> g2 (m2.rows (), m2.cols ());
    g2.stddev (m1.rows () / 4.0);
    transform (m2.begin (), m2.end (), m2.begin (), g2);
    if (verbose)
        print2d (clog, m2);
    raster<float> x (m2.rows (), m2.cols ());
    raster<float> y (m2.rows (), m2.cols ());
    // get x,y coordinates for points between each pixel
    for (size_t i = 0; i < m2.rows (); ++i)
    {
        for (size_t j = 0; j < m2.cols (); ++j)
        {
            x (i, j) = j + 0.5;
            y (i, j) = i + 0.5;
        }
    }
    raster<float> n (m2.rows (), m2.cols ());
    bicubic_interp (m1, x, y, n);
    if (verbose)
    {
        print2d (clog, n);
    }
    double max_diff = 0;
    for (size_t i = 3; i + 3 < n.rows (); ++i)
    {
        for (size_t j = 3; j + 3 < n.cols (); ++j)
        {
            double diff = abs (n (i, j) - m2 (i, j));
            if (diff > max_diff)
                max_diff = diff;
        }
    }
    if (verbose)
        clog << max_diff << endl;
    VERIFY (max_diff < 1);
}

void test3 (bool verbose)
{
    raster<unsigned> p (4, 4, 255);
    subscript_unary_function<double,gaussian_window> g (p.rows (), p.cols ());
    g.stddev (p.rows () / 4.0);
    transform (p.begin (), p.end (), p.begin (), g);
    if (verbose)
        print2d (clog, p);
    raster<float> x (1, 1, 1.5);
    raster<float> y (1, 1, 1.5);
    raster<float> q (1);
    bicubic_interp (p, x, y, q);
    if (verbose)
    {
        clog << x[0] << "," << y[0] << " = " << q[0] << endl;
    }
}

int main (int argc, char **)
{
    try
    {
        const bool verbose = (argc != 1);
        test1 (verbose);
        test2 (verbose);
        test3 (verbose);

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
