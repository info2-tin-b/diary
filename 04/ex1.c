#include <stdio.h>

void my_strncpy(char *dst, char *src, size_t size_dst) {
    // ...
}

int main() {
    char *a = "Tourte aux pommes";
    char b[128] = "";

    my_strncpy(b, a, sizeof(b));
    printf("%s\n", b);
}