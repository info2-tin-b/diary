#include <assert.h>

struct point {
    float x;
    float y;
    float z;
};

struct point sum(struct point a, struct point b) {
    struct point c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}

void swapxy(struct point *a) {
    double tmp = a->x;  // (*a).x === a->x
    a->x = a->y;
    a->y = tmp;
}

void display(const struct point *a) {
    printf("Point(x:%g,y:%g,z:%g)", a->x, a->y, a->z);
}

int main() {
    struct point a;
    a.x = 42;
    float tmp = a.y;

    struct point b = {1.23, 34.89, 42.42};
    assert(b.x == 1.23);

    struct point c = {.y = 45.1};
    assert(c.x == 0.0);
    assert(c.y == 45.1);
}