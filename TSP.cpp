#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>


int score (const std::vector<std::vector<int>>& c, const std::vector<int>& tour, int n) {
    int res = 0;
    for (int i = 1; i != n; ++i) {
        if (c[tour[i - 1]][tour[i]] == 0 && n != 2)
            return -1;
        res += c[tour[i - 1]][tour[i]];
    }
    if (n == 1)
        return 2 * c[tour[1]][tour[0]];
    return res;
}


int main() {
    int n;
    std::set<int> J;
    std::vector<int> tour;
    tour.reserve(n);
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i != n; ++i) {
        tour.push_back(i);
    }
    tour.push_back(0);

    int tmp, min_score = score(matrix, tour, n + 1);
    //std::cout << min_score << "\n";
    while (std::next_permutation(tour.begin() + 1, tour.begin() + n)) {
        /*for (int el : tour)
            std::cout << el << " ";
        std::cout << "\n";*/
        tmp = score(matrix, tour, n + 1);
        if (tmp != -1 && tmp < min_score) {
            min_score = tmp;
        }
    }
    std::cout << min_score;

    return 0;
}
