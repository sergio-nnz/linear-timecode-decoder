#pragma once

#include <cstdint>

struct DecodeInfo {
    uint32_t mask;
    int shift;
};

class TimeDecoder {
private:
    static const uint32_t unit_mask = 0xf;
    static const uint32_t tens_to_twenty_mask = 0x300;
    static const uint32_t tens_to_forty_mask = 0x700;
public:
    static int GetFrames(const unsigned short &value);
    static int GetSeconds(const unsigned short &value);
    static int GetMinutes(const unsigned short &value);
    static int GetHours(const unsigned short &value);
private:
    static unsigned int GetMaskedInt(const unsigned short &value, const uint32_t mask, const int shift);
    static int DecodeValue(const unsigned short &value, const DecodeInfo &units, const DecodeInfo &tens);
};
