/*
Écrire un programme qui effectue 256 itérations et calcul:

s = sin(a) * sin(a)
c = cos(a) * cos(a)

La valeur de a va de 0 à 2*pi donc chaque itération incrémente l'angle de 
2*pi/256

Ouvrir un fichier et écrire dans ce fichier en ASCII la valeur de l'angle
de s et de c avec 2 chiffres après la virgule.
*/
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#   define M_PI 3.1415926535
#endif 

int main() {
    FILE *fp = fopen("data.bin", "w");
    if (fp == NULL) exit(1);

    for (int i = 0; i < 256; i++) {
        double a = 2. * M_PI * i / 256.;
        double s = pow(sin(a), 2);
        double c = pow(cos(a), 2);
        fprintf(fp, "%.2f %.2f %.2f\n", a, s, c);
    }

    fclose(fp);
}