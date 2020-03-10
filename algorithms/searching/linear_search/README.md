# Linear search

Iterates over entire data structure in order to find queried element.

Generally, linear search is useful when searched data structure is known not to be sorted or arranged in a manner allowing more efficient search algorythm to be implemented.

Use [`std::find(InputIterator first, InputIterator last, const T& val)`](https://en.cppreference.com/w/cpp/algorithm/find) method from `<algorithm>` header in C++. It is dependant on the compiler specific implementation of the standard library but generally uses several different search algorythms depending on which would perform faster on specific data set (generally based on size).

**Comparisons:** O(n)
