/// @file test_readlines.cc
/// @brief test readlines
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-01-15

#include <iostream>
#include <sstream>
#include "readlines.h"
#include "verify.h"

using namespace std;
using namespace horny_toad;

void test_readlines ()
{
    stringstream ss1, ss2;
    ss1 << "one\n2\nthree\nfour";
    ss2 << "one\n2\nthree\n";
    vector<string> l1 = readlines<string> (ss1);
    VERIFY (l1.size () == 4);
    vector<string> l2 = readlines<string> (ss2);
    VERIFY (l2.size () == 3);
}

int main ()
{
    try
    {
        test_readlines ();

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what () << endl;
        return -1;
    }
}
