#include <stdio.h>
#include <stdint.h>

int main(void) {
    int32_t s = -42;  // signed 32-bit integer (two's complement representation)
    uint32_t u = (uint32_t)s;  // reinterpret bits of signed integer as unsigned integer

    // Printing both signed and unsigned values
    printf("Signed s = %d\n", s);  // Prints signed value of s (-42)
    printf("Unsigned u = %u\n", u);  // Prints unsigned interpretation of the bits of s

    // Checking the sign bit manually (assuming 32-bit two's complement)
    int sign_bit = (s >> 31) & 1;  // Right shift s by 31 bits and check the most significant bit
    printf("Sign bit of s: %d\n", sign_bit);  // Prints the sign bit (1 if negative, 0 if positive)

    return 0;
}
