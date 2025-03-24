#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t capacity = 4;
    double *data = malloc(capacity * sizeof(double));
    if (data == NULL) exit(1);

    size_t i = 0; 
    while(scanf("%lf", &data[i++]) == 1) {
        if (i >= capacity) {
            capacity *= 2;
            double *new_data = realloc(data, capacity * sizeof(double));
            if (new_data == NULL) exit(2);
            data = new_data;
        }
        printf("%ld, %ld\n", i, capacity);
    }

    for (int k = i - 2 ; k >= 0; k--) {
        printf("%lg\n", data[k]);
    }
}