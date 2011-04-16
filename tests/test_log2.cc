// Test Log2
//
// Copyright (C) 2009 Jeffrey S. Perry
//
// contact: jeffsp@gmail.com

#include "about_equal.h"
#include "log2.h"
#include "verify.h"
#include <iostream>

using namespace std;
using namespace horny_toad;

int main ()
{
    try
    {
        //for (double x = 1; x < 20; ++x)
        //    clog << "logx(" << x << ")=" << log2 (x) << endl;
        VERIFY (about_equal (log2 (1.0/3.0), -1.585));
        VERIFY (about_equal (log2 (1.0), 0.0));
        VERIFY (about_equal (log2 (3.0), 1.585));
        VERIFY (about_equal (log2 (4.0), 2.000));
        VERIFY (about_equal (log2 (7.0), 2.807));

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
