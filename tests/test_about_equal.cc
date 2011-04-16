// Test about_equal
//
// Copyright (C) 2008 Jeffrey S. Perry
//
// contact: jeffsp@gmail.com

#include "about_equal.h"
#include "pi.h"
#include "verify.h"
#include <iostream>

using namespace std;
using namespace horny_toad;

int main ()
{
    try
    {
        VERIFY (about_equal (1, 1));
        VERIFY (about_equal (PI(), 3.14159));
        VERIFY (about_equal (PI(), 3.0, 1.0));
        VERIFY (about_equal (PI(), 3.142, 0.001));
        VERIFY (!about_equal (PI(), 3.141, 0.001));

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
