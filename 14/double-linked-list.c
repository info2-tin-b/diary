#include <stdio.h>

typedef struct element {
    int value; 
    struct element *next;
    struct element *prev;
} Element;

typedef struct list {
    Element *head;
    Element *tail;
} List;

int main() {
    Element a = {.value=4, .prev=NULL};
    Element b = {.value=8, .prev=&a};
    Element c = {.value=15, .prev=&b};
    Element d = {.value=16, .prev=&c};
    Element e = {.value=23, .prev=&d};
    Element f = {.value=42, .prev=&e, .next=NULL};
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e; 
    e.next = &f;

    List list = {.head=&a, .tail=&f};

    // Parcourir la chaîne du début à la fin (en affichant les valeurs)
    Element *walker = list.head;
    do (walker->next != NULL) {
        printf("%d ", walker->value);
        walker = walker->next;
    }
    printf("%d ", walker->value);
}