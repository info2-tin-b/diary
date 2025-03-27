#include <stddef.h>

double mean(double *data, size_t size) {
    double sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}