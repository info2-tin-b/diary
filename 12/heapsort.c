#include <stdio.h>
#include <math.h>

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void printTreeRecursive(int array[], int n, int index, int level) {
    if (index >= n) return;
    printTreeRecursive(array, n, 2 * index + 2, level + 1);
    for (int i = 0; i < level * 6; i++)
        printf(" ");
    printf("%d\n", array[index]);
    printTreeRecursive(array, n, 2 * index + 1, level + 1);
}

void printTree(int array[], int n) {
    printTreeRecursive(array, n, 0, 0);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int n, int i, int N) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest, N);
    }

    if (N > 0)
        printTree(array, N);
}

void heapSort(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i, 0);

    for (int i = n - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0, n);
    }
}

int main() {
    int array[] = {8,4,12,20,6,42,14,11,3,35,7,9,11,50,1};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    printArray(array, n);

    printf("\nTree representation:\n");
    printTree(array, n);

    heapSort(array, n);

    printf("\nSorted array:\n");
    printArray(array, n);
}
