#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000
int * arr ;
static inline double get_time_sec () {
    struct timespec ts ;
    clock_gettime ( CLOCK_MONOTONIC , & ts ) ;
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

int main () {
    arr = (int*)malloc(SIZE*sizeof(int)) ;
    if (!arr) {
        perror ("malloc");
        return 1;
    }
    // Initialize
    for ( int i = 0; i < SIZE ; i ++) {
        arr [i] = i ;
    }
    double start, end ;
    long long sum = 0;
    // Single pass
    start = get_time_sec () ;
    for ( int i = 0; i < SIZE ; i ++) {
        sum += arr [i];
    }
    end = get_time_sec () ;
    printf (" Single pass   : % f s , sum =% lld \n" , end - start , sum ) ;
    // Repeated pass (10 times )
    sum = 0;
    start = get_time_sec();
    for ( int repeat = 0; repeat < 10; repeat ++) {
        for ( int i = 0; i < SIZE ; i ++) {
            sum += arr [i];
        }
    }
    end = get_time_sec () ;
    printf (" Repeated pass : % f s , sum =% lld \n" , end - start , sum ) ;
    free(arr);
    return 0;
}
