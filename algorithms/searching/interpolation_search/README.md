# [Interpolation search](https://en.wikipedia.org/wiki/Interpolation_search)

Interpolation search is a modified version of binary search where data received by failed search probes is used to _interpolate_ position of queried element.

## Performance

| Operation   | Worst | Average  |     Best     |
| :---------- | :---: | :------: | :----------: |
| Comparisons | O(n)  | Θ(log n) | Ω(log log n) |

Under the assumption of a uniform distribution of the data on the linear scale used for interpolation, interpretation search can perform in **O(log log n)**.

## Use cases

- Sorted but unindexed on-disk datasets where access time is slow

## Requirements

- Collection is sorted
- Collection data is uniformly distributed (to avoid worst case complexity)
