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

template <class InputIterator>
void merge_sort(InputIterator first, InputIterator last) {
    if (last - first > 1) {
        auto middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);

        std::vector<int> buf;
        buf.reserve(last - first);
        merge(first, middle, middle, last, std::back_inserter(buf));
        std::copy(buf.begin(), buf.end(), first);
    }
}



int main() {
    int a, tmp;

    std::cin >> a;
    std::vector<int> result;
    result.reserve(a);
    for (size_t i = 0; i != a; ++i) {
        std::cin >> tmp;
        result.push_back(tmp);
    }

    merge_sort(result.begin(), result.end());

    for (size_t i = 0; i != a; ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
