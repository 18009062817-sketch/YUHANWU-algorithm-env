# Sorting Algorithms Implementation and Performance Comparison

**Name:** YUHAN WU
**Student ID:** 2025193028
**GitHub Repository:** https://github.com/18009062817-sketch/YUHANWU-algorithm-env
---

## 1. Introduction

This project implements and compares three sorting algorithms in C: Merge Sort, Quick Sort, and Heap Sort.

The purpose of this project is to understand how each sorting algorithm works and to compare their performance with different input sizes and input conditions.

The algorithms were tested using random, already sorted, and reverse-sorted arrays.


## 2. Implemented Algorithms

### 2.1 Merge Sort

Merge Sort divides an array into smaller subarrays, sorts them recursively, and merges the sorted subarrays.

### 2.2 Quick Sort

Quick Sort selects a pivot and partitions the array into smaller and larger elements. The same process is recursively applied to the partitions.

### 2.3 Heap Sort

Heap Sort builds a heap from the input array and repeatedly moves the largest element to its correct position.
---

## 3. Correctness Test

The implementations were tested with several different input cases, including:

- Random array
- Already sorted array
- Reverse-sorted array
- Array with duplicate values
- Single-element array
- Empty array

All three algorithms passed the tests successfully.

Test result:

18 checks, 0 failures
---

## 4. Performance Experiment

The performance of Merge Sort, Quick Sort, and Heap Sort was measured using three different input sizes:

- n = 1,000
- n = 5,000
- n = 10,000

For each size, three types of input were tested:

- Random
- Sorted
- Reverse

The execution time was measured in milliseconds (ms).
Each benchmark case was executed 10 times, and the average execution time was used as the final result.
---

## 5. Experimental Results

## 5. Experimental Results

### 5.1 n = 1,000

| Input Type | Merge Sort (ms) | Quick Sort (ms) | Heap Sort (ms) |
|---|---:|---:|---:|
| Random | 0.037 | 0.027 | 0.055 |
| Sorted | 0.027 | 0.511 | 0.051 |
| Reverse | 0.024 | 0.672 | 0.050 |

### 5.2 n = 5,000

| Input Type | Merge Sort (ms) | Quick Sort (ms) | Heap Sort (ms) |
|---|---:|---:|---:|
| Random | 0.367 | 0.264 | 0.419 |
| Sorted | 0.151 | 9.897 | 0.307 |
| Reverse | 0.131 | 11.009 | 0.259 |

### 5.3 n = 10,000

| Input Type | Merge Sort (ms) | Quick Sort (ms) | Heap Sort (ms) |
|---|---:|---:|---:|
| Random | 0.625 | 0.577 | 0.691 |
| Sorted | 0.172 | 37.137 | 0.493 |
| Reverse | 0.158 | 46.231 | 0.521 |

The measured execution time may vary slightly between runs depending on the system environment and current workload.
---

## 6. Result Analysis

### 6.1 Random Input

For random input, the execution times of the three algorithms were relatively similar.

At n = 10,000, Quick Sort took 0.577 ms, Merge Sort took 0.625 ms, and Heap Sort took 0.691 ms. In this experiment, Quick Sort showed the shortest execution time for random data.

The Quick Sort implementation in this project uses the last element of the array as the pivot. When the input is random, this pivot usually does not produce extremely unbalanced partitions. Therefore, the recursion can remain relatively balanced and the algorithm performs close to its average time complexity of O(n log n).

Merge Sort also showed stable performance. The use of a temporary array introduces additional memory operations, which may be one reason why Merge Sort was slightly slower than Quick Sort for random input in this experiment.

Heap Sort was also stable, but it was generally slower than the other two algorithms for random input. Heap Sort repeatedly performs `heapify` operations and accesses elements using parent-child index relationships. Although its theoretical time complexity is O(n log n), these operations can have a larger constant cost in practice.

### 6.2 Sorted Input

The largest difference appeared with already sorted input.

For n = 1,000, Quick Sort took 0.511 ms. When the input size increased to 5,000, the time increased to 9.897 ms, and at n = 10,000 it increased to 37.137 ms.

This result is directly related to the pivot selection used in my Quick Sort implementation.

The pivot is selected as:

```c
int pivot = a[high];
```

In other words, the last element is always used as the pivot.

For an already sorted array such as:

```text
1 2 3 4 5 6 7 8 9 10
```

the last element is also the largest element. Therefore, after partitioning, almost all elements remain on one side of the pivot.

Instead of dividing the array approximately in half,

```text
n
→ n/2 + n/2
```

the partition becomes similar to:

```text
n
→ (n - 1) + 0
→ (n - 2) + 0
→ (n - 3) + 0
→ ...
```

As a result, the recursion becomes highly unbalanced and Quick Sort approaches its worst-case time complexity of O(n²).

This behavior can be clearly observed in the experimental results. When n increased from 5,000 to 10,000, the Quick Sort execution time increased from 9.897 ms to 37.137 ms, which is much larger than the increase observed for Merge Sort or Heap Sort.

