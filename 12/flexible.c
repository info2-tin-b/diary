#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray {
    int size;
    int capacity;
    char data[];
} Foo;

int main() {
    // Affiche 8 car deux entiers font 8 bytes.
    printf("Size Foo: %ld\n", sizeof(Foo));

    // Alloue une structure Foo avec de la place pour 10 caractères dans data
    Foo *foo = malloc(sizeof(Foo) + sizeof(char) * 10);

    foo->data[9] = 'u'; // OK
    foo->data[10] = 'j'; // Jardine
}