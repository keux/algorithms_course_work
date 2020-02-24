#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> board(n + 1, std::vector<int>(m + 1));

    board[1][1] = 1;

    for (int i = 2; i != n + 1; ++i) {
        for (int j = 2; j != m + 1; ++j) {
            board[i][j] = board[i - 2][j - 1] + board[i - 1][j - 2];
        }
    }

    std::cout << board[n][m];
    return 0;
}
