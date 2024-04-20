#ifndef SOPH_HASH_H
#define SOPH_HASH_H

#include <soph/int.h>

typedef u32 (*hashfunc32_t)(u8 *data, size_t size);
typedef u64 (*hashfunc64_t)(u8 *data, size_t size);

#define FNV_32_PRIME ((u32) 0x01000193) /* 16777619 */
#define FNV_64_PRIME ((u64) 0x00000100000001b3) /* 1099511628211 */
#define FNV_32_BASIS ((u32) 0x811c9dc5) /* 2166136261 */
#define FNV_64_BASIS ((u64) 0xcbf29ce484222325) /* 14695981039346656037 */

u32 fnv32(u8 *data, size_t size);
u64 fnv64(u8 *data, size_t size);
u32 sha1(u8 *data, size_t size);
u32 sha256(u8 *data, size_t size);
u32 md5(u8 *data, size_t size);
u32 siphash(u8 *data, size_t size);

#endif // SOPH_HASH_H
