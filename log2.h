// Log Base 2
//
// Copyright (C) 2004-2011
// Center for Perceptual Systems
// University of Texas at Austin
//
// contact: jeffsp@gmail.com

#ifndef LOG2_H
#define LOG2_H

#include <cmath>

namespace horny_toad
{

/// @brief Log base 2
/// @return log base 2 of x
template<typename T>
inline T log2 (T x)
{
    const T LOG10_2 = log10 (2.0);
    return log10 (x) / LOG10_2;
}

} // namespace horny_toad

#endif // LOG2_H
