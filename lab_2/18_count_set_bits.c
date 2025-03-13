#include <stdio.h>
#include <stdint.h>

int count_set_bits(uint32_t x) {
    int count = 0;
    while (x) {
        count += (x & 1); // Increment count if the least significant bit is 1
        x >>= 1;           // Right shift the number to process the next bit
    }
    return count;
}

int main(void) {
    uint32_t num = 0xF0F0F0F0;  // Number to check for set bits
    int bits = count_set_bits(num);  // Count the set bits in num

    printf("Number = 0x%08X\n", num);  // Print the number in hex format
    printf("Set bits = %d\n", bits);  // Print the count of set bits

    return 0;
}
