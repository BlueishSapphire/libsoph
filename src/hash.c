#include <soph/hash.h>

u32 fnv32(u8 *data, size_t size) {
    u32 h = FNV_32_BASIS;
    while (size--) {
        h ^= *data++;
        h *= FNV_32_PRIME;
    }
    return h;
}
u64 fnv64(u8 *data, size_t size) {
    u64 h = FNV_64_BASIS;
    while (size--) {
        h ^= *data++;
        h *= FNV_64_PRIME;
    }
    return h;
}

u32 sha1(u8 *data, size_t size);
u32 sha256(u8 *data, size_t size);
u32 md5(u8 *data, size_t size);
u32 siphash(u8 *data, size_t size);

