#include <stdio.h>

int pasukti(int n);

int main(){
    FILE *in, *out;
    in = fopen("input.txt", "r");
    // out = fopen("U1rez.txt", "w");

    int n;
    fscanf(in, "%d", &n);

    pasukti(n);

    return 0;
}

int pasukti(int n){
    printf("%d\n", n % 10);
    if(n > 10)
        pasukti(n / 10);  
       
}