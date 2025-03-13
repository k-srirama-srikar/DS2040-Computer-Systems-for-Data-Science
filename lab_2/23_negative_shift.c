#include <stdio.h>
#include <stdint.h>

int main(void) {
    int32_t neg = -1; // Signed integer
    uint32_t uneg = (uint32_t)neg; // Unsigned integer with same bit pattern

    printf("neg (signed) = %d\n", neg);
    printf("uneg (unsigned) = %u\n", uneg);

    // Right shifting a signed negative
    int32_t shiftedNeg = neg >> 1; // Typically arithmetic shift
    printf("neg >> 1 = %d (0x%08X)\n", shiftedNeg, (uint32_t)shiftedNeg);

    // Right shifting the unsigned version (logical shift)
    uint32_t shiftedUNeg = uneg >> 1;
    printf("uneg >> 1 = %u (0x%08X)\n", shiftedUNeg, shiftedUNeg);

    return 0;
}
