#include <algorithm>
#include <iostream>
#include <vector>

int MaxPath(std::vector<std::vector<int>>& D, int n) {
    int max = 0;
    for (size_t k = 0; k != n; ++k) {
        for (size_t i = 0; i != n; ++i) {
            for (size_t j = 0; j != n; ++j) {
                D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
                if (k == n - 1 && (D[i][j] > max))
                    max = D[i][j];
            }
        }
    }
    return max;
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

    std::cout << MaxPath(matrix, n);
    return 0;
}
