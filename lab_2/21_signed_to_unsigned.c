#include <stdio.h>
#include <stdint.h>
// #include <cstdint>

int main(void) {
    __int32_t negativeVal = -12345;
    __uint32_t convertedVal = (__uint32_t)negativeVal;
    printf("signed int: %d\n", negativeVal);    
    printf("unsigned int: %u\n", convertedVal);
    printf("as hex: 0x%08X\n", convertedVal);
    return 0;
}