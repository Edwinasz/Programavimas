#include <stdio.h>
#include <math.h>

int find(int a[], int n);

int main(){
    int n, sk;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    sk = find(a, n);

    if(sk == 1) printf("No");
    else printf("%d", sk);

    return 0;
}

int find(int a[], int n){
    int max = -9999999;
    for(int i = 0; i < n; i++){ 
        int sk = (int)sqrtf(a[i]);
        if (sk * sk != a[i]){
            if(a[i] > max){
                max = a[i];
            } 
        }
    }

    if(max != -9999999) return max;
    return 1; 
}