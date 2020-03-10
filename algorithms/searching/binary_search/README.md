# [Binary search](https://en.wikipedia.org/wiki/Binary_search_algorithm)

Binary search recursively divides specified container range in half and checks if middle element is equal to searched one.

## Performance

**Comparisons:** O(log(n))

## Use cases

- Simple and efficient search algorithm is needed

## Requirements

- Collection supports random access
- Collection is sorted

## Language-specific notes

### C++

**NOTE:** Binary search is part of `<algorithm>` header in *STL* and is equivalent to:

```c++
template <class ForwardIterator, class T>
bool binary_search(ForwardIterator first, ForwardIterator last, const T& val)
{
  first = std::lower_bound(first, last, val);
  return (first != last && !(val < *first));
}
```

If you need index of searched element, use the following implementation:

```c++
template <class ForwardIterator, class T>
int binary_search_i(ForwardIterator first, ForwardIterator last, const T &val) {
  auto found = std::lower_bound(first, last, val);
  return found != last ? found - first : -1;
}
```

`std::lower_bound` also works on containers without random access but it's performance is linear in such cases.
