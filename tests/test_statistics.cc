// Test Stats Utilities
//
// Copyright (C) 2004-2011
// Center for Perceptual Systems
// University of Texas at Austin
//
// contact: jeffsp@gmail.com

#include "about_equal.h"
#include "statistics.h"
#include "verify.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace horny_toad;

int main ()
{
    try
    {
        vector<int> x (10, 3);
        VERIFY (about_equal (var (x), 0.0));
        for (size_t i = 0; i < x.size (); ++i)
            x[i] = i;
        VERIFY (about_equal (var (x), 9.1667));
        VERIFY (about_equal (stdev (x), 3.0277));
        vector<int> y (10);
        for (size_t i = 0; i < x.size (); ++i)
            y[i] = x[i] * x[i];
        VERIFY (about_equal (corr (x, y), 0.9627));

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
