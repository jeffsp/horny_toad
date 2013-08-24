/// @file mlr_lapack.h
/// @brief lapack version of multiple linear regression support
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-08-23

#ifndef MLR_LAPACK_H
#define MLR_LAPACK_H

#include "raster_utils.h"
#include <lapacke.h>

namespace horny_toad
{

    /// @brief multiple linear regression
    ///
    /// @tparam T matrix types
    /// @param y responses
    /// @param x predictors
    ///
    /// @return linear estimates of y=b*x
    template<typename T>
    T mlr_lapack (const T &y, const T &x)
    {
        assert (x.cols () <= x.rows ());
        assert (y.rows () == x.rows ());
        // result gets stored in b
        T b (y);
        // add a column of 1's to x on the left
        T xx (x.rows (), x.cols () + 1);
        for (size_t i = 0; i < x.rows (); ++i)
        {
            xx (i, 0) = 1;
            for (size_t j = 0; j < x.cols (); ++j)
            {
                xx (i, j + 1) = x (i, j);
            }
        }
        const size_t M = xx.rows ();
        const size_t N = xx.cols ();
        // solve it
        if (LAPACKE_dgels (LAPACK_ROW_MAJOR, 'N', M, N, 1, &xx[0], N, &b[0], 1) != 0)
            throw std::runtime_error ("LAPACK error: can't solve mlr");
        // copy result into matrix with correct dimensions
        T z (x.cols (), 1);
        for (size_t i = 0; i < x.cols (); ++i)
            z[i] = b[i + 1];
        return z;
    }

} // namespace horny_toad

#endif // MLR_LAPACK_H
