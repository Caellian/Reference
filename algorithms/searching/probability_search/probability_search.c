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
