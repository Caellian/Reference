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
