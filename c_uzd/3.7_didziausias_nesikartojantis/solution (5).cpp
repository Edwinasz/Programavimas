#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int max = -10000000;     
    int second;              

    for(int i = 0; i < n; i++){
        second = 0; 

        for(int j = 0; j < n; j++){
            if(a[i] == a[j])
                second++;
        }

        if(second == 1 && a[i] > max){
            max = a[i];
        }
    }

    if(max == -10000000)
        printf("NO");
    else
        printf("%d", max);

    return 0;
}