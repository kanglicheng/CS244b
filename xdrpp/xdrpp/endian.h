// -*- C++ -*-
// Warning: Make sure to edit xdrc_endian.h.in, not xdrc_endian.h.

/** \file endian.h Endianness of build machine. */

#ifndef _XDRC_ENDIAN_H_HEADER_INCLUDED_
#define _XDRC_ENDIAN_H_HEADER_INCLUDED_ 1

#include <cstdint>

namespace xdr {

#ifndef WORDS_BIGENDIAN
//! Default value set on build machine, but can be overridden (by
//! defining WORDS_BIGENDIAN to 0 or 1) in case of cross-compilation.
#define WORDS_BIGENDIAN 0
#endif // !WORDS_BIGENDIAN

//! True on big endian machines, false on little endian machines.
#if WORDS_BIGENDIAN
constexpr bool is_big_endian = true;
#else // !WORDS_BIGENDIAN
constexpr bool is_big_endian = false;
#endif // !WORDS_BIGENDIAN

//! Byteswap 32-bit number.
constexpr std::uint32_t
swap32(std::uint32_t v)
{
  return v << 24 | (v & 0xff00) << 8 | (v >> 8 & 0xff00) | v >> 24;
}

//! Byteswap 64-bit number.
constexpr std::uint64_t
swap64(std::uint64_t v)
{
  return std::uint64_t(swap32(v))<<32 | swap32(v>>32);
}

//! Byteswap 32-bit value only on little-endian machines, identity
//! function on big-endian machines.
constexpr std::uint32_t
swap32le(std::uint32_t v)
{
  return xdr::is_big_endian ? v : swap32(v);
}

//! Byteswap 32-bit value only on big-endian machines
constexpr std::uint32_t
swap32be(std::uint32_t v)
{
  return xdr::is_big_endian ? swap32(v) : v;
}

//! Byteswap 64-bit value only on little-endian machines
constexpr std::uint64_t
swap64le(std::uint64_t v)
{
  return xdr::is_big_endian ? v : swap64(v);
}

//! Byteswap 64-bit value only on big-endian machines
constexpr std::uint64_t
swap64be(std::uint64_t v)
{
  return xdr::is_big_endian ? swap64(v) : v;
}

}

#endif // !_XDRC_ENDIAN_H_HEADER_INCLUDED_
