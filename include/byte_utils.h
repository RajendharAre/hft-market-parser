#pragma once

#include <cstdint>

inline uint16_t be16(uint16_t value)
{
    return (value >> 8) |
           (value << 8);
}

inline uint32_t be32(uint32_t value)
{
    return ((value & 0x000000FFu) << 24) |
           ((value & 0x0000FF00u) << 8)  |
           ((value & 0x00FF0000u) >> 8)  |
           ((value & 0xFF000000u) >> 24);
}

inline uint64_t be48(const uint8_t bytes[6])
{
    return
        (static_cast<uint64_t>(bytes[0]) << 40) |
        (static_cast<uint64_t>(bytes[1]) << 32) |
        (static_cast<uint64_t>(bytes[2]) << 24) |
        (static_cast<uint64_t>(bytes[3]) << 16) |
        (static_cast<uint64_t>(bytes[4]) << 8)  |
        (static_cast<uint64_t>(bytes[5]));
}

inline uint64_t be64(uint64_t value)
{
    return ((value & 0x00000000000000FFULL) << 56) |
           ((value & 0x000000000000FF00ULL) << 40) |
           ((value & 0x0000000000FF0000ULL) << 24) |
           ((value & 0x00000000FF000000ULL) << 8)  |
           ((value & 0x000000FF00000000ULL) >> 8)  |
           ((value & 0x0000FF0000000000ULL) >> 24) |
           ((value & 0x00FF000000000000ULL) >> 40) |
           ((value & 0xFF00000000000000ULL) >> 56);
}
