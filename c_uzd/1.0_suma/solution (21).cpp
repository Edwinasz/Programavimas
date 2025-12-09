#include <stdio.h>
#include <stdlib.h>

int suma(int n);

int main(){
    int n;
    scanf("%d", &n);

    printf("%d", suma(n));
    
    return 0;
}

int suma(int n){
    int *ptr = (int *)malloc(n * sizeof(int));
    if(ptr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
        sum += ptr[i];
    }

    free(ptr);
    return sum;
}