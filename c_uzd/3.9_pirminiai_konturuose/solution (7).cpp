#include <stdio.h>
#include <stdbool.h>

bool isPrime(long long a){
    if(a < 2) return false;
    if(a == 2) return true;
    if(a % 2 == 0) return false;
    for(long long i = 3; i * i <= a; i++){
        if(a % i == 0) return false;
    }
    return true;
}

int main(){
    FILE *input, *output;
    input = fopen("duom.txt", "r");
    output = fopen("rez.txt", "w");

    int n, m, count = 0;
    fscanf(input, "%d %d", &n, &m);

    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fscanf(input, "%d", &a[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i == 0 || i == n - 1 || j == 0 || j == m - 1)){
                if(isPrime(a[i][j]))
                    count++;
            }
        }
    }

    fprintf(output, "%d\n", count);
    return 0;
}