public static void quicksort(int[] a) {
  StdRandom.shuffle(a);          // Eliminate dependence on input.
  quicksort(a, 0, a.length - 1);
}

private static void quicksort(int[] a, int lo, int hi) {
  if (hi <= lo) return;
  int j = partition(a, lo, hi);  // Partition (see page 291).
  quicksort(a, lo, j-1);              // Sort left part a[lo .. j-1].
  quicksort(a, j+1, hi);              // Sort right part a[j+1 .. hi].
}

private static int partition(int[] a, int lo, int hi) {
  // Partition into a[lo..i-1], a[i], a[i+1..hi].
  
  int i = lo, j = hi+1;         // left and right scan indices
  int v = a[lo];                // partitioning item
  int buff;
  while (true) { // Scan right, scan left, check for scan complete, and swap.
    while (a[++i] < v) if (i == hi) break;
    while (v < a[--j]) if (j == lo) break;
    if (i >= j) break;
    buff = a[i];
    a[i] = a[j];
    a[j] = buff;
  }
  
  // Put v = a[j] into position with a[lo..j-1] <= a[j] <= a[j+1..hi].
  buff = a[lo];
  a[lo] = a[j];
  a[j] = buff;
  return j;
}
