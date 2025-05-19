# Semaine 12/16

- [x] Complexité algorithmique
- [x] Algorithmes de tri
  - [x] Bubble Sort (O(n²))
  - [x] [Heap Sort](https://heig-tin-info.github.io/handbook/course-c/40-algorithms/sorting/heap-sort) O(n log n)
- [x] Recherche linéaire et dichotomique
  - [x] Recherche linéaire O(n)
  - [x] Recherche dichotomique O(log n)

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

## Exercice

1. Définir une structure de données `Contact` contenant un nom (max 64 caractères) et un numéro de téléphone sous forme d'un entier non signé 32-bit.
2. Insérer dans le *main* 10 contacts.
3. Utiliser `qsort` pour trier les contacts par téléphone.
4. Implémenter une fonction de recherche linéaire pour rechercher un contact par son numéro de téléphone.
5. Implémenter une fonction de recherche dichotomique pour rechercher un contact par son numéro de téléphone.
  
