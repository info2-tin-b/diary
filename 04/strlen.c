#include <stdio.h>

int my_strlen(char *s) {
    char *start = s;
    char *end = s;
    while(*(end++) != '\0') {}
    return end - start - 1;
}

int main() {
    char *s = "chocolat";
    printf("%d\n", my_strlen(s));
}