#include <iostream>
#include <vector>

template <class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator merge(InputIterator1 begin1, InputIterator1 end1,
                     InputIterator2 begin2, InputIterator2 end2,
                     OutputIterator out) {
    while (true) {
        if (begin1 == end1)
            return std::copy(begin2, end2, out);
        if (begin2 == end2)
            return std::copy(begin1, end1, out);
        *out++ = (*begin1 < *begin2)? *begin1++ : *begin2++;
    }
}

int main() {
    int a, b, tmp;

    std::cin >> a;
    std::vector<int> first;
    first.reserve(a);
    for (size_t i = 0; i != a; ++i) {
        std::cin >> tmp;
        first.push_back(tmp);
    }

    std::cin >> b;
    std::vector<int> second;
    second.reserve(b);
    for (size_t i = 0; i != b; ++i) {
        std::cin >> tmp;
        second.push_back(tmp);
    }

    std::vector<int> result;
    result.reserve(a + b);

    merge(first.begin(), first.end(), second.begin(), second.end(), result.begin());

    for (size_t i = 0; i != (a + b); ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
