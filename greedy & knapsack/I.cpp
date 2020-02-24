#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>

struct block {
    int l, col;
};

void path(std::vector<int>& B, int i, int j, std::vector<std::multiset<int>>& from) {
    if (B[j] == 0) {
        from[i].insert(j);
    } else {
        from[i].insert(j - B[j]);
        path(B, i, B[j], from);
    }
}

int main() {
    int n, k, m, a, b;
    std::cin >> n >> k;

    std::vector<block> all;
    all.reserve(n * n);

    for (size_t i = 0; i != n; ++i) {
        block temp;
        std::cin >> temp.l >> temp.col;
        all.push_back(temp);
    }

    m = 0;
    for (auto elem : all) {
        if (elem.col == 1)
            m += elem.l;
    }

    std::vector<std::vector<int>> A(k + 1, std::vector<int>(m + 1)),
            B(k + 1, std::vector<int>(m + 1));
    for (int p = 0; p != k + 1; ++p) {
        A[p][0] = 1;
    }

    for (auto elem : all) {
        int i = elem.col;
        int z = elem.l;
        for (int j = m - 1; j >= z; --j) {
            if (A[i][j - z] == 1 && A[i][j] != 1) {
                A[i][j] = 1;
                B[i][j] = j - z;
            }
        }
    }

    for (int j = m; j > 0; --j) {
        for (int i = 1; i != k + 1; ++i) {
            A[0][j] += A[i][j];
        }
    }
    int t = 0;
    for (int i = 1; i < m; ++i) {
        if (A[0][i] == k) {
            t = i;
            break;
        }
    }

    if (t != 0) {
        std::cout << "YES\n";
        std::vector<std::multiset<int>> from(k + 1);
        for (int i = 1; i <= k; ++i) {
            path(B[i], i, t, from);
        }

        for (int i = 0; i != n; ++i) {
            int color = all[i].col, length = all[i].l;
            if (from[color].find(length) != from[color].end()) {
                std::cout << i + 1 << " ";
                from[color].erase(from[color].find(length));
            }
        }
    } else {
        std::cout << "NO";
    }
    return 0;
}
