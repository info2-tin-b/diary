#include <stdio.h>

int main() {
    char u[128];

    char *a = &u[0];
    char *b = &u[127];

    printf("%d\n", b - a); // 128

    int *aint = (int*)a;
    int *bint = (int*)b;
    printf("%d\n", bint - aint); // 32 
}