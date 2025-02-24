#include <stdio.h>

struct point3d {
    int x;
    int y; 
    int z; 
};

struct location {
    struct point3d point;
    double t;
    char name[32];
};

int main() {
    struct location loc[10] = { [2].point.x = 23 }; 
    loc[0].point.x = 23;
    loc[0].t = 23.42;


    int foo = 42; // scalaire de type entier signé (complément à deux)
    char *ptr = "toto"; // pointeur sur un entier (chaîne de caractères)
    long array[10]; // tableau de 10 éléments long

    struct { int x; int y; } point = {.x = 23, .y = 42};
    printf("%d, %d\n", point.x, point.y);

    printf("%ld\n", sizeof(point));
}