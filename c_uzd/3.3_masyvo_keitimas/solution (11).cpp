#include <stdio.h>

void mat_keitimas(int n, int m, int a[]);

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    mat_keitimas(n, m, &a[0][0]);

    return 0;
}

void mat_keitimas(int n, int m, int a[]){
    int suma = 0, count = 1;
    for(int i = 0; i < n * m; i++){
        suma += a[i];
    }

    float vidurkis = (float)suma / (n * m);

    int apt = a[(n-1) * m];
    for(int i = 0; i < n * m; i++){
        if(a[i] < vidurkis){
            a[i] = apt * 2;
        }
        printf("%d", a[i]);
        if(count % m == 0){
            printf("\n");
            count = 0;
        } else {
            printf(" ");
        }
        count++;
    }

}