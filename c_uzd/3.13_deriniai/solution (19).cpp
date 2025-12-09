#include <stdio.h>

int deriniai(int k, int n);

int main(){
    FILE *in, *out;
    in = fopen("duom.txt", "r");
    out = fopen("U1rez.txt", "w");

    int k, n;
    fscanf(in, "%d %d", &k, &n);
    fprintf(out, "%d", deriniai(k, n));

    return 0;
}


int deriniai(int k, int n){
    if(k == 0 || k == n)
        return 1;
    else
        return deriniai(k - 1, n - 1) + deriniai(k, n - 1);
    
}