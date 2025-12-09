#include <stdio.h>

double apskritimas(long long a, double pi);

int main(){
    FILE *input, *output;
    input = fopen("in.txt", "r");
    output = fopen("rez.txt", "w");

    long long a;
    fscanf(input, "%lld", &a);
    double pi = 355 / 113.0;
    
    fprintf(output, "Įbrėžto plotas: %.2lf\n", apskritimas(a, pi));
    fprintf(output, "Apibrėžto plotas: %.2lf\n", apskritimas(a, pi) * 2.0);

    fclose(input);
    fclose(output);
    return 0;   
}

double apskritimas(long long a, double pi){
    double r = (double)a / 2.0;
    return pi * r * r;
}