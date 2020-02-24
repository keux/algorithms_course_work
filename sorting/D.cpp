#include <iostream>
#include <vector>

template <typename Iterator>
std::pair<Iterator, Iterator> Partition(Iterator begin, Iterator end) {
    if (end - begin > 1) {
        Iterator i = begin, j = begin, k = end - 1, last = end - 1, ind, ind2;
        while (j < k) {
            if (*j == *last) {
                --k;
                std::swap(*j, *k);
            } else {
                if (*j < *last) {
                    std::swap(*j, *i);
                    ++j;
                    ++i;
                } else {
                    ++j;
                }
            }
        }
        ind = i;
        for (Iterator it = k; it != end; ++it, ++i) {
            std::swap(*i, *it);
        }
        ind2 = ind + (end - k);
        return std::make_pair(ind, ind2);
    }
}

template <typename Iterator>
Iterator ChoosePivot(Iterator begin, Iterator end) {
    auto last = std::distance(end, begin);
    auto random = rand() % (last + 1);
    return begin + random;
}

template <typename Iterator>
void QuickSort(Iterator begin, Iterator end) {
    if (end - begin >  1) {
        Iterator p = ChoosePivot(begin, end);
        auto tmp = end - 1;
        std::swap(*p, *tmp);
        auto i = Partition(begin, end);
        QuickSort(begin, i.first);
        QuickSort(i.second, end);
    }
}

int main() {
    long long int n, elem, pivot;
    std::cin >> n;

    std::vector<long long int> tmp;
    tmp.reserve(n + 1);

    for (size_t i = 0; i != n; ++i) {
        std::cin >> elem;
        tmp.push_back(elem);
    }

    QuickSort(tmp.begin(), tmp.end());

    for (auto elem : tmp) {
        std::cout << elem << " ";
    }

    return 0;
}
