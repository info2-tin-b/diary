#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

void display(Node *el) {
    while(el) {
        printf("%c\n", el->data);
        el = el->next;
    }
}

int main() {
    // T0
    Node a = {.data = 'a' };
    Node b = {.data = 'b', .next = &a };
    Node c = {.data = 'c', .next = NULL};
    Node *head = &a;

    // T1 Insérer l'élément `d` au début de la liste
    Node d = {.data = 'd'};
    
    display(head);
}
