#include <stdio.h>

void skaitymas(FILE *input, int arr[][100], int n);
void pasukimas(int arr[][100], int n);
void rasymas(FILE *output, int arr[][100], int n);

int main(){
    FILE *input, *output;
    input = fopen("15.txt", "r");
    output = fopen("15rez.txt", "w");

    int n, k;
    fscanf(input, "%d %d", &n, &k);

    k = k % 4;

    int arr[100][100];
    skaitymas(input, arr, n);
    
    for(int i = 0; i < k; i++)
        pasukimas(arr, n);
    
    rasymas(output, arr, n);

    fclose(input);
    fclose(output);
    return 0;
}

void skaitymas(FILE *input, int arr[][100], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            fscanf(input, "%d", &arr[i][j]);
    }
}

void pasukimas(int arr[][100], int n){
    int temp[100][100];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            temp[i][j] = arr[i][j];
        }

    int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            arr[i][index++] = temp[j][i]; 
        }
            index = 0;
    }
}

void rasymas(FILE *output, int arr[][100], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            fprintf(output, "%d ", arr[i][j]);
        fprintf(output, "\n");
    }
}