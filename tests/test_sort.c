/* Sorting algorithm tests
 * 실행: make test-c
 */

#include <stdio.h>
#include <string.h>
#include "sort.h"

static int checks = 0;
static int failures = 0;

typedef void (*SortFunction)(int[], int);

static void printArray(const char *label, const int a[], int n)
{
    printf("    %s:", label);

    for (int i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }

    printf("\n");
}

static void expectSorted(
    const char *algorithm,
    const char *testName,
    SortFunction sortFunction,
    int input[],
    const int want[],
    int n)
{
    checks++;

    sortFunction(input, n);

    if (n > 0 &&
        memcmp(input, want, (size_t)n * sizeof(int)) != 0) {

        failures++;
        printf("FAIL  %s - %s\n", algorithm, testName);
        printArray("got ", input, n);
        printArray("want", want, n);
        return;
    }

    printf("OK    %-10s - %s\n", algorithm, testName);
}

static void runTests(const char *algorithm, SortFunction sortFunction)
{
    {
        int a[] = {6, 8, 5, 9, 10, 1, 7, 2, 4, 3};
        const int want[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        expectSorted(
            algorithm, "random array",
            sortFunction, a, want, 10);
    }

    {
        int a[] = {1, 2, 3, 4, 5};
        const int want[] = {1, 2, 3, 4, 5};

        expectSorted(
            algorithm, "sorted array",
            sortFunction, a, want, 5);
    }

    {
        int a[] = {5, 4, 3, 2, 1};
        const int want[] = {1, 2, 3, 4, 5};

        expectSorted(
            algorithm, "reverse array",
            sortFunction, a, want, 5);
    }

    {
        int a[] = {3, 1, 3, 1, 2};
        const int want[] = {1, 1, 2, 3, 3};

        expectSorted(
            algorithm, "duplicate values",
            sortFunction, a, want, 5);
    }

    {
        int a[] = {42};
        const int want[] = {42};

        expectSorted(
            algorithm, "single element",
            sortFunction, a, want, 1);
    }

    {
        int a[1] = {0};
        const int want[1] = {0};

        expectSorted(
            algorithm, "empty array",
            sortFunction, a, want, 0);
    }
}

int main(void)
{
    printf("\n=== Merge Sort Tests ===\n");
    runTests("Merge Sort", mergeSort);

    printf("\n=== Quick Sort Tests ===\n");
    runTests("Quick Sort", quickSort);

    printf("\n=== Heap Sort Tests ===\n");
    runTests("Heap Sort", heapSort);

    printf("\n%d checks, %d failures\n", checks, failures);

    return failures == 0 ? 0 : 1;
}
