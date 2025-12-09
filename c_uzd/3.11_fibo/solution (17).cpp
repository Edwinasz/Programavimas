#include <stdio.h>

int fibo(int n);

int main(){
    FILE *in, *out;
    in = fopen("11.in", "r");
    out = fopen("11.out", "w");

    int n;
    fscanf(in, "%d", &n);
    
    int f = fibo(n);
    fprintf(out, "%d", f);

    return 0;
}

int fibo(int n){
    if(n < 2)
        return n;
    
    return fibo(n - 1) + fibo(n - 2);  
}