#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>

int main() {
    long int n, a, b, c, sum = 0;
    std::cin >> n >> a >> b >> c;
    std::vector<long int> floors(n + 1);
    floors[1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (floors[i] == 1) {
            if (i + a <= n)
                floors[i + a] = 1;
            if (i + b <= n)
                floors[i + b] = 1;
            if (i + c <= n)
                floors[i + c] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (floors[i] == 1)
            ++sum;
    }
    std::cout << sum;
    return 0;
}
