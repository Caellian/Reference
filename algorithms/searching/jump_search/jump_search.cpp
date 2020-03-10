#include <cmath>

// Implementation for random access iterators

template <class RandomAccessIt, class T>
int jump_search_ra(RandomAccessIt first, RandomAccessIt last, const T &el) {
  const int step = std::sqrt(last - first);
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

// Implementation for forward iterators

template <class ForwardIt, class T>
int jump_search_fw(ForwardIt first, ForwardIt last, const T &el) {
  const int step = std::sqrt(last - first);
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
