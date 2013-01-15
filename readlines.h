/// @file readlines.h
/// @brief readlines
/// @author Jeff Perry <jeffsp@gmail.com>
/// @version 1.0
/// @date 2013-01-15

#ifndef READLINES_H
#define READLINES_H

#include <fstream>
#include <vector>
#include <stdexcept>

namespace horny_toad
{

/// @brief read newline delimited fields from an input stream
///
/// @tparam T type of fields to extract
/// @param s the input stream
///
/// @return vector of Ts containing the fields
template<typename T>
std::vector<T> readlines (std::istream &s)
{
    std::vector<T> lines;
    T l;
    for (;;) // ever
    {
        s >> l;
        if (s)
            lines.push_back (l);
        else
            break;
    }
    return lines;
}

/// @brief read lines from a file
///
/// @param f the file
///
/// @return vector of strings containing the lines
template<typename T>
std::vector<T> readlines (const char *fn)
{
    std::ifstream s (fn);
    if (!s)
        throw std::runtime_error ("could not open file");
    return readlines<T> (s);
}

} // namespace horny_toad

#endif // READLINES_H
