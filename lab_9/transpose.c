#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1024
static double A [ N ][ N ];
static double B [ N ][ N ];
// B will hold transpose of A
static inline double get_time_sec () {
    struct timespec ts ;
    clock_gettime (CLOCK_MONOTONIC, & ts ) ;
    return ts . tv_sec + ts . tv_nsec * 1e-9;
}

// Naive transpose
void transpose_naive() {
    for ( int i =0; i < N ; i ++) {
        for ( int j =0; j < N ; j ++) {
            B [j][i] = A [i][j];
        }
    }
}

// Blocked transpose - to be implemented by you
void transpose_blocked(int blockSize) {
    // e . g . , for i in steps of blockSize
    //              for j in steps of blockSize
    //                   transpose sub-block
    // hints : B [ j2 ][ i2 ] = A [ i2 ][ j2 ]
    for(int i=0; i<N; i+=blockSize){
        for(int j=0; j<N; j+=blockSize){
            for(int ii=i; ii<i+blockSize; ii++){
                for(int jj=j; jj<j+blockSize; jj++){
                    B[jj][ii] = A[ii][jj];
                }
            }
        }
    }
}

int main() {
    // init A
    for ( int i =0; i < N ; i ++) {
        for ( int j =0; j < N ; j ++) {
            A [i][j] = (double) (i+j);
            B [i][j] = 0.0;
        }
    }
    double start , end ;
    // naive
    start = get_time_sec () ;
    transpose_naive () ;
    end = get_time_sec () ;
    printf (" Naive transpose time                   : %f s \n" , end - start ) ;
    // clear B
    for ( int i =0; i < N ; i ++) {
        for ( int j =0; j < N ; j ++) {
            B [ i ][ j ] = 0.0;
        }   
    }
    // // blocked ( TODO : vary blockSize = 8 ,16 ,32 ,... ,64)
    int blockSize = 8;
    while(blockSize<=128){
        start = get_time_sec () ;
        transpose_blocked(blockSize);
        end = get_time_sec() ;
        printf (" Blocked transpose (blockSize=%03d) time : %f s \n" , blockSize , end- start ) ;
        blockSize *= 2;
    }
    return 0;
}