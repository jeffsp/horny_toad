// Polar Utilities
//
// Copyright (C) 2004-2011
// Center for Perceptual Systems
// University of Texas at Austin
//
// contact: jeffsp@gmail.com

#ifndef POLAR_H
#define POLAR_H

#include <cmath>

namespace horny_toad
{

template<typename Ty>
inline void cart2pol (Ty x, Ty y, Ty &r, Ty &th)
{
    th = atan2 (y, x);
    r = sqrt (x * x + y * y);
}

template<typename Ty>
inline void pol2cart (Ty r, Ty th, Ty &x, Ty &y)
{
    x = r * cos (th);
    y = r * sin (th);
}

} // namespace horny_toad

#endif // POLAR_H
