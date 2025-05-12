## Exercice

- 5 Mise en place (vscode, nouveau fichier, dossier, gcc)
- 5 Tester lecture sur l'entrée standard et écriture sur la sortie standard
- 10 Implémenter le programme avec un tableau de taille fixe 256 bytes
- 10 Implémenter le programme avec le tableau dynamique.

## Pointeurs

```c
int value = 23;
int *a = &value; // "L'adresse de" value
int c = *a; // "Le contenu de" a

int* p = 0xdeadbeef;
int **q = &p;
int ***r = &q;

// /!\ Attention
int *a, b; // a est un pointeur, b est un int 
```