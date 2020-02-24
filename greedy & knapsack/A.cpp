#include <iostream>
#include <vector>

int main() {
    int n, k, s, sNumb;
    std::cin >> n >> k >> s;

    std::vector<std::vector<int>> table(n, std::vector<int>(n, -1));


    for (size_t i = 0; i != n - k + 1; ++i) {
        for (size_t j = 0; j != n - k + 1; ++j) {
            sNumb = 0;
            for (size_t x = i; x != i + k; ++x) {
                for (size_t y = j; y != j + k; ++y) {
                    if (table[x][y] == -1 && sNumb < s) {
                        table[x][y] = 1;
                        ++sNumb;
                    } else if (table[x][y] == -1) {
                        table[x][y] = 0;
                    } else if (table[x][y] == 1) {
                        ++sNumb;
                    }
                }
            }
        }
    }
    for (auto row : table) {
        for (auto col : row) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
