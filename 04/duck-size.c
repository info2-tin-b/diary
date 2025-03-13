#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1) // Assurer l'alignement des structures comme dans le fichier BMP

typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;

#pragma pack(pop)

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <fichier BMP>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Erreur ouverture fichier");
        return 1;
    }

    BMPHeader header;
    fread(&header, sizeof(BMPHeader), 1, file);
    
    BMPInfoHeader infoHeader;
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    if (header.type != 0x4D42) { // Vérification signature "BM"
        printf("Ce n'est pas un fichier BMP valide.\n");
        fclose(file);
        return 1;
    }

    printf("Largeur : %d pixels\n", infoHeader.width);
    printf("Hauteur : %d pixels\n", infoHeader.height);

    fclose(file);
}
