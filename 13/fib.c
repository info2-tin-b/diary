/*
- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2) pour n > 1
*/
#include <stdio.h>

int fib(int n, int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%d\n", n);

    if (n == 0 || n == 1) return n;
    return fib(n - 1, level + 1) + fib(n - 2, level + 1);
}

int fib_with_cache(int n) {
    int cache[1024] = {0};
    if (cache[n] > 0) {
        return cache[n];
    }
    if (n == 0 || n == 1) return n;
    cache[n] = fib_with_cache(n - 1) + fib_with_cache(n - 2);
    return cache[n];
}

void fib_weber(int n) {
    int temp, x=0, y = 1;
    for (int i = 0; i < n; i++) {
        printf("%d ", x);
        temp = x;
        x += y;
        y = temp;
    }
}

int main() {
    printf("%d\n", fib_with_cache(20));
}