/// @file test_mse.cc
/// @brief test mse
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-01-17

#include "about_equal.h"
#include "mse.h"
#include "verify.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace horny_toad;

int main ()
{
    try
    {
        vector<int> a (1000, 10);
        vector<int> b (1000, 20);
        VERIFY (mse (a, a) == 0);
        VERIFY (mse (a, b) == 100);
        VERIFY (about_equal (psnr (mse (a, b)), 28.1308));

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
