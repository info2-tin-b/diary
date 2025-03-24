/**
 * On veut un programme qui lit un nombre sur 
 * l'entrée standard ou depuis le premier argument
 * et l'affiche sur la sortie standard.asm
 * 
 * Le programme peut faire la première ou la seconde action
 * selon le parametre FROM_STDIN
 */
#if !defined FROM_STDIN
#define FROM_STDIN 0
#endif 

#include <stdio.h>

#if !FROM_STDIN
#include <stdlib.h>
int main(int argc, char* argv[]) {
    int value;
    if (argc > 1) value = atoi(argv[1]);
    printf("%d\n", value);
}
#else 
int main() {
    int value;
    if (scanf("%d", &value) != 1) return 1;
    printf("%d\n", value);    
}
#endif 