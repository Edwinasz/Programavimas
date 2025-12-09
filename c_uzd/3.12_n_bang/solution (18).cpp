#include <stdio.h>

long long fact(int n);

int main(){
    FILE *in, *out;
    in = fopen("13.txt", "r");
    out = fopen("13.out", "w");

    int n;
    fscanf(in, "%d", &n);
    
    long long f = fact(n);
    fprintf(out, "%lld", f);

    return 0;
}

long long fact(int n){
    if(n <= 2)
        return n;
    else
        return n * fact(n - 2);
}