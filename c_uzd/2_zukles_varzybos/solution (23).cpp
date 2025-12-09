#include <stdio.h>

long long int a[6];

int main() {
    
    int n = 6;
    long long int suma = 0;
    int count = 0;

    
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        suma += a[i];
    }

    if(suma % 2 != 0){
        printf("Ne");
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(i < n - 2){
                    if(a[i] + a[j] + a[k] == suma / 2)
                        count++;
                    if(count >= 2){
                        printf("Taip");
                        return 0;
                    }
                }
            }
        }
    }

    printf("Ne");

    return 0;
}