#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, tmp, a, b;
    std::cin >> n;

    std::vector<std::pair<int, int>> game(n);
    std::vector<std::vector<int>> result(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        std::cin >> a;
        game[i] = std::make_pair(a, i);
    }

    for (int i = 0; i != n; ++i) {
        std::sort(game.begin() + i, game.end());
        int j = 0;
        for (j = i + 1; game[i].first > 0 && j < n; j++) {
            --game[i].first;
            --game[j].first;
            a = game[i].second;
            b = game[j].second;
            result[a][b] = 1;
            result[b][a] = 1;
        }
        for (; j != n; ++j) {
            game[j].first -= 2;
            a = game[i].second;
            b = game[j].second;
            result[a][b] = 0;
            result[b][a] = 2;
        }
    }
    for (auto row : result) {
        for (auto col : row)
            std::cout << col << " ";
        std::cout << "\n";
    }
    return 0;
}