### 6.3 Reverse-Sorted Input

A similar problem appeared for reverse-sorted input.

At n = 10,000, the execution times were:

- Merge Sort: 0.158 ms
- Quick Sort: 46.231 ms
- Heap Sort: 0.521 ms

Quick Sort was much slower than the other two algorithms.

For example, consider a reverse-sorted array:

```text
10 9 8 7 6 5 4 3 2 1
```

Because my implementation selects the last element as the pivot, the first pivot in this example is `1`, which is the smallest element.

After partitioning, almost all of the remaining elements are placed on one side of the pivot. The same problem then happens again in the next recursive call. Therefore, the partitions remain very unbalanced and the running time approaches O(n²).

This explains why Quick Sort increased from 0.672 ms at n = 1,000 to 11.009 ms at n = 5,000 and 46.231 ms at n = 10,000 for reverse-sorted input.

The result is similar to the sorted-input case, although the measured times are not exactly the same. This is reasonable because actual execution time can change slightly depending on operations such as swaps, memory access, and the execution environment.

### 6.4 Merge Sort and Heap Sort

Unlike Quick Sort, Merge Sort and Heap Sort did not show a large performance difference between random, sorted, and reverse-sorted input.

For example, at n = 10,000, Merge Sort took 0.625 ms for random input, 0.172 ms for sorted input, and 0.158 ms for reverse input. Heap Sort took 0.691 ms, 0.493 ms, and 0.521 ms respectively.

Merge Sort always divides the array according to its position, so the initial order of the elements does not cause extremely unbalanced recursive calls. Its time complexity remains O(n log n).

Heap Sort also maintains O(n log n) time complexity for these input cases. Its execution time was not the shortest in most of my tests, but it remained relatively stable when the input order changed.

From these results, I found that Quick Sort can be very fast when the partitions are balanced, but its performance depends strongly on how the pivot is selected. Merge Sort and Heap Sort were more consistent in this experiment.


## 7. Learning Heap Sort with AI

Heap Sort was the sorting algorithm that I had not learned in class. Therefore, before implementing it, I used AI to understand its basic structure and the role of the heap.

At first, the most confusing part for me was how a tree-shaped heap could be implemented using an ordinary array. I originally thought that a separate tree data structure would be necessary.

Through AI, I learned that a binary heap can be represented directly in an array. For an element located at index `i`, the positions of its children can be calculated as:

```text
left child  = 2 * i + 1
right child = 2 * i + 2
```

For example, if the array is:

```text
10 8 7 5 3
```

it can be viewed as the following tree:

```text
        10
       /  \
      8    7
     / \
    5   3
```

This made the heap structure easier for me to understand because it showed that a separate tree object is not required.

### 7.1 Max Heap

The next concept I learned was the max heap.

In a max heap, every parent is greater than or equal to its children. Therefore, the largest element is always located at the root of the heap.

Heap Sort uses this property to repeatedly move the largest remaining element to the end of the array.

The overall process can be summarized as:

1. Convert the input array into a max heap.
2. Swap the root element with the last element of the heap.
3. Reduce the effective heap size by one.
4. Restore the max-heap property using `heapify`.
5. Repeat the process until the array is sorted.

### 7.2 Understanding `heapify`

The most important function in my Heap Sort implementation is:

```c
static void heapify(int a[], int n, int root)
```

Inside this function, the current root is compared with its left and right children.

The child indices are calculated as:

```c
int left = 2 * root + 1;
int right = 2 * root + 2;
```

The function first finds the largest value among the root, left child, and right child.

If one of the children is larger than the root, the two values are swapped. Then `heapify` is called again from the new position.

This process restores the max-heap property.

The main Heap Sort function first builds the heap:

```c
for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i);
}
```

After that, the root is repeatedly exchanged with the last element:

```c
for (int i = n - 1; i > 0; i--) {
    swap(&a[0], &a[i]);
    heapify(a, i, 0);
}
```

After learning these two parts, I was able to understand why Heap Sort produces an ascending array.

### 7.3 What I Learned from AI

AI was especially useful for explaining the relationship between the array index and the binary-tree structure.

Before this assignment, expressions such as `2 * i + 1` and `2 * i + 2` looked like formulas that had to be memorized. After seeing the heap represented as both an array and a tree, I understood where these formulas came from.

I also learned that Heap Sort has O(n log n) worst-case time complexity. Unlike Merge Sort, it does not require a separate temporary array of size n.

However, Heap Sort is not stable. In addition, my implementation uses recursive `heapify`, so it can use O(log n) call-stack space even though the array itself is sorted in place.

After studying the algorithm with AI, I verified the implementation using the same tests as the other sorting algorithms. Heap Sort successfully handled random, already sorted, reverse-sorted, duplicate, single-element, and empty inputs.

This process was more useful than simply receiving the completed code because I could connect the heap structure, array indices, and actual implementation.
---


