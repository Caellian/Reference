#include <stdlib.h>

/*
  Example shuffle method. Only effective if n is much
  smaller than RAND_MAX. Use a better implementation.
*/
void shuffle(int *a, size_t n)
{
  size_t i, j;
  int buff;
  if (n > 1)
  {
    for (i = 0; i < n - 1; i++)
    {
      j = i + rand() / (RAND_MAX / (n - i) + 1);
      buff = a[j];
      a[j] = a[i];
      a[i] = buff;
    }
  }
}

int partition(int *a, size_t lo, size_t hi)
{
  // Partition into a[lo..i-1], a[i], a[i+1..hi]
  
  int i = lo, j = hi+1;         // left and right scan indices
  int v = a[lo];                // partitioning item
  int buff;
  while (true)
  { // Scan right, scan left, check for scan complete, and swap.
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

void quicksort(int *a, size_t lo, size_t hi)
{
  if (hi <= lo) return;
  int j = partition(a, lo, hi);
  quicksort(a, lo, j - 1);
  quicksort(a, j + 1, hi);
}

void quicksort(int *a, size_t n)
{
  shuffle(a, n); // avoid worst case complexity for example
  quicksort(a, 0, n);
}
