#include <stdio.h>

int main() {
    int a[10] = {0, 1,2,3,4,5,6,7,8,9};

    printf("%d\n", a[2]);
    printf("%d\n", *(a + 2));
    printf("%d\n", *(2 + a));
    printf("%d\n", 2[a]);
}