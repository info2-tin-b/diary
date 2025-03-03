# Semaine 03/16

- [ ] Fichiers sont organisé dans une arborescence 
- [ ] Un point d'une arborescence peut être identifié par un chemin
- [ ] Un chemin peut être absolu ou relatif
- [ ] Sous Windows, un chemin commence par lecteur (C:), sous Linux par un /
- [ ] Le `.` veut dire le chemin courant
- [ ] Le `..` veut dire le chemin parent
- [ ] Un fichier peut être "texte" ou "binaire"
- [ ] Les ordinateurs modernes utilisent le *little endian*
- [ ] Un entier stocké dans un fichier commencera par son point faible
- [ ] Les formarts "texte" sérialisé peuvent être XML, JSON, YAML, CSV...

## Chemins de fichiers

/earth/europe/switzerland/vaud/yverdon-les-bains/cheseaux/1/g/4

./4
../k/7

.././../1/g/../g/4

C:\earth\europe\switzerland\vaud\yverdon-les-bains\cheseaux\1\g\4


## Exercice

Créer un programme qui : 

- Déclare une structure avec :
  - deux entiers 16-bits
  - 2 entiers 32-bit
  - Un tableau de char
- Déclarer une variable
- Sauvegarder dans fichier 
- Explorer le fichier avec hexdump