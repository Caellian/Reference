# [Heapsort](https://en.wikipedia.org/wiki/Heapsort)

**Type:** Selection sort (Comparison sort)

## Performance

| Operation   |   Worst    |  Average   |    Best    |
| :---------- | :--------: | :--------: | :--------: |
| Comparisons | O(n log n) | Θ(n log n) | Ω(n log n) |

**Size complexity:** O(1)

## Use cases

- Stable sort isn't needed
- Worst case performance is more important than average case performance.
- Inputs of very large but not specific size

## Implementation

### C++

```c++
#include <utility>
#include <iterator>

template <class RandomAccessIt>
void heapify(RandomAccessIt first, RandomAccessIt last, RandomAccessIt from) {
  auto largest = from;

  if (2 * std::distance(first, from) + 1 < std::distance(first, last)) {
    auto l = first + (2 * std::distance(first, from) + 1);

    if (*l > *largest) {
      largest = l;
    }
  }

  if (2 * std::distance(first, from) + 2 < last - first) {
    auto r = first + (2 * std::distance(first, from) + 2);

    if (*r > *largest) {
      largest = r;
    }
  }

  if (largest != from) {
    std::swap(*from, *largest);
    heapify(first, last, largest);
  }
}

template <class RandomAccessIt>
void heapsort(RandomAccessIt first, RandomAccessIt last) {
  for (auto it = first + (std::distance(first, last) / 2 - 1); it >= first; it--) {
    heapify(first, last, it);
  }

  for (auto it = last - 1; it >= first; it--) {
    std::swap(*first, *it);
    heapify(first, it, first);
  }
}
```

### C

```c
void heapify(int *a, int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int tmp;

  if (l < n && a[l] > a[largest]) {
    largest = l;
  }

  if (r < n && a[r] > a[largest]) {
    largest = r;
  }

  if (largest != i) {
    tmp = a[i];
    a[i] = a[largest];
    a[largest] = tmp;
    heapify(a, n, largest);
  }
}

void heapsort(int *a, int n) {
  int i, tmp;
  for(i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i);
  }

  for(i = n - 1; i >= 0; i--) {
    tmp = a[0];
    a[0] = a[i];
    a[i] = tmp;
    heapify(a, i, 0);
  }
}
```
