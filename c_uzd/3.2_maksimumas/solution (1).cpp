#include <stdio.h>
int didziausias(int a[], int n);
int main()
{
    int n, did;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    did = didziausias(a, n);
    printf("%d", did);

    return 0;
}

int didziausias(int a[], int n){
    int did = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > did)
            did = a[i];
    }

    return did;
}