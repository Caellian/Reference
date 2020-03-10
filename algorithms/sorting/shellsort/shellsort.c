void shellsort(int a[], int n) {
  int i, j, gap, tmp;
  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      tmp = a[i];
      for (j = i; j >= gap && a[j - gap] > tmp; j -= gap)
        a[j] = a[j - gap];
      a[j] = tmp;
    }
  }
}
