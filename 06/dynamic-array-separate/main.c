#include <stdio.h> 
#include <stdint.h> 

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
