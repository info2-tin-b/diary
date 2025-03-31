#include <stdio.h>

size_t filesize(FILE* fp) {
    size_t pos = ftell(fp);
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, pos, SEEK_SET);
    return size;
}

int colors[] = {
    0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF, 0xFF00FF
};

int main() {
    FILE *fp = fopen("4x4wh.bmp", "rb+");
    if (fp == NULL) return 1;
    printf("Taille du fichier: %ld\n", 
        filesize(fp));
    fseek(fp, 0x36, SEEK_SET);
    for (int i = 0; i < 16; i++) {
        int v = colors[i % (sizeof(colors) / sizeof(colors[0]))];
        fwrite(&v, 3, 1, fp);
    }
    fclose(fp);
}