#include <stdio.h>
#include <stdint.h>

uint32_t rotate_left(uint32_t x, int n) {
    return (x << n) | (x >> (32 - n));
}

uint32_t rotate_right(uint32_t x, int n) {
    return (x >> n) | (x << (32 - n));
}

int main(void) {
    uint32_t val = 0xABCDEF12;

    printf("Original: 0x%08X\n", val);
    printf("Rotated L4: 0x%08X\n", rotate_left(val, 4));
    printf("Rotated R4: 0x%08X\n", rotate_right(val, 4));

    return 0;
}