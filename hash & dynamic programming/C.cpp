#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, k, s = 1, tmp;
    std::cin >> n >> k;

    std::vector<int> d(n + 1);
    d[1] = s;
    tmp = std::min(n, k);

    for (int i = 2; i != tmp + 1; ++i) {
        d[i] = s;
        s += d[i];
    }

    for (int i = tmp + 1; i != n + 1; ++i) {
        d[i] = s;
        s = s - d[i - k] + d[i];
    }

    std::cout << d[n];
    return 0;
}
