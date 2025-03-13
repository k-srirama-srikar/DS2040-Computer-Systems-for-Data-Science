#include <stdio.h>
#include <stdint.h>

int main(void) {
    int16_t smallNum = -12345;
    int32_t largeNum = smallNum;

    printf("16-bit smallNum = %d\n", smallNum);
    printf("32-bit largeNum (extended) = %d\n", largeNum);

    return 0;
}
