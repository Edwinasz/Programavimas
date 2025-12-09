#include <stdio.h>
    #include <stdlib.h>

    double vidurkis(int n, FILE *in);

    int main(){
        FILE *in;
        in = fopen("triz.xtx", "r");


        int n;
        fscanf(in, "%d", &n);

        double rez = vidurkis(n, in);
        printf("%.2lf\n", rez);
        
        return 0;
    }

    double vidurkis(int n, FILE *in){
        int *ptr = (int *)malloc(n * sizeof(int));
        if(ptr == NULL){
            printf("Memory allocation failed\n");
            return 1;
        }

        double vid = 0.0;
        int count = 0;
        for(int i = 0; i < n; i++){
            fscanf(in, "%d", &ptr[i]);
            if(ptr[i] < 100 || ptr[i] == 666 || ptr[i] > 999){
                vid += ptr[i];
                count++;
            }
        }

        if(count == 0){
            free(ptr);
            printf("NO");
            exit(0);
        }

        free(ptr);
        return (double)vid / count;
    }