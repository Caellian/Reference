int linear_search(int a[], int n, int el) {
  int i;
  for(i = 0; i < n; i++) {
    if (a[i] == el) return i;
  }
  return -1;
}
