#include <stdio.h>
int main() {
    char *a = 0xffc5345628197804;
    printf("%hhx\n", *a);
    printf("%p\n", a);
}