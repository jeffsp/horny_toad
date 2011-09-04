// Bicubic Interpolation
//
// This came straight out of http://en.wikipedia.org/wiki/Bicubic_interpolation
//
// Copyright (C) 2004-2011
// Center for Perceptual Systems
// University of Texas at Austin
//
// contact: jeffsp@gmail.com

#ifndef BICUBIC_H
#define BICUBIC_H

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

namespace horny_toad
{


/// @brief Use finite differences to determine df/dx of f(x,y)
///
/// @tparam R return type
/// @tparam T type of f(x,y)
/// @param p f(x,y)
///
/// @return derivatives evaluated at each point of f(x,y)
template<typename R,typename T>
R fxy_dx (const T &p)
{
    R df (p.rows (), p.cols ());
    for (size_t i = 0; i + 2 < p.rows (); ++i)
        for (size_t j = 0; j + 2 < p.cols (); ++j)
            df (i + 1, j + 1) = (static_cast<typename R::value_type> (p (i + 1, j + 2))
                - static_cast<typename R::value_type> (p (i + 1, j + 0))) / 2.0;
    return df;
}

/// @brief Use finite differences to determine df/dy of f(x,y)
///
/// @tparam R return type
/// @tparam T type of f(x,y)
/// @param p f(x,y)
///
/// @return derivatives evaluated at each point of f(x,y)
template<typename R,typename T>
R fxy_dy (const T &p)
{
    R df (p.rows (), p.cols ());
    for (size_t i = 0; i + 2 < p.rows (); ++i)
        for (size_t j = 0; j + 2 < p.cols (); ++j)
            df (i + 1, j + 1) = (static_cast<typename R::value_type> (p (i + 2, j + 1))
                - static_cast<typename R::value_type> (p (i + 0, j + 1))) / 2.0;
    return df;
}

/// @brief Use finite differences to determine df/dxy of f(x,y)
///
/// @tparam R return type
/// @tparam T type of f(x,y)
/// @param p f(x,y)
///
/// @return cross derivatives evaluated at each point of f(x,y)
template<typename R,typename T>
R fxy_dxy (const T &p)
{
    R df (p.rows (), p.cols ());
    for (size_t i = 0; i + 2 < p.rows (); ++i)
        for (size_t j = 0; j + 2 < p.cols (); ++j)
            df (i + 1, j + 1) = (static_cast<typename R::value_type> (p (i + 2, j + 2))
                - static_cast<typename R::value_type> (p (i + 2, j + 0))
                - static_cast<typename R::value_type> (p (i + 0, j + 2))
                + static_cast<typename R::value_type> (p (i + 0, j + 0))) / 4.0;
    return df;
}

/// @brief p(x,y)=sum(i=0,3)[sum(j=0,3)[c(i,j)*x^i*y^j]]
///
/// @tparam T coordinate type
/// @tparam U coefficient type
/// @param x x coordinate
/// @param y y coordinate
/// @param c coefficients
///
/// @return surface value evaluated at x, y
template<typename T,typename U>
typename U::value_type surface (T x, T y, const U &c)
{
    assert (c.size () == 16);

    typename U::value_type sum = 0.0;
    for (size_t i = 0; i < 4; ++i)
        for (size_t j = 0; j < 4; ++j)
            sum += c[j * 4 + i] * std::pow (x, i) * std::pow (y, j);
    return sum;
}

/// @brief solve for c in x=Ac
///
/// @tparam T known function values type
/// @param x known function values
///
/// @return the coefficients
template<typename T>
T get_coeffs (const T &x)
{
    const typename T::value_type A_inverse[256] = {
         1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        -3,  3,  0,  0, -2, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         2, -2,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0, -3,  3,  0,  0, -2, -1,  0,  0,
         0,  0,  0,  0,  0,  0,  0,  0,  2, -2,  0,  0,  1,  1,  0,  0,
        -3,  0,  3,  0,  0,  0,  0,  0, -2,  0, -1,  0,  0,  0,  0,  0,
         0,  0,  0,  0, -3,  0,  3,  0,  0,  0,  0,  0, -2,  0, -1,  0,
         9, -9, -9,  9,  6,  3, -6, -3,  6, -6,  3, -3,  4,  2,  2,  1,
        -6,  6,  6, -6, -3, -3,  3,  3, -4,  4, -2,  2, -2, -2, -1, -1,
         2,  0, -2,  0,  0,  0,  0,  0,  1,  0,  1,  0,  0,  0,  0,  0,
         0,  0,  0,  0,  2,  0, -2,  0,  0,  0,  0,  0,  1,  0,  1,  0,
        -6,  6,  6, -6, -4, -2,  4,  2, -3,  3, -3,  3, -2, -1, -2, -1,
         4, -4, -4,  4,  2,  2, -2, -2,  2, -2,  2, -2,  1,  1,  1,  1
    };
    assert (x.size () == 16);
    T c (x.size ());
    for (size_t i = 0; i < 16; ++i)
    {
        for (size_t j = 0; j < 16; ++j)
        {
            size_t index = i * 16 + j;
            assert (index < 256);
            c[i] += A_inverse[index] * x[j];
        }
    }
    return c;
}

template<typename T,typename U>
typename U::value_type bicubic_interp (const T &p, const U &dx, const U &dy, const U &dxy, double x, double y)
{
    assert (p.rows () == dx.rows ());
    assert (p.rows () == dy.rows ());
    assert (p.rows () == dxy.rows ());
    assert (p.cols () == dx.cols ());
    assert (p.cols () == dy.cols ());
    assert (p.cols () == dxy.cols ());
    // how many pixels in p are above/left the point x,y?
    const unsigned above = y + 0.5;
    const unsigned left = x + 0.5;
    // if we are too near the image's edges, we can't interpolate
    if (above < 2)
        return 0;
    if (left < 2)
        return 0;
    if (above + 2 > p.rows ())
        return 0;
    if (left + 2 > p.cols ())
        return 0;
    // get the boundary indexes of p
    const unsigned i1 = above - 1;
    const unsigned j1 = left - 1;
    const unsigned i2 = i1 + 1;
    const unsigned j2 = j1 + 1;
    std::clog << i1 << " " << j1 << " " << i2 << " " << j2 << std::endl;
    // get known function values of the linear equation: pixel values and three
    // derivatives at all four corners
    std::vector<typename U::value_type> d (16);
    d[0] = p (i1, j1);
    d[1] = p (i1, j2);
    d[2] = p (i2, j1);
    d[3] = p (i2, j2);
    d[4] = dx (i1, j1);
    d[5] = dx (i1, j2);
    d[6] = dx (i2, j1);
    d[7] = dx (i2, j2);
    d[8] = dy (i1, j1);
    d[9] = dy (i1, j2);
    d[10] = dy (i2, j1);
    d[11] = dy (i2, j2);
    d[12] = dxy (i1, j1);
    d[13] = dxy (i1, j2);
    d[14] = dxy (i2, j1);
    d[15] = dxy (i2, j2);
    // solve for the coefficients
    std::vector<typename U::value_type> c = get_coeffs (d);
    // evaluate at the point
    typename U::value_type v = surface (fmod (x, 1.0), fmod (y, 1.0), c);
    return v;
}

template<typename T,typename U>
void bicubic_interp (const T &p, U &q)
{
    // compute derivatives at each point of p
    U dx = fxy_dx<U> (p);
    U dy = fxy_dy<U> (p);
    U dxy = fxy_dxy<U> (p);
    const double xscale = static_cast<double> (p.cols ()) / q.cols ();
    const double yscale = static_cast<double> (p.rows ()) / q.rows ();
    // for each point in q
    for (size_t i = 0; i < q.rows (); ++i)
    {
        for (size_t j = 0; j < q.cols (); ++j)
        {
            // where does the center of the pixel align with pixels in p?
            double x = (j + 0.5) * xscale;
            double y = (i + 0.5) * yscale;
            // interpolate the point
            q (i, j) = bicubic_interp (p, dx, dy, dxy, x, y);
            if (i == 3 && j == 3)
            {
                std::clog << i << " " << j << std::endl;
                std::clog << x << " " << y << std::endl;
                std::clog << q (i, j) << std::endl;
            }
        }
    }
}

} // namespace horny_toad

#endif // BICUBIC_H
