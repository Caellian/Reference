void merge(int a[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int left[n1], right[n2];

  for (int i = 0; i < n1; i++) {
    left[i] = a[l + i];
  }

  for (int i = 0; i < n2; i++) {
    right[j] = a[m + 1 + i];
  }

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      a[k++] = left[i++];
    } else {
      a[k++] = right[j++];
    }
  }

  while (i < n1) {
    a[k++] = left[i++];
  }

  while (j < n2) {
    a[k++] = right[j++];
  }
}

void merge_sort(int a[], int l, int r) {
  if (l < r) {
    int m = l+(r-l)/2;

    merge_sort(a, l, m);
    merge_sort(a, m+1, r);

    merge(a, l, m, r);
  }
}

void merge_sort(int a[], int n) {
  merge_sort(a, 0, n)
}
