// Statistics Utilities
//
// Copyright (C) 2004-2011
// Center for Perceptual Systems
// University of Texas at Austin
//
// contact: jeffsp@gmail.com

#ifndef STATISTICS_H
#define STATISTICS_H

#include <algorithm>
#include <cassert>

namespace horny_toad
{

// Compute mean
template<typename T>
double mean (const T &x)
{
    return accumulate (x.begin (), x.end (), 0.0) / x.size ();
}

// Compute unbiased estimate of the variance
template<typename T>
double var (const T &x)
{
    double u = mean (x);
    double s2 = 0.0;
    for (size_t i = 0; i < x.size (); ++i)
    {
        double d = x[i] - u;
        s2 += d * d;
    }
    return s2 / (x.size () - 1);
}

// Compute sample standard deviation
template<typename T>
double stdev (const T &x)
{
    return sqrt (var (x));
}

// Compute correlation
template<typename T>
double corr (const T &x, const T &y)
{
    assert (x.size () == y.size ());
    double s = 0.0;
    for (size_t i = 0; i < x.size (); ++i)
        s += x[i] * y[i];
    double ux = mean (x);
    double uy = mean (y);
    return (s - x.size () * ux * uy) / ((x.size () - 1) * stdev (x) * stdev (y));
}

} // namespace horny_toad

#endif // STATISTICS_H
