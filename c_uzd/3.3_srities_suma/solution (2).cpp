#include <stdio.h>

int main() {
    
    FILE *iFile;
    iFile = fopen("doum.txt", "r");

    int n, m;
    int suma = 0;

    fscanf(iFile, "%d %d", &n, &m);
    
    int a[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fscanf(iFile, "%d", &a[i][j]);
            if(i == 0 || j == m - 1){
                suma += a[i][j];
            }
        }
    }

    printf("%d", suma);

    return 0;
}