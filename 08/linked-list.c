#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

void display(Node *el) {
    while(el) {
        printf("%d\n", el->data);
        el = el->next;
    }
}

int main() {
    Node a = {.data = 42 };
    Node b = {.data = 23, .next = &a };
    Node c = {.data = 15, .next = NULL};
    Node *head = &a;
    display(head);
}
