
#include "timedecoder.h"

int TimeDecoder::GetFrames(const unsigned short &value) {
    const DecodeInfo unit = {unit_mask, 0};
    const DecodeInfo tens = {tens_to_twenty_mask, 8};

    const int result = DecodeValue(value, unit, tens);

    return result;
}

int TimeDecoder::GetSeconds(const unsigned short &value) {
    const DecodeInfo unit = {unit_mask, 0};
    const DecodeInfo tens = {tens_to_forty_mask, 8};

    const int result = DecodeValue(value, unit, tens);

    return result;
}

int TimeDecoder::GetMinutes(const unsigned short &value) {
    const DecodeInfo unit = {unit_mask, 0};
    const DecodeInfo tens = {tens_to_forty_mask, 8};

    const int result = DecodeValue(value, unit, tens);

    return result;
}

int TimeDecoder::GetHours(const unsigned short &value) {
    const DecodeInfo unit = {unit_mask, 0};
    const DecodeInfo tens = {tens_to_twenty_mask, 8};

    const int result = DecodeValue(value, unit, tens);

    return result;
}

unsigned int TimeDecoder::GetMaskedInt(const unsigned short &value, const uint32_t mask, const int shift) {
    return (value & mask) >> shift;
}

int TimeDecoder::DecodeValue(const unsigned short &value, const DecodeInfo &units, const DecodeInfo &tens) {
    const auto unit_value = GetMaskedInt(value, units.mask, units.shift);
    const auto tens_value = GetMaskedInt(value, tens.mask, tens.shift) * 10;
    const int result = unit_value + tens_value;
    return result;
}
