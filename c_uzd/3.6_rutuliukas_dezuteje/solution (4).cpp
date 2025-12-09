#include <stdio.h>

int main() {
    
    FILE *iFile;
    iFile = fopen("skola.txt", "r");
    
    int A, B, C;
    fscanf(iFile, "%d %d %d", &A, &B, &C);

    int min = A;
    if(B <= A && B <= C)
        min = B;
    if(C <= A && C <= B)
        min = C;

    double r = (double)min / 2; 
    double pi = 355.0/113.0;
    double rV = (4.0/3.0) * pi * r * r * r;

    printf("%.2lf", rV);
    
    return 0;
}