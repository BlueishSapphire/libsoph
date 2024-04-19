#ifndef SOPH_INT_H
#define SOPH_INT_H

#include <stdint.h>
#include <sys/types.h>

#ifdef __SIZEOF_INT128__
	typedef unsigned __int128 uint128_t;
	typedef signed __int128 int128_t;
#else
	typedef unsigned _BitInt(128) uint128_t;
	typedef signed _BitInt(128) int128_t;
#endif
typedef uint128_t u128;
typedef int128_t  i128;
typedef uint64_t  u64;
typedef int64_t   i64;
typedef uint32_t  u32;
typedef int32_t   i32;
typedef uint16_t  u16;
typedef int16_t   i16;
typedef uint8_t   u8;
typedef int8_t    i8;
typedef size_t    usize;
typedef ssize_t   isize;
typedef uintmax_t umax;
typedef intmax_t  imax;

#define __MAX_U(T) (~(T) 0)
#define __MIN_U(T) ((T) 0)
#define __MAX_I(T) (~(__MIN_I(T)))
#define __MIN_I(T) (((T) 1 << (sizeof(T) * CHAR_BIT - 1)))

// unsigned maximums
#define MAX_U8    __MAX_U(u8)
#define MAX_U16   __MAX_U(u16)
#define MAX_U32   __MAX_U(u32)
#define MAX_U64   __MAX_U(u64)
#define MAX_U128  __MAX_U(u128)
#define MAX_USIZE __MAX_U(usize)
#define MAX_UMAX  __MAX_U(umax)

// signed maximums
#define MAX_I8    __MAX_I(i8)
#define MAX_I16   __MAX_I(i16)
#define MAX_I32   __MAX_I(i32)
#define MAX_I64   __MAX_I(i64)
#define MAX_I128  __MAX_I(i128)
#define MAX_ISIZE __MAX_I(isize)
#define MAX_IMAX  __MAX_I(imax)

// unsigned minimums
#define MIN_U8    __MIN_U(u8)
#define MIN_U16   __MIN_U(u16)
#define MIN_U32   __MIN_U(u32)
#define MIN_U64   __MIN_U(u64)
#define MIN_U128  __MIN_U(u128)
#define MIN_USIZE __MIN_U(usize)
#define MIN_UMAX  __MIN_U(umax)

// signed minimums
#define MIN_I8    __MIN_I(i8)
#define MIN_I16   __MIN_I(i16)
#define MIN_I32   __MIN_I(i32)
#define MIN_I64   __MIN_I(i64)
#define MIN_I128  __MIN_I(i128)
#define MIN_ISIZE __MIN_I(isize)
#define MIN_IMAX  __MIN_I(imax)

#endif // SOPH_INT_H
