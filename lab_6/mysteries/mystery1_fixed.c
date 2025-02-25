#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello!";
    printf("Original string: %s\n", str);
    char *p = str+3;  // Move pointer to point to the 'l' in "lo!"
    printf("Before writing: %s\n", p);
    *(p + 2) = 'X';  // Replace '!' with 'X'
    printf("After writing: %s\n", p);
    return 0;
}

