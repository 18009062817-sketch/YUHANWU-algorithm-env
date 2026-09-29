#include "sort.h"
#include <stdlib.h>

/* ---------------- Merge Sort ---------------- */

static void merge(int a[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (i = left; i <= right; i++) {
        a[i] = temp[i];
    }
}

static void mergeSortRecursive(int a[], int temp[], int left, int right)
{
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSortRecursive(a, temp, left, mid);
    mergeSortRecursive(a, temp, mid + 1, right);

    merge(a, temp, left, mid, right);
}

void mergeSort(int a[], int n)
{
    if (n <= 1) {
        return;
    }

    int *temp = malloc(sizeof(int) * n);

    if (temp == NULL) {
        return;
    }

    mergeSortRecursive(a, temp, 0, n - 1);

    free(temp);
}


/* ---------------- Quick Sort ---------------- */

static void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

static int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

static void quickSortRecursive(int a[], int low, int high)
{
    if (low < high) {
        int pivotIndex = partition(a, low, high);

        quickSortRecursive(a, low, pivotIndex - 1);
        quickSortRecursive(a, pivotIndex + 1, high);
    }
}

void quickSort(int a[], int n)
{
    if (n <= 1) {
        return;
    }

    quickSortRecursive(a, 0, n - 1);
}


/* ---------------- Heap Sort ---------------- */

static void heapify(int a[], int n, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != root) {
        swap(&a[root], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}
