void heapify(int *a, int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int tmp;

  if (l < n && a[l] > a[largest]) {
    largest = l;
  }

  if (r < n && a[r] > a[largest]) {
    largest = r;
  }

  if (largest != i) {
    tmp = a[i];
    a[i] = a[largest];
    a[largest] = tmp;
    heapify(a, n, largest);
  }
}

void heapsort(int *a, int n) {
  int i, tmp;
  for(i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i);
  }

  for(i = n - 1; i >= 0; i--) {
    tmp = a[0];
    a[0] = a[i];
    a[i] = tmp;
    heapify(a, i, 0);
  }
}
