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
