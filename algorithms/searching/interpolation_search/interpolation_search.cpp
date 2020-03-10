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
