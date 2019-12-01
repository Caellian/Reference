# [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) (a.k.a. Sinking sort)

**Type:** Exchange sort (Comparison sort)

## Performance

| Operation   | Worst  | Average | Best |
| :---------- | :----: | :-----: | :--: |
| Comparisons | O(n^2) | Θ(n^2)  | Ω(n) |
| Swaps       | O(n^2) | Θ(n^2)  | Ω(1) |

**Space complexity:** O(1)

## Use cases

- Quick and simple code implementation is needed
- Input is in mostly sorted order and some out-of-order elements are nearly in position.

Standard language sort function (if one exists) should be used instead of this algorithm as it's very slow.

## Implementation

### C++

```c++
#include <utility>

template <class ForwardIt> void bubble_sort(ForwardIt first, ForwardIt last) {
  bool swapped = false;
  do {
    swapped = false;
    for (auto it = first; it < last; it++) {
      auto next = it;
      next++;
      if (next != last && *it > *next) {
        std::swap(*it, *next);
        swapped = true;
      }
    }
  } while (swapped);
}
```

### C

```c
#include <stdbool.h>

void bubble_sort(int *a, int n) {
  int i, j, tmp;
  bool swapped;
  for (i = 0; i < n - 1; i++) {
    swapped = FALSE;
    for (j = 0; j < n - i - 1; j++) {
      if (a[j] < a[j + 1]) {
        tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
        swapped = TRUE;
      }
    }

    if (swapped == FALSE) {
      break;
    }
  }
}
```
