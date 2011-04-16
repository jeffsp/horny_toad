// Test Polar
//
// Copyright (C) 2008 Jeffrey S. Perry
//
// contact: jeffsp@gmail.com

#include "about_equal.h"
#include "pi.h"
#include "polar.h"
#include "verify.h"
#include <iostream>

using namespace std;
using namespace horny_toad;

int main ()
{
    try
    {
        double r, th;
        double x, y;
        cart2pol (1.0, 0.0, r, th);
        pol2cart (r, th, x, y);
        VERIFY (about_equal (r, 1.0));
        VERIFY (about_equal (th, 0*PI()/4));
        VERIFY (about_equal (x, 1.0));
        VERIFY (about_equal (y, 0.0));
        cart2pol (1.0, 1.0, r, th);
        pol2cart (r, th, x, y);
        VERIFY (about_equal (r, sqrt (2.0)));
        VERIFY (about_equal (th, 1*PI()/4));
        VERIFY (about_equal (x, 1.0));
        VERIFY (about_equal (y, 1.0));
        cart2pol (0.0, 1.0, r, th);
        pol2cart (r, th, x, y);
        VERIFY (about_equal (r, 1.0));
        VERIFY (about_equal (th, 2*PI()/4));
        VERIFY (about_equal (x, 0.0));
        VERIFY (about_equal (y, 1.0));
        cart2pol (-1.0, 1.0, r, th);
        pol2cart (r, th, x, y);
        VERIFY (about_equal (r, sqrt (2.0)));
        VERIFY (about_equal (th, 3*PI()/4));
        VERIFY (about_equal (x, -1.0));
        VERIFY (about_equal (y, 1.0));
        cart2pol (-1.0, 0.0, r, th);
        pol2cart (r, th, x, y);
        VERIFY (about_equal (r, 1.0));
        VERIFY (about_equal (th, 4*PI()/4));
        VERIFY (about_equal (x, -1.0));
        VERIFY (about_equal (y, 0.0));
        cart2pol (-1.0, -1.0, r, th);
        pol2cart (r, th, x, y);
        VERIFY (about_equal (r, sqrt (2.0)));
        VERIFY (about_equal (th, -3*PI()/4));
        VERIFY (about_equal (x, -1.0));
        VERIFY (about_equal (y, -1.0));
        cart2pol (0.0, -1.0, r, th);
        pol2cart (r, th, x, y);
        VERIFY (about_equal (r, 1.0));
        VERIFY (about_equal (th, -2*PI()/4));
        VERIFY (about_equal (x, 0.0));
        VERIFY (about_equal (y, -1.0));
        cart2pol (1.0, -1.0, r, th);
        pol2cart (r, th, x, y);
        VERIFY (about_equal (r, sqrt (2.0)));
        VERIFY (about_equal (th, -1*PI()/4));
        VERIFY (about_equal (x, 1.0));
        VERIFY (about_equal (y, -1.0));

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
