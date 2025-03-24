# Semaine 05/16

- [ ] Préprocesseur
- [ ] Passer en revue la donnée (formats de sortie)
- [ ] Continuer le labo en classe

## Préprocesseur

### Macro 

Remplacement de chaîne simple : 

```c
#define NOM CONTENU
#define PI 3.14
#define U Les choux sont blancs
```

Macros avec paramètres: 

```c
#define MAX(a, b) (a > b ? a : b)
MAX(23, 42)
```

/!\ Attention

1. Toujours protéger les macros avec des parenthèses
2. Les macros sont du REMPLACEMENT DE CHAINES

### Inclusion

Cette directive intègre le contenu d'un fichier à la place de la directive. 

- `"nom"` Inclusion locale
- `<nom>` Inclusion globale (système)

```c 
#include <nom>
#include "nom"
```

### Conditions

```c
#if 0
n'importe quoi 
#endif 

```c
#if
#ifdef
#ifndef
#else
#elif
#endif
```