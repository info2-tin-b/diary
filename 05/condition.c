#include <stdio.h>

#define VALUE 42

int main() {
#if VALUE == 42
    printf("Hello World\n");
#else 
    printf("Goodbye World\n");
#endif
}