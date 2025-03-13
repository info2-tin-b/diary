#include <stdio.h>
#include <stdlib.h>

void write_midi_file(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Entête MIDI (Format 0, une piste, résolution de 96 ticks par noire)
    unsigned char header[] = {
        'M', 'T', 'h', 'd',
        0x00, 0x00, 0x00, 0x06,  // Taille de l'entête (toujours 6)
        0x00, 0x00,  // Format 0 (une seule séquence)
        0x00, 0x01,  // Une seule piste
        0x00, 0x60   // 96 ticks par noire
    };

    // Piste MIDI avec une taille plus grande pour éviter les erreurs
    unsigned char track_header[] = {
        'M', 'T', 'r', 'k',
        0x00, 0x00, 0x00, 0x50  // Taille approximative, sera recalculée si besoin
    };

    // Séquence des notes de la gamme de Do majeur
    unsigned char notes[] = {
        // Do
        0x00, 0x90, 60, 100,  // Note ON (Do, vélocité 100)
        0x60, 0x80, 60, 0,    // Note OFF (Do)
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

    // Écriture dans le fichier
    fwrite(header, sizeof(header), 1, file);
    fwrite(track_header, sizeof(track_header), 1, file);
    fwrite(notes, sizeof(notes), 1, file);

    fclose(file);
    printf("Fichier MIDI généré : %s\n", filename);
}

int main() {
    write_midi_file("gamme.mid");
}
