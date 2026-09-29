#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"

typedef void (*SortFunction)(int[], int);

static void fillRandom(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100000;
    }
}

static void fillSorted(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
}

static void fillReverse(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        a[i] = n - i;
    }
}

static double measureTime(
    SortFunction sortFunction,
    const int original[],
    int n)
{
    int *copy = malloc((size_t)n * sizeof(int));

    if (copy == NULL) {
        return -1.0;
    }

    memcpy(copy, original, (size_t)n * sizeof(int));

    clock_t start = clock();

    sortFunction(copy, n);

    clock_t end = clock();

    free(copy);

    return (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
}

static void runCase(
    FILE *csv,
    const char *caseName,
    int original[],
    int n)
{
    double mergeTime = measureTime(mergeSort, original, n);
    double quickTime = measureTime(quickSort, original, n);
    double heapTime = measureTime(heapSort, original, n);

    printf("\n[%s] n = %d\n", caseName, n);
    printf("---------------------------------\n");
    printf("%-12s %12s\n", "Algorithm", "Time(ms)");
    printf("---------------------------------\n");

    printf("%-12s %12.3f\n", "Merge Sort", mergeTime);
    printf("%-12s %12.3f\n", "Quick Sort", quickTime);
    printf("%-12s %12.3f\n", "Heap Sort", heapTime);

    fprintf(csv, "%s,%d,Merge Sort,%.3f\n",
            caseName, n, mergeTime);

    fprintf(csv, "%s,%d,Quick Sort,%.3f\n",
            caseName, n, quickTime);

    fprintf(csv, "%s,%d,Heap Sort,%.3f\n",
            caseName, n, heapTime);
}

int main(void)
{
    const int sizes[] = {1000, 5000, 10000};
    const int sizeCount =
        (int)(sizeof(sizes) / sizeof(sizes[0]));

    FILE *csv = fopen("src/benchmark.csv", "w");

    if (csv == NULL) {
        fprintf(stderr, "Could not open benchmark.csv\n");
        return 1;
    }

    fprintf(csv, "InputType,Size,Algorithm,Time_ms\n");

    srand(42);

    for (int s = 0; s < sizeCount; s++) {
        int n = sizes[s];

        int *data = malloc((size_t)n * sizeof(int));

        if (data == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            fclose(csv);
            return 1;
        }

        fillRandom(data, n);
        runCase(csv, "Random", data, n);

        fillSorted(data, n);
        runCase(csv, "Sorted", data, n);

        fillReverse(data, n);
        runCase(csv, "Reverse", data, n);

        free(data);
    }

    fclose(csv);

    printf("\nBenchmark results saved to src/benchmark.csv\n");

    return 0;
}
