# Semaine 12/16

- [x] Complexité algorithmique
- [x] Algorithmes de tri
  - [x] Bubble Sort (O(n²))
  - [x] [Heap Sort](https://heig-tin-info.github.io/handbook/course-c/40-algorithms/sorting/heap-sort) O(n log n)

- [ ] Recherche linéaire et dichotomique
  - [ ] Recherche linéaire O(n)
  - [ ] Recherche dichotomique O(log n)
  
- [ ] Récursivité
  - [ ] Factorielle
  - [ ] Fibonacci
  - [ ] Labyrinthe
- [ ] Liste doublement chaînée


## Complexité algorithmique

1. On exprime la complexité d'un algorithme a "La notation en O" *Big O*
2. On peut exprimer la complexité **en temps** ou **en espace**
3. On élimine les constantes et les termes de moindre importance O(2*n) -> O(n)
4. Le Big O considère le pire des cas

### Exemple

Rechercher un élément dans un tableau de taille N

$$O(n)$$

Et si le tableau il est trié ?

$$O(log n)$$