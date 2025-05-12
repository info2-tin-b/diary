#include <stdio.h>

// Fonction pour échanger deux éléments
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour maintenir la propriété de tas (heapify)
void tasifier(int tableau[], int n, int i) {
    int plusGrand = i;       // Initialise le plus grand comme racine
    int gauche = 2 * i + 1;  // Fils gauche
    int droite = 2 * i + 2;  // Fils droit

    // Si le fils gauche est plus grand que la racine
    if (gauche < n && tableau[gauche] > tableau[plusGrand])
        plusGrand = gauche;

    // Si le fils droit est plus grand que le plus grand jusqu'à présent
    if (droite < n && tableau[droite] > tableau[plusGrand])
        plusGrand = droite;

    // Si le plus grand n'est pas la racine
    if (plusGrand != i) {
        echanger(&tableau[i], &tableau[plusGrand]);

        // Rappel récursif
        tasifier(tableau, n, plusGrand);
    }
}

// Fonction principale de Heap Sort
void heapSort(int tableau[], int n) {
    // Construction du tas (réorganisation du tableau)
    for (int i = n / 2 - 1; i >= 0; i--)
        tasifier(tableau, n, i);

    // Extraction d'un à un les éléments du tas
    for (int i = n - 1; i >= 0; i--) {
        // Déplace la racine (maximum actuel) à la fin
        echanger(&tableau[0], &tableau[i]);

        // Appelle tasifier sur le tas réduit
        tasifier(tableau, i, 0);
    }
}

// Fonction d'affichage du tableau
void afficher(int tableau[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", tableau[i]);
    printf("\n");
}

// Exemple d'utilisation
int main() {
    int tableau[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(tableau) / sizeof(tableau[0]);

    printf("Tableau initial :\n");
    afficher(tableau, n);

    heapSort(tableau, n);

    printf("Tableau trié :\n");
    afficher(tableau, n);
}
