#include <stdio.h>
#include <math.h>

void cords(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, FILE *output);

int main(){

    FILE *output;
    output = fopen("rez.txt", "w");

    float x1, x2, x3, x4, y1, y2, y3, y4;
    scanf("%f %f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    cords(x1, y1, x2, y2, x3, y3, x4, y4, output);

    return 0;
}


void cords(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, FILE *output){
    float p, S, a, b;
    a = sqrtf((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)); 
    b = sqrtf((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));

    p = (a+b) * 2;
    S = a * b;

    fprintf(output, "%.5f\n", S);
    fprintf(output, "%.5f\n", p);
}