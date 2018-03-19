#include <stdint.h>

uint32_t extract_last_bits(uint32_t bits, uint32_t extracted_bits, int num_of_bits)
{
    //TODO -- Add error handling for when num_of_bits is > bits
    unsigned bitmask;
    bitmask = (1 << num_of_bits) - 1;
    extracted_bits = bits & bitmask;
    return extracted_bits;
}