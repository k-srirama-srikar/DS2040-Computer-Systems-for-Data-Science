#include<stdio.h>

int do_stuff(int x, int y){
    return x+y;
}

int main(){
    int a;
    a = do_stuff(5, 10);
    printf("Result is %d\n",a);
    return 0;
}
