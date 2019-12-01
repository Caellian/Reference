# [Quicksort](https://en.wikipedia.org/wiki/Quicksort)

**Type:** Exchange sort (Comparison sort)

## Performance

| Operation   | Worst  |  Average   |    Best    |
| :---------- | :----: | :--------: | :--------: |
| Comparisons | O(n^2) | Θ(n log n) | Ω(n log n) |

**Space complexity:** O(log n)

## Use cases

- Stable sort is not needed
- Average case performance is more important than worst case performance

## Implementation

### C++

```c++
#include <algorithm>
#include <iterator>

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last)
{
  if(first == last) return;
  auto pivot = *std::next(first, std::distance(first, last)/2);
  ForwardIt middle1 = std::partition(first, last, [pivot](const auto& em){ return em < pivot; });
  ForwardIt middle2 = std::partition(middle1, last, [pivot](const auto& em){ return !(pivot < em); });
  quicksort(first, middle1);
  quicksort(middle2, last);
}
```

### C

```c
#include <stdlib.h>

/*
  Example shuffle method. Only effective if n is much
  smaller than RAND_MAX. Use a better implementation.
*/
void shuffle(int *a, size_t n)
{
  size_t i, j;
  int buff;
  if (n > 1)
  {
    for (i = 0; i < n - 1; i++)
    {
      j = i + rand() / (RAND_MAX / (n - i) + 1);
      buff = a[j];
      a[j] = a[i];
      a[i] = buff;
    }
  }
}

int partition(int *a, size_t lo, size_t hi)
{
  // Partition into a[lo..i-1], a[i], a[i+1..hi]
  
  int i = lo, j = hi+1;         // left and right scan indices
  int v = a[lo];                // partitioning item
  int buff;
  while (true)
  { // Scan right, scan left, check for scan complete, and swap.
    while (a[++i] < v) if (i == hi) break;
    while (v < a[--j]) if (j == lo) break;
    if (i >= j) break;
    buff = a[i];
    a[i] = a[j];
    a[j] = buff;
  }
  
  // Put v = a[j] into position with a[lo..j-1] <= a[j] <= a[j+1..hi].
  buff = a[lo];
  a[lo] = a[j];
  a[j] = buff;
  return j;
}

void quicksort(int *a, size_t lo, size_t hi)
{
  if (hi <= lo) return;
  int j = partition(a, lo, hi);
}

void quicksort(int *a, size_t n)
{
  shuffle(a, n);
  quicksort(a, 0, n);
}
```

### Java

```java
public static void quicksort(int[] a) {
  StdRandom.shuffle(a);          // Eliminate dependence on input.
  quicksort(a, 0, a.length - 1);
}

private static void quicksort(int[] a, int lo, int hi) {
  if (hi <= lo) return;
  int j = partition(a, lo, hi);  // Partition (see page 291).
  quicksort(a, lo, j-1);              // Sort left part a[lo .. j-1].
  quicksort(a, j+1, hi);              // Sort right part a[j+1 .. hi].
}

private static int partition(int[] a, int lo, int hi) {
  // Partition into a[lo..i-1], a[i], a[i+1..hi].
  
  int i = lo, j = hi+1;         // left and right scan indices
  int v = a[lo];                // partitioning item
  int buff;
  while (true) { // Scan right, scan left, check for scan complete, and swap.
    while (a[++i] < v) if (i == hi) break;
    while (v < a[--j]) if (j == lo) break;
    if (i >= j) break;
    buff = a[i];
    a[i] = a[j];
    a[j] = buff;
  }
  
  // Put v = a[j] into position with a[lo..j-1] <= a[j] <= a[j+1..hi].
  buff = a[lo];
  a[lo] = a[j];
  a[j] = buff;
  return j;
}
```
