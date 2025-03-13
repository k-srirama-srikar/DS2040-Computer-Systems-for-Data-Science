#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    unsigned int sum = 0;

    // Summing up the elements in the array
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    // Printing the result
    printf("Sum: %d\n", sum);

    return 0;
}

