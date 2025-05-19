/**
 * Recherche dichotomique (ou *binary search*)
 */
#include <stdio.h>
#include <stdlib.h> 

char data[] = {2, 4, 8, 14, 25, 34, 37, 42, 58, 66, 77, 78, 79, 89, 95};


int _bsearch(char *haystack, int left, int right, char needle) {
    int mid = (left + right) / 2;
    printf("%d, %d, %d\n", left, mid, right);
    if (left == right) return -1;
    if (needle == haystack[mid]) return mid;
    if (needle > haystack[mid])
        return _bsearch(haystack, mid, right, needle);
    else
        return _bsearch(haystack, left, mid, needle);
}

int binary_search(char* haystack, size_t size, char needle) {
    return _bsearch(haystack, 0, size - 1, needle);
}

int main() {
    int found = binary_search(data, sizeof(data)/sizeof(data[0]), 79);   
    if (found >= 0)
        printf("Found: %d\n", data[found]);
}