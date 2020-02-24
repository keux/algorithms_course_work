#include <algorithm>
#include <iostream>
#include <vector>

void Floyd(std::vector<std::vector<int>>& D, int n) {
    for (size_t k = 0; k != n; ++k) {
        for (size_t i = 0; i != n; ++i) {
            for (size_t j = 0; j != n; ++j) {
                D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
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

    Floyd(matrix, n);

    for (auto row : matrix) {
        for (auto col : row) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
