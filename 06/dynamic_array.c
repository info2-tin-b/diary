#include <stdio.h>
#include <stdlib.h>

typedef struct array {
    size_t capacity;
    size_t size;
    double *data;
} Array;

void init(Array *array);
void push_back(Array *array, double value);
void push_front(Array *array, double value);
double pop_back(Array *array);
double pop_front(Array *array);

int main() {
    Array array;
    init(&array);
    push_back(&array, 4);
    push_back(&array, 8);
    push_back(&array, 15);
    push_back(&array, 16);
    push_back(&array, 23);
    push_back(&array, 42);

    printf("Capacity: %d\n", array.capacity);
}
