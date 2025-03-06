# Semaine 03/16

- [x] Fichiers sont organisé dans une arborescence
- [x] Un point d'une arborescence peut être identifié par un chemin
- [x] Un chemin peut être absolu ou relatif
- [x] Sous Windows, un chemin commence par lecteur (C:), sous Linux par un /
- [x] Le `.` veut dire le chemin courant
- [x] Le `..` veut dire le chemin parent
- [x] Un fichier peut être "texte" ou "binaire"
- [x] Les ordinateurs modernes utilisent le *little endian*
- [x] Un entier stocké dans un fichier commencera par son point faible
- [x] Les formarts "texte" sérialisé peuvent être XML, JSON, YAML, CSV...

## Chapitres du cours

- [Fichiers](https://heig-tin-info.github.io/handbook/course-c/25-architecture-and-systems/files/?h=fic#fichiers)
- [Système de fichier](https://heig-tin-info.github.io/handbook/tools/arch/filesystem/?h=fichier#organisation)
- [Boutisme](https://heig-tin-info.github.io/handbook/course-c/15-fundations/datatype/?h=boutisme)

## Chemins de fichiers


Chemin absolu POSIX :

```text
/earth/europe/switzerland/vaud/yverdon-les-bains/cheseaux/1/g/4
```

Chemin absolu Windows :

```text
C:\earth\europe\switzerland\vaud\yverdon-les-bains\cheseaux\1\g\4
```

Chemins relatifs :

```text
./4
../k/7
.././../1/g/../g/4
```

## Exercice 1

Créer un programme qui :

- Déclare une structure avec :
  - deux entiers 16-bits
  - 2 entiers 32-bit
  - Un tableau de char
- Déclarer une variable
- Sauvegarder dans fichier
- Explorer le fichier avec hexdump

## Résumé de la dernière fois

- Deux types de fichiers : texte et binaire
- Un fichier text contient que des caractères ASCII / Unicode
- La majorité des ordinateurs aujourd'hui sont en Little Endian
- En Little Endian on stock les bytes de poids faible en premier

```c
char u[] = {0x01, 0x00, 0x00, 0x00};
printf("%d", *(int*)&u);
```

## Exercice 2

Écrire un programme qui effectue 256 itérations et calcul:

s = sin(a) * sin(a)
c = cos(a) * cos(a)

La valeur de a va de 0 à 2*pi donc chaque itération incrémente l'angle de 
2*pi/256

Ouvrir un fichier et écrire dans ce fichier en ASCII la valeur de l'angle
de s et de c avec 2 chiffres après la virgule.

- fprintf(fp, "%.2f %.2f\n", s, c)

## Exercice 3

Faire un programme en C qui lit le fichier créé avec l'exercice 2
Et afficher sur l'écran pour chaque ligne la somme de s + c 