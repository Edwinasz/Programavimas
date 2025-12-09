#include <stdio.h>

float min_maxvid(int a[], int n, int m);
void elemvid(int a[], int n, int m, FILE *output);

int main(){
    FILE *output;
    output = fopen("rez.xtx", "w");

    int n, m, suma = 0;
    scanf("%d %d", &n, &m);

    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    elemvid((int *)a, n, m, output);

    return 0;
}

float min_maxvid(int a[], int n, int m){
    int min = a[0];
    int max = a[0];
    for(int i = 1; i < n * m; i++){
        if(a[i] < min){
            min = a[i];
        }
        if(a[i] > max){
            max = a[i];
        }
    }
    return (float)(min + max) / 2;
}

void elemvid(int a[], int n, int m, FILE *output){
    float min_max_vid = min_maxvid(a, n, m);
    int suma = 0;
    float evid = 0.0;

    for(int i = 0; i < n * m; i++){
        suma += a[i];
    }

    evid = (float)suma / (n * m);
    if(evid > min_max_vid){
        fprintf(output, "TAIP");
    }
    else{
        fprintf(output, "NE");
    }
}