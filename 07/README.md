# Semaine 07/16

On s'intéresse aux fichiers BMP.

## Décoder un fichier BMP

Utiliser `convert` de ImageMagick pour générer un fichier BMP. Utiliser `sudo apt install imagemagick` pour l'installer.

Générez différentes versions :

```bash
convert -size 1x1 canvas:black -depth 8 BMP3:1x1bk.bmp
convert -size 1x1 canvas:white -depth 8 BMP3:1x1wh.bmp
convert -size 1x1 canvas:red -depth 8 BMP3:1x1red.bmp
convert -size 1x1 canvas:blue -depth 8 BMP3:1x1blue.bmp
convert -size 1x1 canvas:yellow -depth 8 BMP3:1x1yellow.bmp
```

Comparez ces fichiers soit avec `hexdump -C 1x1bk.bmp`, soit avec le script fourni :

```bash
python hexdiff.py 1x1bk.bmp 1x1wh.bmp
```

Essayez maintenant d'augmenter la taille de l'image et voir ce qui change.
