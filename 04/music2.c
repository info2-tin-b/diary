#include <stdint.h>
#include <string.h>
#include <stdio.h>

// Définition des commandes MIDI
typedef enum {
    NOTE_OFF  = 0x8,
    NOTE_ON   = 0x9,
    POLY_PRESSURE = 0xA,
    CONTROL_CHANGE = 0xB,
    PROGRAM_CHANGE = 0xC,
    CHANNEL_PRESSURE = 0xD,
    PITCH_BEND = 0xE
} MidiCommand;

// Définition des notes MIDI
typedef enum {
    NOTE_C1  = 24, NOTE_C1s = 25, NOTE_D1b = 25, NOTE_D1 = 26, NOTE_D1s = 27, NOTE_E1b = 27, NOTE_E1 = 28, NOTE_F1 = 29, NOTE_F1s = 30, NOTE_G1b = 30, NOTE_G1 = 31, NOTE_G1s = 32, NOTE_A1b = 32, NOTE_A1 = 33, NOTE_A1s = 34, NOTE_B1b = 34, NOTE_B1 = 35,
    NOTE_C2  = 36, NOTE_C2s = 37, NOTE_D2b = 37, NOTE_D2 = 38, NOTE_D2s = 39, NOTE_E2b = 39, NOTE_E2 = 40, NOTE_F2 = 41, NOTE_F2s = 42, NOTE_G2b = 42, NOTE_G2 = 43, NOTE_G2s = 44, NOTE_A2b = 44, NOTE_A2 = 45, NOTE_A2s = 46, NOTE_B2b = 46, NOTE_B2 = 47,
    NOTE_C3  = 48, NOTE_C3s = 49, NOTE_D3b = 49, NOTE_D3 = 50, NOTE_D3s = 51, NOTE_E3b = 51, NOTE_E3 = 52, NOTE_F3 = 53, NOTE_F3s = 54, NOTE_G3b = 54, NOTE_G3 = 55, NOTE_G3s = 56, NOTE_A3b = 56, NOTE_A3 = 57, NOTE_A3s = 58, NOTE_B3b = 58, NOTE_B3 = 59,
    NOTE_C4  = 60, NOTE_C4s = 61, NOTE_D4b = 61, NOTE_D4 = 62, NOTE_D4s = 63, NOTE_E4b = 63, NOTE_E4 = 64, NOTE_F4 = 65, NOTE_F4s = 66, NOTE_G4b = 66, NOTE_G4 = 67, NOTE_G4s = 68, NOTE_A4b = 68, NOTE_A4 = 69, NOTE_A4s = 70, NOTE_B4b = 70, NOTE_B4 = 71,
    NOTE_C5  = 72
} MidiNoteValue;

#pragma pack(push, 1)

// Définition d'une structure pour une note MIDI
typedef struct {
    uint8_t delta_time;  // Temps relatif avant l'événement
    union midi_command {
        struct {
            uint8_t channel : 4;  // Canal MIDI
            uint8_t command : 4;  // Commande MIDI (Note ON / Note OFF)
        };
        uint8_t value;
    } command;
    uint8_t status;      // Statut MIDI (Note ON / Note OFF + Canal)
    MidiNoteValue note;  // Numéro de la note MIDI
    uint8_t velocity;    // Vélocité
} MidiNote;

#pragma pack(pop)

// Fin de la piste MIDI
uint8_t end_of_track[] = {0x00, 0xFF, 0x2F, 0x00};

// Fonction pour écrire le fichier MIDI
void write_midi_file(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Préparer l'entête MIDI
    uint8_t header[] = {
        'M', 'T', 'h', 'd', // Chunk ID
        0x00, 0x00, 0x00, 0x06, // Chunk Size (6)
        0x00, 0x00, // Format 0
        0x00, 0x01, // Une seule piste
        0x00, 0x60  // 96 ticks par noire
    };

    // Tableau de notes MIDI
    MidiNote notes[] = {
        {.delta_time = 0, .note = NOTE_C4, .command.command = NOTE_ON, .velocity = 100},
        {.delta_time = 0, .note = NOTE_C4, .command.command = NOTE_OFF, .velocity = 0},
        //{0x00, (NOTE_ON << 4) | 0, NOTE_C4, 100}, {0x60, (NOTE_OFF << 4) | 0, NOTE_C4, 0}, // Do
        //{0x00, (NOTE_ON << 4) | 0, NOTE_D4, 100}, {0x60, (NOTE_OFF << 4) | 0, NOTE_D4, 0}, // Ré
        // {0x00, (NOTE_ON << 4) | 0, NOTE_E4, 100}, {0x60, (NOTE_OFF << 4) | 0, NOTE_E4, 0}, // Mi
        // {0x00, (NOTE_ON << 4) | 0, NOTE_F4, 100}, {0x60, (NOTE_OFF << 4) | 0, NOTE_F4, 0}, // Fa
        // {0x00, (NOTE_ON << 4) | 0, NOTE_G4, 100}, {0x60, (NOTE_OFF << 4) | 0, NOTE_G4, 0}, // Sol
        // {0x00, (NOTE_ON << 4) | 0, NOTE_A4, 100}, {0x60, (NOTE_OFF << 4) | 0, NOTE_A4, 0}, // La
        // {0x00, (NOTE_ON << 4) | 0, NOTE_B4, 100}, {0x60, (NOTE_OFF << 4) | 0, NOTE_B4, 0}, // Si
        // {0x00, (NOTE_ON << 4) | 0, NOTE_C5, 100}, {0x60, (NOTE_OFF << 4) | 0, NOTE_C5, 0}  // Do aigu
    };

    size_t notes_length = sizeof(notes);

    // Chunk MTrk
    uint8_t track_header[] = {
        'M', 'T', 'r', 'k',
        (uint8_t)((notes_length + sizeof(end_of_track)) >> 24),
        (uint8_t)((notes_length + sizeof(end_of_track)) >> 16),
        (uint8_t)((notes_length + sizeof(end_of_track)) >> 8),
        (uint8_t)(notes_length + sizeof(end_of_track))
    };

    // Écriture dans le fichier
    fwrite(header, sizeof(header), 1, file);
    fwrite(track_header, sizeof(track_header), 1, file);
    fwrite(notes, 1, notes_length, file);
    fwrite(end_of_track, sizeof(end_of_track), 1, file);

    fclose(file);
    printf("Fichier MIDI généré : %s\n", filename);
}

int main(int argc, char *argv[]) {
    char *filename = argc > 1 ? argv[1] : "gamme.mid";
    write_midi_file(filename);
    return 0;
}
