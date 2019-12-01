# [Selection sort​](https://en.wikipedia.org/wiki/Selection_sort)

**Type:** Selection sort (Comparison sort)

## Performance

| Operation   | Worst  | Average |  Best  |
| :---------- | :----: | :-----: | :----: |
| Comparisons | O(n^2) | Θ(n^2)  | Ω(n^2) |

**Space complexity:** O(1)

## Use cases

- Quick and simple code implementation is needed

**Standard language sort function (if one exists) should be used instead of this algorithm as it's very slow.**

## Implementation

### C++

```c++
#include <algorithm>

template <class ForwardIt>
void selection_sort(ForwardIt first, ForwardIt last) {
  for (auto it = first; it != last; it++) {
    auto min = std::min_element(it, last);
    std::swap(*min, *it);
  }
}
```

### C

```c
void selection_sort(int a[], int n) {
  int i, j, min, tmp;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    tmp = a[min];
    a[min] = a[i];
    a[i] = tmp;
  }
}
```
