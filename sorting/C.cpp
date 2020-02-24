#include <iostream>
#include <vector>

template <typename Iterator>
Iterator Partition(Iterator begin, Iterator end, int p) {
        if (end - begin <= 1)
            return begin;
        Iterator i = begin;
        for (Iterator j = begin + 1; j != end; ++j) {
            if (*j < p) {
                ++i;
                std::swap(*i, *j);
            }
        }
        return i;
}

int main() {
    long long int n, elem, pivot;
    std::cin >> n;

    std::vector<long long int> tmp;
    tmp.reserve(n + 1);
    tmp.push_back(0);

    for (size_t i = 0; i != n; ++i) {
        std::cin >> elem;
        tmp.push_back(elem);
    }

    std::cin >> pivot;
    tmp[0] = pivot;

    auto ind = Partition(tmp.begin(), tmp.end(), pivot);

    std::cout << ind - tmp.begin() << "\n";
    std::cout << tmp.end() - ind - 1;

    return 0;
}
