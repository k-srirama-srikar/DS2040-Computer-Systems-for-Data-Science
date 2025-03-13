#include <stdio.h>
#include <stdint.h>

int main(void) {
    __uint32_t val = 0x12345678;      // 32-bit value
    unsigned char *ptr = (unsigned char *)&val; // Pointer to the first byte of the value

    printf("val = 0x%08X\n", val); // Print the full 32-bit value
    printf("Byte 0: 0x%02X\n", ptr[0]); // Print byte 0
    printf("Byte 1: 0x%02X\n", ptr[1]); // Print byte 1
    printf("Byte 2: 0x%02X\n", ptr[2]); // Print byte 2
    printf("Byte 3: 0x%02X\n", ptr[3]); // Print byte 3

    return 0;
}
