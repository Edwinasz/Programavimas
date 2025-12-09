#include <stdio.h>
#include <stdbool.h>

bool isPrime(long long a){
    if(a < 2) return false;
    for(long long i = 2; i * i <= a; i++){
        if(a % i == 0) return false;
    }
    return true;
}

int main(){
    FILE *input, *output;
    input = fopen("11.in", "r");
    output = fopen("rez.txt", "w");

    long long a;
    scanf("%lld", &a);
    fprintf(output, "%d\n", isPrime(a) ? 1 : 0);

    fclose(input);
    fclose(output);
    return 0;
}