# [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) (a.k.a. Sinking sort)

**Type:** Exchange sort (Comparison sort)

## Performance

| Operation   | Worst  | Average | Best |
| :---------- | :----: | :-----: | :--: |
| Comparisons | O(n^2) | Θ(n^2)  | Ω(n) |
| Swaps       | O(n^2) | Θ(n^2)  | Ω(1) |

**Space complexity:** O(1)

## Use cases

- Quick and simple code implementation is needed
- Input is in mostly sorted order and some out-of-order elements are nearly in position.

**Standard language sort function (if one exists) should be used instead of this algorithm as it's very slow.**
