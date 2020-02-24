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
    int n, l, elem;
    std::cin >> n >> l;

    std::vector<std::vector<int>> table(n, std::vector<int>(l));
    std::vector<int> result;
    result.reserve(2 * l);

    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != l; ++j) {
            std::cin >> elem;
            table[i][j] = elem;
        }
    }

    for (size_t i = 0; i != n; ++i) {
        for (size_t j = i + 1; j != n; ++j) {
            merge(table[i].begin(), table[i].end(), table[j].begin(),
                  table[j].end(), std::back_inserter(result));
            std::cout << result[l - 1] << "\n";
            result.clear();
        }
    }
    return 0;
}
