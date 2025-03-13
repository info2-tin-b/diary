#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#   define M_PI 3.1415926535
#endif 

int main() {
    FILE *fp = fopen("data.bin", "rb");
    if (fp == NULL) exit(1);

    for (int i = 0; i < 256; i++) {
        float a, s, c;
        fread(&a, sizeof(float), 1, fp);
        fread(&s, sizeof(float), 1, fp);
        fread(&c, sizeof(float), 1, fp);

        printf("%g %g %g\n", a, s, c);
    }
    fclose(fp);
}