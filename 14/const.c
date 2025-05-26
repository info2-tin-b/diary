#include <stdio.h> 

struct data {
    int a;
    int b;
    int values[128];
};

void foo(struct data d) {
}

void bar(const struct data *d) {
    d->a = 42; // Interdit
}

int main() {
    struct data u;
    foo(u);
    bar(&u);



    const int i = 42;
    int a[4]; 

    printf("Address a %p\n", a);
    printf("Address i %p\n", &i);

    printf("Address: %p\n", a - 1);

    *(a-1) = 666;
    printf("Valeur de i %d\n", i);
}