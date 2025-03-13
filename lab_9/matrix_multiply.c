#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 512
#define BLOCK 32

static double A[N][N], B[N][N], C[N][N];

static inline double get_time_sec(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec*1e-9;
}

void matmul_naive(){
    for(int i=0; i<N;i++){
        for(int j=0; j<N; j++){
            double sum = 0.0;
            for(int k=0; k<N; k++){
                sum += A[i][k]*B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void matmul_block(){
    for(int i=0;i<N;i+=BLOCK){
        for(int j=0;j<N;j+=BLOCK){
            for(int k=0;k<N;k+=BLOCK){
                for(int ii=i;ii<i+BLOCK;ii++){
                    for(int jj=j;jj<j+BLOCK;jj++){
                        double sum = 0.0;
                        for(int kk=k;kk<k+BLOCK;kk++){
                            C[ii][jj] += A[ii][kk]*B[kk][jj];
                        }
                        C[ii][jj] = sum;
                    }
                }
            }
        }
    }
}

int main(){
    // initializing A and B
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            A[i][j] = i+j;
            B[i][j] = i-j;
            C[i][j] = 0.0;
        }
    }

    double start, end;

    // naive matrix multiplication
    start = get_time_sec();
    matmul_naive();
    end = get_time_sec();
    printf("Naive matrix multiplication time    : %f s\n", end-start);

    // //reinitializing C
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         C[i][j] = 0.0;
    //     }
    // }

    // block matrix multiplication
    // start = get_time_sec();
    // matmul_block();
    // end = get_time_sec();
    // printf("Block matrix multiplication time    : %f s\n", end-start);
    return 0;
}