## 8. Theoretical Comparison

The theoretical characteristics of the three sorting algorithms are summarized below.

| Algorithm | Best Time | Average Time | Worst Time | Auxiliary Space | Stable |
|---|---:|---:|---:|---:|---|
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) average, O(n) worst | No |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(log n) in this recursive implementation | No |

### 8.1 Merge Sort

Merge Sort has O(n log n) time complexity regardless of the initial order of the data.

Its main disadvantage is additional memory usage. In my implementation, a temporary array is dynamically allocated:

```c
int *temp = malloc(sizeof(int) * n);
```

Therefore, the algorithm requires O(n) additional array space.

My Merge Sort implementation is stable because the merge step chooses the left-side element first when two values are equal:

```c
if (a[i] <= a[j])
```

### 8.2 Quick Sort

Quick Sort has an average time complexity of O(n log n), but its worst-case complexity is O(n²).

The experimental results showed this difference clearly.

My implementation always selects the last element as the pivot:

```c
int pivot = a[high];
```

This strategy worked well for random input, but it produced very unbalanced partitions for already sorted and reverse-sorted arrays.

Therefore, Quick Sort showed both the shortest execution time in some random-input tests and the longest execution time in the sorted and reverse-sorted tests.

This was the clearest example in this assignment of how an implementation detail can strongly affect actual algorithm performance.

### 8.3 Heap Sort

Heap Sort guarantees O(n log n) time complexity even in the worst case.

Unlike Merge Sort, it does not allocate another array of size n. The elements are rearranged inside the original array.

However, Heap Sort is not stable because elements with the same value can change their original relative order during heap construction and swapping.

In my experiment, Heap Sort was not usually the fastest algorithm, but its execution time remained much more consistent than Quick Sort when the input order changed.
---


## 9. Conclusion

In this assignment, I implemented and compared Merge Sort, Quick Sort, and Heap Sort.

Before the experiment, I expected the three O(n log n) algorithms to show relatively similar results. However, the actual experiment showed that the input order and implementation method can have a large effect on execution time.

For random input, Quick Sort showed very good performance. At n = 10,000, Quick Sort took 0.577 ms, compared with 0.625 ms for Merge Sort and 0.691 ms for Heap Sort.

However, the result changed significantly for already sorted and reverse-sorted input.

For sorted input with n = 10,000, Quick Sort required 37.137 ms, while Merge Sort required 0.172 ms and Heap Sort required 0.493 ms.

For reverse-sorted input with n = 10,000, Quick Sort required 46.231 ms, while Merge Sort required 0.158 ms and Heap Sort required 0.521 ms.

The main reason was the pivot strategy used in my Quick Sort implementation. Since the last element was always selected as the pivot, sorted and reverse-sorted arrays produced highly unbalanced partitions.

Merge Sort and Heap Sort were less affected by the original order of the input. Merge Sort showed stable execution time, but it required an additional temporary array. Heap Sort did not require this additional array and guaranteed O(n log n) worst-case time, although it was not the fastest algorithm in most of the measured cases.

I also learned Heap Sort for the first time through this assignment. Using AI helped me understand how the binary heap is represented inside an array and how `heapify` works.

The most important thing I learned from this experiment is that comparing algorithms only by Big-O notation is not enough. The input data, implementation details, memory usage, and algorithm design can all affect the actual result.
---


## 10. Reproducibility

The correctness tests can be executed with:

```bash
make test-c
```

The benchmark can be executed with:

```bash
make bench
```

The benchmark uses input sizes of 1,000, 5,000, and 10,000 with Random, Sorted, and Reverse input conditions.

The measured benchmark results are saved in:

```text
src/benchmark.csv
```

Because execution time can vary depending on system workload, the values in this report represent the results measured in my execution environment.
---

## 11. Files

The main files used in this assignment are:

```text
src/
├── main.c
├── sort.c
├── sort.h
├── bench.c
└── benchmark.csv

tests/
└── test_sort.c
```

`sort.c` contains the implementations of Merge Sort, Quick Sort, and Heap Sort.

`main.c` checks the basic output of the three sorting algorithms.

`test_sort.c` checks algorithm correctness using several input conditions.

`bench.c` measures execution time for different input sizes and input orders.

`benchmark.csv` stores the benchmark results.
---


## 12. GitHub Repository

The complete source code is available at:

https://github.com/18009062817-sketch/YUHANWU-algorithm-env
---


## 13. References

1. Course materials and examples provided in the Advanced Algorithms class.

2. Wikipedia, "Sorting algorithm – Comparison of algorithms."
   https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_of_algorithms

3. Wikipedia, "Heapsort."
   https://en.wikipedia.org/wiki/Heapsort

4. AI-assisted learning was used to understand the heap structure, array-index relationships, the `heapify` process, and differences between the three sorting algorithms. The implementation was then tested using the course environment and the experimental results were measured directly from the program.
