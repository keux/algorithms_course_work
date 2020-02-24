#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>

int main() {
    unsigned long long m, sum = 0;
    std::cin >> m;
    std::vector<unsigned long long> time(31);
    std::cin >> time[0];
    for (int i = 1; i != 31; ++i) {
        std::cin >> time[i];
        if (time[i] < 2 * time[i - 1])
            time[i] = 2 * time[i - 1];
    }
    for (int i = 30; i >= 0; --i) {
        if (m >= time[i]) {
            m -= time[i];
            sum += std::pow(2, i);
        }
    }
    if (m > 0)
        std::cout << sum + 1;
    else
        std::cout << sum;
    return 0;
}
