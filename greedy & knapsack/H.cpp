#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
void print(const std::vector<std::vector<int>>& mas, int n, int m,
           const std::vector<int>& w) {
    if (mas[n][m] == 0)
        return;
    if (mas[n - 1][m] == mas[n][m]) {
        print(mas, n - 1, m, w);
    } else {
        print(mas, n - 1, m - w[n], w);
        std::cout << n << "\n";
    }
}
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
                    (mas[s - 1][z - weight[s]] + p[s]) > mas[s - 1][z]) {
                mas[s][z] = mas[s - 1][z - weight[s]] + p[s];
            }
        }
    }
    print(mas, n, m, weight);
    return 0;
}
