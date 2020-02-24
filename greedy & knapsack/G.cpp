#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
int main() {
    int n, m, a;
    std::cin >> n >> m;
    std::vector<std::vector<int>> mas(n + 1, std::vector<int>(m + 1));
    std::vector<int> weight(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> weight[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];
    }
    for (int s = 1; s <= n; ++s) {
        for (int z = 0; z <= m; ++z) {
            mas[s][z] = mas[s - 1][z];
            if (z >= weight[s] &&
                    (mas[s - 1][z - weight[s]] + p[s]) > mas[s - 1][z])
                mas[s][z] = mas[s - 1][z - weight[s]] + p[s];
        }
    }
    std::cout << mas[n][m];
    return 0;
}
