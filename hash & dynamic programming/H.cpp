#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
std::vector<int> X, Y;

void lcs() {
    std::vector<std::vector<int>> board(n + 1, std::vector<int>(m + 1, 0));
    std::vector<std::vector<std::pair<int, int>>>
            p(n + 1, std::vector<std::pair<int, int>>(m + 1, std::make_pair(-1, -1)));

    for (int i = 1; i != n + 1; ++i)
        for (int j = 1; j != m + 1; ++j)
            if (X[i] == Y[j]) {
                board[i][j] = board[i - 1][j - 1] + 1;
                p[i][j] = std::make_pair(i-1, j-1);
            } else if (board[i-1][j] >= board[i][j-1]) {
                board[i][j] = board[i-1][j];
                p[i][j] = std::make_pair(i-1, j);
            } else {
                board[i][j] = board[i][j-1];
                p[i][j] = std::make_pair(i, j-1);
            }

    int i = n, j = m;
    std::vector<int> path;
    path.reserve(n);
    while (true) {
        if (i == 0 || j == 0)
            break;
        if (p[i][j] == std::make_pair(i - 1, j - 1)) {
            path.push_back(X[i]);
            i--;
            j--;
        } else if (p[i][j] == std::make_pair(i - 1, j)) {
            i--;
        } else {
            j--;
        }
    }
    for (size_t k = 0; k != path.size(); ++k) {
        std::cout << path[path.size() - k - 1] << " ";
    }
}

int main() {
    std::cin >> n;
    X.assign(n + 1, 0);

    for (size_t i = 1; i != n + 1; ++i)
        std::cin >> X[i];

    std::cin >> m;
    Y.assign(m + 1, 0);

    for (size_t i = 1; i != m + 1; ++i)
        std::cin >> Y[i];

    lcs();
    return 0;
}
