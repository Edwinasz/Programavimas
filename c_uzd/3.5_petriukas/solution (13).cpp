#include <stdio.h>

int extra(int a, int b, int arr[], int brr[]);

int main(){

    int a, b;
    scanf("%d", &a);
    int arr[a];

    for(int i = 0; i < a; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &b);
    int brr[b];

    for(int i = 0; i < b; i++){
        scanf("%d", &brr[i]);
    }

    printf("%d", extra(a, b, arr, brr));
    return 0;   
}

int extra(int a, int b, int arr[], int brr[]){
    int sum_a = 0, sum_b = 0;
    for(int i = 0; i < a; i++){
        sum_a += arr[i];
    }
    for(int i = 0; i < b; i++){
        sum_b += brr[i];
    }
    
    if(a > b){
        return sum_a - sum_b;
    } else {
        return sum_b - sum_a;
    }

}