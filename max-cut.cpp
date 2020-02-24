#include <iostream>
#include <vector>
#include <set>


int main() {
    int n, max = 0;
    std::cin >> n;

    std::vector<std::vector<int>> c(n, std::vector<int>(n));
    std::set<int> A_b, B_b;

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            std::cin >> c[i][j];
        }
    }
    std::vector<int> fin(n, 1), fin2;
    for (int i = 0; i < (1 << (n - 1)) - 1; ++i) {
        for (auto len = 0; len < n - 1; ++len) {
            if (i & (1 << len)) {
                fin[len + 1] = 1;
            } else {
                fin[len + 1] = 2;
            }
        }
        int res = 0;

        for (int a = 0; a != n; ++a) {
            if (fin[a] == 1) {
                for (int b = 0; b != n; ++b) {
                    if (fin[b] == 2) {
                        res += c[a][b];
                    }
                }
            }
        }

        if (res > max) {
            max = res;
            fin2 = fin;
        }
    }
    std::cout << max << "\n";

    for (int a : fin2) {
        std::cout << a << " ";
    }
    return 0;
}
