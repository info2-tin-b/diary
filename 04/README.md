# Semaine 04/16

- [x] Introduction aux pointeurs
- [ ] Finir exercice sin/cos
- [ ] Exercice sin/cos binaire

## Exercice sin/cos binaire

Générer un fichier `data.bin` contenant l'angle, la valeur du sin^2 et du cos^2.
en format binaire, chaque entrée représente un `float`. Les valeurs de l'angle vont de 0 à 2*pi et avec 256 valeurs.

## Midi

```bash
sudo apt install midicsv fluidsynth
midicsv gamme.mid
fluidsynth -F gamme.wav -r 44100
```

## Déclaration

```c
int a;  // Je déclare un entier
int *p = &a; // Je déclare un pointeur sur un entier (ici a)
char *q; // Je déclare un pinteur sur un char
unsigned long long int *v; // Je décalre un pointeur sur ...

void *w; // Je déclare un pointeur sans type.


0xffc53456281978xx
| 00  | 01  | 02  | 03  | 04  | 05  | 06  | 07  |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 45  | 23  | 2e  | 1f  | 67  | 88  | 01  | 96  |

char *a = 0xffc5345628197804;
printf("%hhx\n", *a);
printf("%p\n", a);
```

## Double, triple pointeurs

```c
int a = 42;
int *p = &a;
int **q = &p;
int ***r = &q;

printf("Valeur de a: %d\n", *&*&*&*&*&*&*&*&*&*&a);
printf("Valeur de a: %d\n", *p);
printf("Valeur de a: %d\n", **q);
printf("Valeur de a: %d\n", ***r);
```

## uintptr_t

Ce type permet de représenter une adresse sous forme d'un entier.

```c
int array[] = {1,2,3,4};
int *a = array; // (1)

unsigned long int c = (unsigned long int)a;
uintptr_t c = (uintptr_t)a;
```
