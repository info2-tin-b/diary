/**
 * Implémentation d'un tableau dynamique en C.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct array {
    size_t capacity;
    size_t size;
    double *data;
} Array;

void init(Array *array) {
    array->capacity = 4;
    array->size = 0;
    array->data = malloc(sizeof(*array->data) * array->capacity);
    if (array->data == NULL) exit(EXIT_FAILURE);
}

void perform_realloc(Array *array) {
    if (array->size >= array->capacity) {
        array->capacity *= 2;
        double *new_data = realloc(array->data, sizeof(*array->data) * array->capacity);
        if (new_data == NULL) exit(EXIT_FAILURE);
        array->data = new_data;
    }
}

void push_back(Array *array, double value) {
    perform_realloc(array);
    array->data[array->size++] = value;
}

double pop_back(Array *array) {
    return array->data[--array->size];
}

double pop_front(Array *array) {
    double value = array->data[0];
    array->size--;
    for (size_t i = 0; i < array->size; i++) {
        array->data[i] = array->data[i + 1];
    }
    return value;
}

void push_front(Array *array, double value) {
    perform_realloc(array);
    for (int i = array->size; i > 0; i--) {
        array->data[i] = array->data[i - 1];
    }
    array->data[0] = value;
    array->size++;
}

void display(Array *array, FILE* fp) {
    fprintf(fp, "[");
    for (size_t i = 0; i < array->size; i++) { 
        fprintf(fp, "%lg%s", 
            array->data[i],
            i < array->size - 1 ? ", ": "]"
        );
    }
    puts("");
}

int main() {
    Array array;
    init(&array);
    push_back(&array, 4);
    push_back(&array, 8);
    push_back(&array, 15);
    printf("pop-front: %lf\n", pop_front(&array));
    push_back(&array, 16);
    push_front(&array, 88);
    push_back(&array, 23);
    printf("pop-back: %lf\n", pop_back(&array));
    push_back(&array, 42);


    printf("Capacity: %ld\n", array.capacity);
    printf("Count: %ld\n", array.size);

    display(&array, stdout);
}
