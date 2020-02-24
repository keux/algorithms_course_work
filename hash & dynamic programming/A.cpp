#include <iostream>
#include <string>

int main() {
    int n, rem = 0;
    std::string numb;

    std::cin >> n >> numb;

    for (int i = 0; i != numb.size(); ++i) {
        rem = (rem * 10 + (numb[i] - '0')) % n;
    }

    std::cout << rem;
    return 0;
}
