#include <stdio.h> 
#include <stdlib.h>

typedef struct entry {
    float angle;
    float sin2;
    float cos2;
} Entry;

int main() {
    FILE *fp = fopen("data.bin", "rb");
    if (fp == NULL) exit(1);

    fseek(fp, sizeof(Entry) * 100, SEEK_SET);

    Entry entry;
    fread(&entry, sizeof(entry), 1, fp);
    printf("Angle: %g\nSin2: %g\nCos2: %g\n", 
        entry.angle, entry.sin2, entry.cos2);
    fclose(fp);
}