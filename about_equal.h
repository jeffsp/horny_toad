// About Equal
//
// Copyright (C) 2004-2011
// Center for Perceptual Systems
// University of Texas at Austin
//
// contact: jeffsp@gmail.com

#ifndef ABOUT_EQUAL_H
#define ABOUT_EQUAL_H

#include <cmath>

namespace horny_toad
{

/// @brief Return true if two values are about equal
template<typename Ty>
inline bool about_equal (Ty a, Ty b, double PREC = 0.001)
{
    return round (a * 1.0 / PREC) == round (b * 1.0 / PREC);
}

} // namespace horny_toad

#endif // ABOUT_EQUAL_H
