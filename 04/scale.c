#include <stdio.h>
#include <stdlib.h>

#ifndef SCALE
#   define SCALE 42
#endif

int main(int argc, char * argv[]) {
    if (argc > 1) {
        printf("%d\n", atoi(argv[1]) * SCALE);
    }
}