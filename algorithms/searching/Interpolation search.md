# [Interpolation search](https://en.wikipedia.org/wiki/Interpolation_search)

Interpolation search is a modified version of binary search where data received by failed search probes is used to _interpolate_ position of queried element.

## Performance

| Operation   | Worst | Average  |     Best     |
| :---------- | :---: | :------: | :----------: |
| Comparisons | O(n)  | Θ(log n) | Ω(log log n) |

Under the assumption of a uniform distribution of the data on the linear scale used for interpolation, interpretation search can perform in **O(log log n)**.

## Use cases

- Sorted but unindexed on-disk datasets

## Requirements

- Collection is sorted
- Collection data is uniformly distributed (to avoid worst case complexity)

## Implementation

### C++

```c++
template <typename RandomAccessIt, class T>
int interpolation_search(RandomAccessIt first, RandomAccessIt last,
                         const T &el) {
  size_t low = 0;
  size_t high = last - first - 1;

  while (*(first + high) != *(first + low) && el >= *(first + low) &&
         el <= *(first + high)) {
    size_t mid = low + ((el - *(first + low)) * (high - low) /
                        (*(first + high) - *(first + low)));

    if (*(first + mid) < el)
      low = mid + 1;
    else if (el < *(first + mid))
      high = mid - 1;
    else
      return mid;
  }

  if (el == *(first + low))
    return low;
  else
    return -1;
}
```

### C

```c
int interpolation_search(int a[], int n, int el) {
  int lo = 0, hi = (n - 1);

  while (lo <= hi && el >= a[lo] && el <= a[hi]) {
    if (lo == hi) {
      if (a[lo] == el)
        return lo;
      return -1;
    }

    int pos = lo + (((double)(hi - lo) / (a[hi] - arr[lo])) * (el - a[lo]));

    if (a[pos] == el)
      return pos;

    if (a[pos] < el) {
      lo = pos + 1;
    } else {
      hi = pos - 1;
    }
  }
  return -1;
}
```
