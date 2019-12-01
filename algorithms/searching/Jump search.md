# [Jump search](https://en.wikipedia.org/wiki/Jump_search)

Jump search finds a given element in collection by making small jumps

**Time complexity:** O(√n)

## Requirements

- Collection is sorted

## Implementation

### C++

#### Random Access Iterator

```c++
#include <cmath>

template <class RandomAccessIt, class T>
int jump_search(RandomAccessIt first, RandomAccessIt last, const T &el) {
  const int step = sqrt(last - first);
  auto curr = first;
  auto after = curr;

  after += step;

  while (*after < el && after != last) {
    curr += step;
    after += step;
  }

  while (*curr < el && curr != after) {
    curr++;
  }
  if (curr == last || *curr != el)
    return -1;

  return curr - first;
}
```

#### Forward Iterator

```c++
#include <cmath>

template <class ForwardIt, class T>
int jump_search(ForwardIt first, ForwardIt last, const T &el) {
  const int step = sqrt(last - first);
  auto curr = first;
  auto after = curr;

  int steps = step;
  while (steps > 0) {
    steps--;
    after++;
  }
  
  while (*after < el && after != last) {
    steps = step;
    while (steps > 0) {
      steps--;
      curr++;
      after++;
    }
  }

  while (*curr < el && curr != after) {
    curr++;
  }
  if (curr == last || *curr != el)
    return -1;

  return curr - first;
}
```
