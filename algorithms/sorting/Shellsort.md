# [Shellsort​](https://en.wikipedia.org/wiki/Shellsort)

**Type:** Insertion sort (Comparison sort)

## Performance

| Operation   |     Worst     |    Average    |    Best    |
| :---------- | :-----------: | :-----------: | :--------: |
| Comparisons | O(n log(n)^2) | Θ(n log(n)^2) | Ω(n log n) |

_Actual time complexity of shell sort is highly dependant on gap distance. Above table shows estimated time complexity._

**Space complexity:** O(1)

## Use cases

- Simplicity of implementation is wanted

## Requirements

- Collection has random access

## Implementation

### C++

```c++
template <class BidirectionalIt>
void shellsort(BidirectionalIt first, BidirectionalIt last) {
  for (size_t gap = std::distance(first, last) / 2; gap > 0; gap /= 2) {
    for (auto it = std::next(first, gap); it != last; it++) {
      typename std::iterator_traits<BidirectionalIt>::value_type tmp = *it;
      auto i = it;
      while (std::distance(first, i) >= gap && *std::prev(i, gap) > tmp) {
        *i = *std::prev(i, gap);
        i = std::prev(i, gap);
      }
      *i = tmp;
    }
  }
}
```

### C

```c
void shellsort(int a[], int n) {
  int i, j, gap, tmp;
  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      tmp = a[i];
      for (j = i; j >= gap && a[j - gap] > tmp; j -= gap)
        a[j] = a[j - gap];
      a[j] = tmp;
    }
  }
}
```
