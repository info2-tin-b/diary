# Semaine 06/16

- [ ] L'allocation dynamique
- [ ] Les tableaux dynamiques

## Allocation dynamique

```c
int *p = malloc(sizeof(int));
if (p == NULL) {
    // erreur
}
*p = 42;
free(p); // Très important
```

## Compilation séparée

1. Toujours mettre un `#pragma once` en haut de chaque fichier d'en-tête
2. Compilation avec `gcc -c fichier.c` pour créer un fichier objet
3. Compilation avec `gcc a.o b.o c.o` pour créer un exécutable