// Faire un programme en C qui crée un 
// fichier écrit du texte dedans et le ferme
#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "w");
    if (fp == NULL) { 
        fprintf(stderr, "Erreur\n");
        return 1; 
    }
    fprintf(fp, "Hello");
    fprintf(fp, " World!\n");

    fclose(fp);
}