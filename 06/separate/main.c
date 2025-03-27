#include <stdio.h> 

#include "std.h" 

int main() {
    double data[] = {1.2, 3.6, 8.7 };

    printf("mean: %g\n", mean(data, sizeof(data)/sizeof(data[0])));
    printf("std: %g\n", std(data, sizeof(data)/sizeof(data[0])));
}