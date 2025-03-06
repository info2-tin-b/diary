/*
Faire un programme en C qui lit le fichier créé avec l'exercice 2
Et afficher sur l'écran pour chaque ligne la somme de s + c 
*/
#include <stdio.h>

int main() {
    FILE *fp = fopen("data.bin", "r");

    do {
        double s, c;
        if (fscanf(fp, "%*f %lf %lf", &s, &c) == 2) {
            printf("%f\n", s + c);
        }
    } while(!feof(fp));   
    fclose(fp);
}