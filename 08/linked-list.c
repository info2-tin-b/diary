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

Node * push_back(Node* head, int value) {

}

int main() {
    // T0
    Node c = {.data = 'c', .next = NULL};
    Node b = {.data = 'b', .next = &c };
    Node a = {.data = 'a', .next = &b };
    Node *head = &a;

    // T1 Insérer l'élément `d` au début de la liste
    Node d = {.data = 'd', .next = &a };
    head = &d;

    display(head);
}
