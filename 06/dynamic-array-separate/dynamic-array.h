#pragma once 

#include <stdio.h> 
#include <stdint.h>

typedef struct array {
    size_t capacity;
    size_t size;
    double *data;
} Array;

void display(Array *, FILE*);
double pop_back(Array *);
double pop_front(Array *);
void push_front(Array*, double);
void push_back(Array*, double);
void init(Array *);
