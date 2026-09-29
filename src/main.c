/* 실행: make run-c */
#include <stdio.h>
#include "sort.h"

static void printArray(const char *name, int a[], int n)
{
    printf("%s:", name);

    for (int i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }

    printf("\n");
}

int main(void)
{
    int original[] = {6, 8, 5, 9, 10, 1, 7, 2, 4, 3};
    int n = (int)(sizeof(original) / sizeof(original[0]));

    int mergeArray[] = {6, 8, 5, 9, 10, 1, 7, 2, 4, 3};
    int quickArray[] = {6, 8, 5, 9, 10, 1, 7, 2, 4, 3};
    int heapArray[] = {6, 8, 5, 9, 10, 1, 7, 2, 4, 3};

    printArray("Original", original, n);

    mergeSort(mergeArray, n);
    quickSort(quickArray, n);
    heapSort(heapArray, n);

    printArray("Merge Sort", mergeArray, n);
    printArray("Quick Sort", quickArray, n);
    printArray("Heap Sort ", heapArray, n);

    return 0;
}
