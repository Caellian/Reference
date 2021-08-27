# [C++ Iterators](https://en.cppreference.com/w/cpp/iterator)

While [C++ Reference](https://en.cppreference.com) is a great resource which specifies in great detail iterator functionality. You should be looking up their requirements there.

It is trivial to implement them in most cases, but the ability to simply paste the code and modify it appropriately minimizes the likelihood of dumb mistakes (omissions).

Keep in mind that iterators are defined based on requirements instead of having a class you can inherit from to "quickly grab" all their methods precisely because they can behave in variety of ways. Standard does not define a single correct way of using them but an interface so they can be portable and stable when used in abstract functions. Example (template) classes I wrote follow some sane assumptions but your requirements might (and likely will) be different so you should modify them.

I didn't add assignment operator overloads to avoid confusion as they might be hard/impossible for some use cases to properly handle.

## [Iterator tags](https://en.cppreference.com/w/cpp/iterator/iterator_tags)

`iterator` defines following iterator tags:
```c++
std::input_iterator_tag
std::output_iterator_tag
std::forward_iterator_tag
std::bidirectional_iterator_tag
std::random_access_iterator_tag
std::contiguous_iterator_tag // Since C++20
```

If you're using these in C++ version lower than C++17, remove `[[nodiscard]]`.
`using` should also be replaced with `typedef` if unavailable.

## C++17

With C++17, [`std::iterator`](https://en.cppreference.com/w/cpp/iterator/iterator) became deprecated due to several reasons, biggest of which was that iterators inheriting from `std::iterator` not explicitly stating which type is
assigned to which type definition
(see [\[P0174\]](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0174r2.html#2.1)). Output iterators were especially ugly: `std::iterator<std::output_iterator_tag, void, void, void, void>`.

With `std::iterator` **deprecation**, it is expected that developers explicitly declare appropriate `using`
declarations:

```c++
using iterator_category = std::forward_iterator_tag;
using value_type = int;
using difference_type = int;
using pointer = int*;
using reference = int&;
```

In respect to this change, all iterators defined here don't inherit from `std::iterator` and instead declare `using` declarations explicitly. `std::iterator` should not be used to handle iterators in code, by default it shouldn't hold
any runtime data.

### Accessing iterator traits

Accessing iterator traits should not be done directly through iterators because it's not guaranteed that they will have appropriate type definitions. [`std::iterator_traits`](https://en.cppreference.com/w/cpp/iterator/iterator_traits) should be used instead.

## C++20

C++20 introduces a new system of iterators based on concepts that are somewhat different from C++17 iterator categories.

Take a look at [cppreference.com](https://en.cppreference.com/w/cpp/iterator#C.2B.2B20_iterator_concepts) for more details on iterator concepts.
