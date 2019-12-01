# Linear search

Iterates over entire data structure in order to find queried element.

**Time complexity:** O(n)

## Implementation

### C++

Use [`std::find(InputIterator first, InputIterator last, const T& val)`](http://www.cplusplus.com/reference/algorithm/find/) method from `<algorithm>` header.

### C

```c
int linear_search(int a[], int n, int el) {
  int i;
  for(i = 0; i < n; i++) {
    if (a[i] == el) return i;
  }
  return -1;
}
```
