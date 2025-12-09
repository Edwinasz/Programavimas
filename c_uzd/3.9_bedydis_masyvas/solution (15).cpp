#include <stdio.h>

void skaitymas(FILE *input, int a[], int &sk);
void min_max(int a[], int sk, int &min, int &max);

int main(){
    FILE *input;
    input = fopen("duom.txt", "r");

    int a[10];
    int sk = 0;
    

    skaitymas(input, a, sk);
    fclose(input);
    
    int min, max;
    min_max(a, sk, min, max);
    printf("Minimumas yra %d\n", min);
    printf("Maksimumas yra %d\n", max);
    return 0;
}

void skaitymas(FILE *input, int a[], int &sk){
    for(int i = 0; i < 10; i++){
        while (sk < 10 && fscanf(input, "%d", &a[sk]) == 1) {
            sk++;
        }
    }
}

void min_max(int a[], int sk, int &min, int &max){
    min = a[0];
    max = a[0];
    for(int i = 1; i < sk; i++){
        if(a[i] < min){
            min = a[i];
        }
        if(a[i] > max){
            max = a[i];
        }
    }
}