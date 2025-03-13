#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#   define M_PI 3.1415926535
#endif 

int main() {
    FILE *fp = fopen("data.bin", "wb");
    if (fp == NULL) exit(1);

    for (int i = 0; i < 256; i++) {
        float a = 2. * M_PI * i / 256.;
        float s = pow(sin(a), 2);
        float c = pow(cos(a), 2);

        // fprintf(fp, "%.2f %.2f %.2f\n", a, s, c);
        fwrite(&a, sizeof(float), 1, fp);
        fwrite(&s, sizeof(float), 1, fp);
        fwrite(&c, sizeof(float), 1, fp);
    }
    fclose(fp);
}