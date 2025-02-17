#include <stdio.h>

struct element {
    int value;
    struct element *next;
};

int main() {
    struct element a = { .value = 4, .next = NULL};
    struct element b = { .value = 8 };

    a.next = &b;
    b.next = &a;

    struct element *w = &a;
    for (int i = 0; i < 10; i++) {
        printf("%d ", (*w).value);
        w = w->next;
    }
}