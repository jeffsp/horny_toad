/// @file mlr.h
/// @brief multiple linear regression support
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-06-13

#ifndef MLR_H
#define MLR_H

#include "raster_utils.h"
#include <stdexcept>

namespace horny_toad
{

    /// @brief helper function
    template<typename T>
    T matrix_multiply (const T &a, const T &b)
    {
        assert (a.cols () == b.rows ());
        const size_t N = a.rows ();
        const size_t M = a.cols ();
        const size_t P = b.cols ();
        T y (a.rows (), b.cols ());
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < P; ++j)
                for (size_t k = 0; k < M; ++k)
                    y (i, j) += a (i, k) * b (k, j);
        return y;
    }
    /// @brief multiple linear regression
    ///
    /// @tparam T matrix types
    /// @param y responses
    /// @param x predictors
    ///
    /// @return linear estimates of y=b*x
    template<typename T>
    T mlr (const T &y, const T &x)
    {
        // b = (x^T * x)^-1 * x^T * y
        T xt = transpose (x);
        T tmp = matrix_multiply (xt, x);
        tmp = invert (tmp);
        tmp = matrix_multiply (tmp, xt);
        tmp = matrix_multiply (tmp, y);
        return tmp;
    }

} // namespace horny_toad

#endif // MLR_H
