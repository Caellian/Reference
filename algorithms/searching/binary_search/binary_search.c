
int binary_search_impl(int a[], int first, int last, int el) {
  int mid = ((int) (first + last)) / 2;

  if (last - first == 1) {
    return -1;
  } else if (a[mid] == el) {
    return mid;
  } else if (a[mid] > el) {
    return binary_search_impl(a, first, mid, el);
  } else if (a[mid] < el) {
    return binary_search_impl(a, mid, last, el);
  } else {
    return -1;
  }
}

int binary_search_i(int a[], int last, int el) {
  return binary_search_impl(a, 0, last, el);
}
