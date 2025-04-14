#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

int main() {
    Node a = {.data = 42 };
    Node b = {.data = 23, .next = &a };
    a.next = &b;

    Node *el = &a;
    for (int i = 0; i < 10; i++ ) {
        printf("%d: %d\n", i, el->data);
        el = el->next;
    }
}
