#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    int size = atoi(argv[1]);

    //int data[size]; // Normalement pas autorisé...
    int *data = malloc(size);
    if (data == NULL) {
        fprintf(stderr, "Not enough memory");
        return 2;
    }
    for (int i = 0; i < size; i++) {
        data[i] = i * 2;
    }
    for (int i = 0; i < size; i++) {
        printf("%d\n", data[i]);
    }    

    free(data);
}