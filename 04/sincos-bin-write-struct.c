#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#   define M_PI 3.1415926535
#endif 

typedef struct entry {
    float angle;
    float sin2;
    float cos2;
} Entry;

int main() {
    FILE *fp = fopen("data.bin", "wb");
    if (fp == NULL) exit(1);

    for (int i = 0; i < 256; i++) {
        float a = 2. * M_PI * i / 256.;
        Entry entry = {
            .angle = a,
            .sin2 = pow(sin(a), 2),
            .cos2 = pow(cos(a), 2)
        };
        fwrite(&entry, sizeof(Entry), 1, fp);
    }
    fclose(fp);
}
