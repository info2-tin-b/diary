#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

typedef struct list {
    Node *head;
    Node *tail;
} List;

void display(List *list) {
    Node *el = list->head;
    while(el) {
        printf("%d\n", el->data);
        el = el->next;
    }
}

Node * push_back(List *list, int data) {
    Node *new_node = (Node*)calloc(1, sizeof(Node));
    if (new_node == NULL) exit(EXIT_FAILURE);
    new_node->data = data;

    // If list is empty?
    if (list->tail == NULL || list->head == NULL) {
        list->head = list->tail = new_node;
        return new_node;
    }
    list->tail->next = new_node;
    list->tail = list->tail->next;
    return new_node;
}

int main() {
    List list = {0};
    push_back(&list, 4);
    push_back(&list, 8);
    push_back(&list, 15);
    push_back(&list, 16);
    push_back(&list, 23);
    push_back(&list, 42);
    display(&list);
}
