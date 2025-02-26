# Semaine 02/16

- [ ] Se familiariser avec les fichiers
- [ ] Faire fonctionner l'environnement de développement sans CodeSpace
- [ ] Commencer le labo 0x21

## Théorie

### Encodage

Les fichiers sont des séquences d'octets. Les octets sont des entiers de 0 à 255. Les fichiers dit **textes** sont des fichiers dont les octets sont des caractères imprimables. Par opposition, les fichiers **binaires** sont des fichiers dont les octets peuvent être n'importe quel entier et qui ne représentent pas nécessairement des caractères.

Un fichier qui ne comporte que les codes ASCII de 0x00 à 0x7F est dit ASCII pure. Il se base sur la table ASCII de 1986 qui ne comprend aucun caractère accentué ni diacritique.

Jadis, les fichiers qui comportaient des caractères supplémentaires (de 0x80 à 0xFF) étaient dits **étendus** et devaient se conformer à une table d'extension normalisée, généralement ISO-8859-1 (latin1) ou ISO-8859-15 (latin9). Ainsi les russes utilisaient ISO-8859-5, les grecs ISO-8859-7, etc.

L'ennui c'est qu'il est impossible de savoir quelle table a été utilisée pour encoder un fichier étendu. C'est pourquoi on a inventé l'UTF-8 qui est un encodage universel qui peut représenter tous les caractères Unicode. UTF-8 est compatible avec ASCII, c'est-à-dire que les fichiers ASCII sont aussi des fichiers UTF-8.

### Fin de ligne

Emprunté aux machines à écrire, un retour à la ligne se composait historiquement de deux opérations, ou deux caractères : un retour chariot (CR) suivi d'une avance de ligne (LF). Curieusement, les différents systèmes d'exploitations de l'époque ont adopté des conventions différentes pour les fins de ligne :

- Unix : LF (\r ou 0x0A)
- Windows : CR+LF (\r\n ou 0x0D0A)
- Mac : CR (\r ou 0x0D)

La seule véritable norme en vigueur concernant les systèmes d'exploitation est POSIX qui recommande LF. C'est pourquoi les fichiers textes sous Unix et Linux utilisent LF pour marquer la fin de ligne. Depuis que Apple a adopté Unix en 2001, macOS utilise également LF. Il ne reste donc que deux standards:

- Windows : CR+LF
- Le reste du monde : LF

### Ouvrir un fichier

```c
FILE *fichier = fopen("poeme.txt", "r");
```

Mode d'ouverture:

- `r` : lecture
- `w` : écriture
- `a` : ajout
- `r+` : lecture et écriture

### Pointeur de fichier

Le type `FILE*` est un pointeur de fichier. Il est exactement du même type que `stdin` ou `stdout` qui sont également des pointeurs de fichiers vers les flux standard d'entrée et de sortie.

### Fichier ou flux

De nombreux programmes demandent le nom d'un fichier en argument et basculent automatiquement vers l'entrée standard si aucun fichier n'est spécifié. Cela permet de traiter les fichiers et les flux de la même manière. On peut l'implémenter facilement avec :

```c
FILE *fp = argc > 1 ? fopen(argv[1], "r") : stdin;
```

## Exercices

### Exercice 1

Faire un programme en C qui crée un fichier écrit du texte dedans et le ferme

### Exercice 2

Faire un programme en C qui lit le fichier créé avant et affiche le contenu
sur la sortie standard

### Exercice 3

Compter le nombre de mots dans poeme.txt

## WSL

- [ ] WSL2 (Windows Subsystem for Linux)
- [ ] Ubuntu 24.04 Distribution Linux
- [ ] Visual Studio Code
- [ ] Installer Git et le configurer
