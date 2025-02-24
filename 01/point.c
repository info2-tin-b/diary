#include <stdio.h>
#include <math.h>
struct point {
    double x;  
    double y;
};

double distance( struct point a, struct point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
} 

int main() {
    struct point data[10] = {
        {2, 3}, {4,7}, {-4, 6.4}, {8, -6}
    };

    distance(data[0], data[3]);
}