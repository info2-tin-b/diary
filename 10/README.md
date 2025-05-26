# Semaine 10/16

## Type abstrait

```c
FILE *fp = fopen("file.txt", "w");
fwrite(fp, "Hello World");
ftell(fp); // Renvoie la position actuelle du curseur
fseek(fp, 0, SEEK_SET); // Remet le curseur au début du fichier
fclose(fp);
```

```c
typdef struct opaque Data;

Data *data; 
Data data; // Interdit car on ne connait pas la taille de Data


struct opaque {
    int a;
    char b;
};

Data data;
data.a = 23;
```