#include <stdio.h>

int get_foo() {
    return 23;
}

int counter() {
    static int i = 0;
    //printf(" -%p-", &i);
    return i++;
}

int main() {
    printf("%d\n", get_foo());

    printf("%d ", counter());
    printf("%d ", counter());
    printf("%d ", counter());
    // int *hack = (int*)0x555555558014;
    // *hack = 42;
    printf("%d ", counter());
    printf("%d ", counter());
}