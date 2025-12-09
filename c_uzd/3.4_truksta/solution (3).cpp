#include <stdio.h>

int main() {
    
    FILE *iFile, *oFile;
    iFile = fopen("duom.txt", "r");
    oFile = fopen("rex.txt", "w");

    int n, sk;
    int sksuma = 0;
    int suma = 1; // nes yra -1

    fscanf(iFile, "%d", &n);
    for(int i = 1; i <= n; i++){
        sksuma += i;
        fscanf(iFile, "%d", &sk);
        suma += sk;
    }

    fprintf(oFile, "%d", sksuma - suma);
    return 0;
}