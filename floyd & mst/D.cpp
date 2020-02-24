#include <algorithm>
#include <iostream>
#include <vector>

bool dfs(const std::vector<std::vector<int>>& matrix, std::vector<int>& vis, int u) {
    vis[u] = 1;
    for (size_t i = 0; i != matrix.size(); ++i) {
        if (matrix[u][i] == 1) {
            if ((vis[i] == 0 && dfs(matrix, vis, i)) || vis[i] == 1) {
                return true;
            }
        }
    }
    vis[u] = 2;
    return false;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::vector<int> visited(n, 0);
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (size_t i = 0; i != n; ++i) {
        if (visited[i] == 0 && dfs(matrix, visited, i)) {
            std::cout << 1;
            return 0;
        }
    }
    std::cout << 0;

    return 0;
}
