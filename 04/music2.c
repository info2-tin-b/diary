#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
/**
 * Chunk d’entête : 14 octets exacts
 *  - 4  octets : "MThd"
 *  - 4  octets : taille = 6 (big-endian)
 *  - 2  octets : format = 0
 *  - 2  octets : ntrks = 1
 *  - 2  octets : division = 96
 */
typedef struct {
    char     chunk_id[4];   // "MThd"
    uint32_t chunk_size;    // Toujours 6 pour un MIDI standard
    uint16_t format;        // 0, 1 ou 2
    uint16_t ntrks;         // nb de pistes
    uint16_t division;      // ticks par noire
} MThdChunk;

/**
 * Chunk de piste : 8 octets exacts
 *  - 4  octets : "MTrk"
 *  - 4  octets : taille (big-endian)
 */
typedef struct {
    char     chunk_id[4];   // "MTrk"
    uint32_t chunk_size;    // taille en octets des events
} MTrkChunk;
#pragma pack(pop)

/**
 * Conversion en big-endian
 */
static uint16_t to_big_endian_16(uint16_t val) {
    return (uint16_t)(((val & 0x00FF) << 8) | ((val & 0xFF00) >> 8));
}

static uint32_t to_big_endian_32(uint32_t val) {
    return ((val & 0x000000FF) << 24) |
           ((val & 0x0000FF00) << 8)  |
           ((val & 0x00FF0000) >> 8)  |
           ((val & 0xFF000000) >> 24);
}

void write_midi_file(const char *filename) {

}

int main(int argc, char *argv[]) {
    char *filename = argc > 1 ? argv[1] : "gamme.mid";
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Préparer l'entête MIDI
    MThdChunk header;
    memcpy(header.chunk_id, "MThd", 4);
    header.chunk_size = to_big_endian_32(6);   // La taille de la zone "format+ntrks+division" = 6
    header.format     = to_big_endian_16(0);   // Format 0
    header.ntrks      = to_big_endian_16(1);   // Une piste
    header.division   = to_big_endian_16(96);  // 96 ticks par noire

    // Piste MIDI
    // Événements : ON + OFF pour 8 notes (gamme de Do), puis End Of Track
    unsigned char notes[] = {
        // Do
        0x00, 0x90, 60, 100,   // Note ON (delta=0)
        0x60, 0x80, 60, 0,     // Note OFF (delta=0x60)
        // Ré
        0x00, 0x90, 62, 100,
        0x60, 0x80, 62, 0,
        // Mi
        0x00, 0x90, 64, 100,
        0x60, 0x80, 64, 0,
        // Fa
        0x00, 0x90, 65, 100,
        0x60, 0x80, 65, 0,
        // Sol
        0x00, 0x90, 67, 100,
        0x60, 0x80, 67, 0,
        // La
        0x00, 0x90, 69, 100,
        0x60, 0x80, 69, 0,
        // Si
        0x00, 0x90, 71, 100,
        0x60, 0x80, 71, 0,
        // Do aigu
        0x00, 0x90, 72, 100,
        0x60, 0x80, 72, 0,
        // Fin de la piste
        0x00, 0xFF, 0x2F, 0x00  // End of Track
    };
    size_t notes_length = sizeof(notes);

    // Chunk MTrk (c'est une seule piste)
    MTrkChunk track;
    memcpy(track.chunk_id, "MTrk", 4);
    track.chunk_size = to_big_endian_32((uint32_t)notes_length);

    // Écriture dans le fichier
    fwrite(&header, sizeof(MThdChunk), 1, file);
    fwrite(&track, sizeof(MTrkChunk), 1, file);
    fwrite(notes, 1, notes_length, file);
    fclose(file);
    printf("Fichier MIDI généré : %s\n", filename);
}
