void selection_sort(int a[], int n) {
  int i, j, min, tmp;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    tmp = a[min];
    a[min] = a[i];
    a[i] = tmp;
  }
}
