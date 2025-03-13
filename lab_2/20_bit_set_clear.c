#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint32_t x = 0xFF00FF00;  // Initial value in hexadecimal
    printf("Original x = 0x%08X\n", x);  // Print the original value of x

    // Clear the lower 8 bits (bits 0-7)
    uint32_t mask_clear = 0xFFFFFF00; // Mask to clear lower 8 bits: 11111111 11111111 11111111 00000000
    x = x & mask_clear;  // Apply the mask using bitwise AND to clear the lower 8 bits
    printf("After clearing lower 8 bits = 0x%08X\n", x);  // Print the result after clearing

    // Set bits 8 to 15 (the 8th to 15th bits)
    uint32_t mask_set = 0x0000FF00;  // Mask to set bits 8-15: 00000000 00000000 11111111 00000000
    x = x | mask_set;  // Apply the mask using bitwise OR to set bits 8-15
    printf("After setting bits 8-15 = 0x%08X\n", x);  // Print the result after setting

    return 0;
}
