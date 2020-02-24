#include <iostream>
#include <vector>

template <typename Iterator>
void Select(Iterator begin, Iterator end) {
    if (end - begin > 1) {
        Iterator max = begin;
        for (Iterator i = begin; i != end; ++i) {
            if (*i > *max)
                max = i;
        }
        std::swap(*max, *--end);
    }
}

template <typename Iterator>
void SelectionSort(Iterator begin, Iterator end) {
    size_t distance  = end - begin;
    for (size_t i = 0; i != distance; ++i) {
        Select(begin, end);
        --end;
    }
}


int main() {
    long long int n, elem;
    std::cin >> n;

    std::vector<long long int> tmp;
    tmp.reserve(n);

    for (size_t i = 0; i != n; ++i) {
        std::cin >> elem;
        tmp.push_back(elem);
    }

    SelectionSort(tmp.begin(), tmp.end());

    for (auto elem : tmp) {
        std::cout << elem << " ";
    }

    return 0;
}
