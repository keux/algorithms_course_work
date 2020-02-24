#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
int main() {
    int n, m, a;
    std::cin >> n >> m;
    std::vector<int> mas(m + 1);
    mas[0] = 1;
    for (int i = 0; i != n; ++i) {
        std::cin >> a;
        for (int j = m; j >= a; --j) {
            if (mas[j - a] == 1)
                mas[j] = 1;
        }
    }
    for (int i = m; i >= 0; --i) {
        if (mas[i] == 1) {
            std::cout << i;
            break;
        }
    }
    return 0;
}
