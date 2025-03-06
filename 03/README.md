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

## Exercice

Créer un programme qui :

- Déclare une structure avec :
  - deux entiers 16-bits
  - 2 entiers 32-bit
  - Un tableau de char
- Déclarer une variable
- Sauvegarder dans fichier
- Explorer le fichier avec hexdump
