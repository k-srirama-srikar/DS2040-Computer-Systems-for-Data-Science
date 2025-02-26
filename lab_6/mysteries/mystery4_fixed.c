#include<stdio.h>
#include<stdlib.h>

void fillArray(int *arr, int size, int value){
    for(int i=0; i<size; i++){
        arr[i]=value;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

int main(){
    int *arr = (int*) malloc(20);
    if(arr!=0) return 1;
    fillArray(arr, 5, 7);
    for(int i=0; i<=4;i++){
        printf("%d\n", arr[i]);
    }
    putchar('\n');
    free(arr);
    return 0;
}
