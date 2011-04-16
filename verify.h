// Verify that a statement is true at runtime
//
// Copyright (C) 2004-2011
// Center for Perceptual Systems
// University of Texas at Austin
//
// contact: jeffsp@gmail.com

#ifndef VERIFY_H
#define VERIFY_H

#include <sstream>
#include <stdexcept>

namespace horny_toad
{

/// @brief Support for VERIFY macro
inline void Verify (const char *e, const char *file, unsigned line)
{
    std::stringstream s;
    s << "verification failed in " << file << ", line " << line << ": " << e;
    throw std::runtime_error (s.str ());
}

/// @brief VERIFY that a statement is true, ignoring NDEBUG
#define VERIFY(e) (void)((e) || (Verify (#e, __FILE__, __LINE__), 0))

} // namespace horny_toad

#endif // VERIFY_H
