#include <stdio.h>

int main() {
    int array[] = { 4, 8, 15, 16, 23, 42, 88, 108 };

    int *p = &array[4];
    
    // array[2] ==== 2[array] ==== *(array + 2)
    printf("%d\n", *p); // 23
    printf("%d\n", *(p + 1)); // 42
    printf("%d\n", *(p - 1)); // 16
    printf("%d\n", p[1]); // 42
    printf("%d\n", p[-1]); // 16

    char *s = "crocodile";

    size_t size = strlen(s);
    for(int i = 0; i < size; i++) {
        printf("%c ", s[i]);
    }

    char *p = s;
    while(*p != '\0') {
        printf("%c ", *(p++));
    }
}