# Probability search

Probability search is a self-optimizing linear search implementation which moves queried element towards the beginning of the collection every time it is found.

**Time complexity:** O(n)

## Use cases

- Some elements are searched for more often than others.

## Requirements

- Searched data can be mutated

## Implementation

### C

```c
int probability_search(int a[], int n, int el) {
  int i, tmp;
  for (i = 0; a[i] != el && i < n; i++);

  if (el == a[i]) {
    if (i > 0) {
      tmp = a[i];
      a[i] = a[i-1];
      i--;
      a[i] = tmp;
    }
    return i;
  } else {
    return -1;
  }
}
```
