#include <algorithm>
#include <iostream>
#include <vector>

struct edge {
    int u, v, w;
};

void uni(int x, int y, std::vector<int>& color) {
    int t = color[y];
    for (size_t i = 1; i != color.size() + 1; ++i) {
        if (color[i] == t)
            color[i] = color[x];
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> color(n + 1, -1);
    std::vector<edge> E(m + 1), result;
    result.reserve(m);

    for (size_t i = 0; i != m; ++i) {
        edge tmp;
        std::cin >> tmp.u >> tmp.v;
        E[i + 1] = tmp;
        color[tmp.u] = tmp.u;
        color[tmp.v] = tmp.v;
    }

    for (size_t i = 1; i != m + 1; ++i) {
        if (color[E[i].u] != color[E[i].v]) {
            uni(E[i].u, E[i].v, color);
            edge tmp;
            tmp.u = E[i].u;
            tmp.v = E[i].v;
            result.push_back(tmp);
        }
    }

    for (auto elem : result) {
        std::cout << elem.u << " " << elem.v << "\n";
    }

    return 0;
}
