#include <iostream>
#include <vector>
#include <set>

int main() {
    size_t n, k;
    int pushes, elem;

    std::cin >> n;

    std::vector<int> elements(n);

    for (size_t i = 0; i != n; ++i) {
        std::cin >> elem;
        elements[i] = elem;
    }

    std::cin >> k;

    for (size_t i = 0; i != k; ++i) {
        std::cin >> pushes;
        elements[pushes - 1] -= 1;
    }

    for (size_t i = 0; i != n; ++i) {
        if (elements[i] >= 0)
            std::cout << "no\n";
        else
            std::cout << "yes\n";
    }

    return 0;
}
