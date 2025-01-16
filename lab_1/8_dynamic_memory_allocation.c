#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));
    if(arr==NULL){
        printf("Memory allocation has failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
    }

    // Print values
    printf("Allocated array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Release the allocated memory
    return 0;

}