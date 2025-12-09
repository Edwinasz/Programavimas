#include <stdio.h>
int suma(int a, int b);
int main()
{
    FILE *iFile, *oFile;
    iFile = fopen("duom.txt", "r");
    oFile = fopen("rez.txt", "w");

    int a, b, sum = 0;
    fscanf(iFile, "%d %d", &a, &b);
    sum = suma(a, b);
    fprintf(oFile, "%d", sum);
    return 0;
}

int suma(int a, int b){
    int sum = a + b;
    return sum;
}