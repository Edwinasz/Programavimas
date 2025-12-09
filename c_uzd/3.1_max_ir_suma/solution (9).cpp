#include <stdio.h>

void max_sum(int a[], int n, FILE *output);

int main(){
    FILE *input, *output;
    input = fopen("duom.txt", "r");
    output = fopen("rez.txt", "w");

    int n;
    fscanf(input, "%d", &n);

    int a[n];
    for(int i = 0; i < n; i++){
        fscanf(input, "%d", &a[i]);
    }

    max_sum(a, n, output);
    fclose(input);
    fclose(output);

    return 0;   
}

void max_sum(int a[], int n, FILE *output){
    int maximum = a[0];
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > maximum)
            maximum = a[i];
        sum += a[i];
    }

    fprintf(output, "Maksimumas yra %d\n", maximum);
    fprintf(output, "Suma yra %d\n", sum);
}