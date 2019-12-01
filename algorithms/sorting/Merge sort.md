# [Merge sort​](https://en.wikipedia.org/wiki/Merge_sort)

**Type:** Merge sort (Comparison sort)

## Performance

| Operation   |   Worst    |  Average   |    Best    |
| :---------- | :--------: | :--------: | :--------: |
| Comparisons | O(n log n) | Θ(n log n) | Ω(n log n) |

**Space complexity:** O(n)

## Use cases

- Sorted data structure does not allow random access (linked list)

## Implementation

### C++

```c++
#include <vector>

template <class ForwardIterator, class T>
void merge(ForwardIt first, ForwardIt mid, ForwardIt last) {
  size_t ls = mid - first;
  size_t rs = last - mid;

  std::vector<T> left(ls);
  std::vector<T> right(rs);

  std::copy_n(first, ls, left.begin());
  std::copy_n(mid, rs, right.begin());

  size_t i = 0, j = 0;
  auto k = first;
  while (i < ls && j < rs) {
    if (left[i] <= right[j]) {
      *k = left[i++];
    } else {
      *k = right[j++];
    }
    k++;
  }

  if (i < ls)
    std::copy_n(left.begin() + i, ls - i, k);
  if (j < rs)
    std::copy_n(right.begin() + j, rs - j, k);
}

template <class ForwardIt> void merge_sort(ForwardIt first, ForwardIt last) {
  auto afterFirst = first;
  afterFirst++;
  if (afterFirst != last) {
    auto mid = first + (last - first) / 2;

    merge_sort(first, mid);
    merge_sort(mid, last);

    merge(first, mid, last);
  }
}
```

### C

```c
void merge(int a[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int left[n1], right[n2];

  for (int i = 0; i < n1; i++) {
    left[i] = a[l + i];
  }

  for (int i = 0; i < n2; i++) {
    right[j] = a[m + 1 + i];
  }

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      a[k++] = left[i++];
    } else {
      a[k++] = right[j++];
    }
  }

  while (i < n1) {
    a[k++] = left[i++];
  }

  while (j < n2) {
    a[k++] = right[j++];
  }
}

void mergeSort(int a[], int l, int r) {
  if (l < r) {
    int m = l+(r-l)/2;

    mergeSort(a, l, m);
    mergeSort(a, m+1, r);

    merge(a, l, m, r);
  }
}

void mergeSort(int a[], int n) {
  mergeSort(a, 0, n)
}
```
