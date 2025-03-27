#include <math.h>

#include "mean.h" 

double std(double *data, size_t size) {
    double m = mean(data, size);
    double sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += (data[i] - m) * (data[i] - m);
    }
    return sqrt(sum / size);
}