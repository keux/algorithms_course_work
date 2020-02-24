#include <algorithm>
#include <iostream>
#include <vector>

void TransitiveClosure(std::vector<std::vector<int>>& T, int n) {
    for (size_t k = 0; k != n; ++k) {
        for (size_t i = 0; i != n; ++i) {
            for (size_t j = 0; j != n; ++j) {
                T[i][j] = T[i][j] || (T[i][k] && T[k][j]);
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    TransitiveClosure(matrix, n);

    for (auto row : matrix) {
        for (auto col : row) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
