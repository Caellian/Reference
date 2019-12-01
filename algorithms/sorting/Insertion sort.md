# [Insertion sort​](https://en.wikipedia.org/wiki/Insertion_sort)

**Type:** Insertion sort (Comparison sort)

## Performance

| Operation   | Worst  | Average | Best |
| :---------- | :----: | :-----: | :--: |
| Comparisons | O(n^2) | Θ(n^2)  | Ω(n) |
| Swaps       | O(n^2) | Θ(n^2)  | Ω(1) |

**Space complexity:** O(n) total, O(1) auxiliary

## Use cases

- Quick and simple code implementation is needed
- Sorting of small data sets
- Stable sort is needed

_This algorithm is more efficient in practice than other simple quadratic sorting algorithms such as bubble sort or selection sort._

## Implementation

### C++

```c++
#include <algorithm>

template <class ForwardIt>
void insertion_sort(ForwardIt first, ForwardIt last) {
  for (auto it = first; it != last; ++it)
    std::rotate(std::upper_bound(first, it, *it), it, std::next(it));
}
```

### C

```c
void insertion_sort(int a[], int n) {
  int i, j, tmp;

  for (i = 1; i < n; i++) {
    tmp = a[i];
    j = i - 1;

    while (j >= 0 && a[j] > tmp) {
      a[j + 1] = a[j];
      j--;
    }

    a[j + 1] = tmp;
  }
}
```
