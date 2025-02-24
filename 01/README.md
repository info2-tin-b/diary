# Semaine 01/16

## Exemples des sujets du semestre

### Fichiers

On verra comment ouvrir, lire, écrire, fermer un fichier.

Voir l'[exemple](./file.c)

### Structures

Les structures sont des types de données qui permettent de regrouper des données de types différents.

Voir l'[exemple](./point.c)

### Listes chaînées

Une liste chaînée est une structure de données qui permet de stocker des éléments de manière séquentielle.

Voir l'[exemple](./linked-list.c)

### Allocation dynamique

Demande au système d'exploitation de réserver un espace mémoire d'une taille variable.

Voir l'[exemple](./dynamic.c)

## Les Fichiers

Un fichier comprend un contenu et des méta données tel que:

- Une taille
- Un nom
- Une localisation sur le disque
- Des droits d'accès
- Une date de création
- Une date de modification
- Une date d'accès

Un fichier texte comporte un encodage (ISO-8859-15, UTF-8, ...) et un type de fin de ligne (CRLF (Windows), LF (Linux/Unix/MacOS), CR (Macintosh)).

## Types de fichiers

1. Fichier Textes (Contient du texte)
2. Fichier Binaires (Contient autre chose)

## Outils en ligne de commande

- `ls` Liste le contenu d'un dossier `ls -al` pour voir les détails
- `cat` Pour afficher le contenu d'un fichier
- `hexdump` Pour afficher en hexa le contenu d'un fichier `hexdump -C`
- `echo` Pour afficher sur la sortie standard ce qui est passé en arguments
