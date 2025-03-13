#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 4000
static double A[N][N];

static inline double get_time_sec(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec*1e-9;
}

int main(){
    // intialize
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            A[i][j] = i+j;
        }
    }
    double start, end;
    double sum=0.0;

    // row major traversal
    //
    // start = get_time_sec();
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //        sum+= A[i][j];
    //     }
    // }
    // end=get_time_sec();
    // printf("Row-major time   : %f s, sum=%f\n", end-start, sum);

    //column major traversal
    
//     sum = 0.0;
    start = get_time_sec();
    for(int j=0; j<N;j++){
      for(int i=0; i<N; i++){
         sum+=A[i][j];
      }
    }
   end = get_time_sec();
   printf("Column-major time: %f s, sum=%f\n", end-start, sum);
   return 0;
}


