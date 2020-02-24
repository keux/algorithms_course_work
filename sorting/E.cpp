#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, elem, last;
    size_t ind = 0;
    std::cin >> n;

    std::vector<int> tmp;
    tmp.reserve(n);
    std::vector<int> result;
    result.reserve(n);

    std::set<int> container;

    for (size_t i = 0; i != n; ++i) {
        std::cin >> elem;
        tmp.push_back(elem);
    }

    for (size_t i = tmp.size() - 1; i != -1; --i) {
        if (container.empty() || container.find(tmp[i]) == container.end()) {
            result.push_back(tmp[i]);
            container.insert(tmp[i]);
        }
    }

    std::cout << container.size() << "\n";
    for (size_t i = result.size() - 1; i != -1; --i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
