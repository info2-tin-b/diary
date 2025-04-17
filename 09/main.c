#include "bmp.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
 
    FILE *fp = fopen("red.bmp", "rb");
    fseek(fp, 0, SEEK_END);
    const size_t size = ftell(fp);
    printf("Taille fichier %ld 0x%lx\n", size, size);
    fseek(fp, 0, SEEK_SET);

    BMP* image = (BMP*)malloc(size);
    printf("Lu %ld\n", fread(image, 1, size, fp));

    printf("Taille image: %dx%d (w x h)\n", image->info.width, image->info.height);
    
    image->data[3] = 0x12;
    image->data[4] = 0x34;
    image->data[5] = 0x56; 

    Pixel24Bits* data = (Pixel24Bits*)image->data;
    data[5].blue = 0x42;

    FILE* fo = fopen("output.bmp", "wb");
    fwrite(image, 1, size, fo);
    fclose(fo);
    
    free(image);
    fclose(fp);
}