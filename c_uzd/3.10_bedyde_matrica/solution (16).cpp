#include <stdio.h>
#include <math.h>

void skaitymas(FILE *input, int a[100], int &n);

int main(){
    FILE *input, *output;
    input = fopen("duom.txt", "r");
    output = fopen("rez.txt", "w");

    int a[100];
    int n = 0;
  
    skaitymas(input, a, n);
    fclose(input);

    n = sqrt(n); // nes kvadratine matrica

    for(int i = 0; i < n*n; i++){
        if(i % n != 0) fprintf(output, " ");
        fprintf(output, "%d", a[i]);
        if((i+1) % n == 0){
            fprintf(output, "\n");
        }
    }
    return 0;
}

void skaitymas(FILE *input, int a[100], int &n){
  
    for (int i = 0; i < 100; i++){
        while(n < 100 && fscanf(input, "%d", &a[n]) == 1){
            n++;
        }
    }  

}