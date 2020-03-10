template <class ForwardIt, class T>
int linear_search(ForwardIt first, ForwardIt last, const T &el) {
    auto curr = first;
    while (curr != last) {
        if (*curr == el) return curr - first;
        curr++;
    }
    return -1;
}
