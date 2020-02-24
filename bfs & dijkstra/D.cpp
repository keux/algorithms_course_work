#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

std::vector<std::vector<int>> adj;
std::vector<int> d, from;
std::queue<int> tmp;

void bfs() {
    int u;
    while (!tmp.empty()) {
        u = tmp.front();
        tmp.pop();
        for (int v = 1; v != adj[u].size(); ++v) {
            if (adj[u][v] == 1) {
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    tmp.push(v);
                    from[v] = u;
                }
            }
        }
    }
}

void print(int start, int finish) {
    if (finish != start) {
        print(start, from[finish]);
    }
    std::cout << finish << " ";
}

int main() {
    int n, m, start, finish, line, station;
    std::cin >> n >> m;

    adj.assign(n + 1, std::vector<int>(n + 1, 0));
    std::vector<std::set<int>> L(m + 1);
    d.assign(n + 1, -1);
    from.assign(n + 1, -1);

    for (size_t i = 0; i != m; ++i) {
        std::cin >> line;
        for (size_t j = 0; j != line; ++j) {
            std::cin >> station;
            L[i + 1].insert(station);
        }
    }

    std::cin >> start >> finish;
    std::set<int> current, next, tmp, tmp2;
    current.insert(start);
    bool  k = false;

    for (int step = 0; step != m; ++step) {
        next = current;
        for (int i = 1; i != m + 1; ++i) {
            std::set_intersection(current.begin(), current.end(), L[i].begin(), L[i].end(),
                                  std::inserter(tmp, tmp.begin()));
            if (!tmp.empty()) {
                std::set_union(next.begin(), next.end(), L[i].begin(), L[i].end(),
                               std::inserter(tmp2, tmp2.begin()));
                next = tmp2;
            }
            tmp.clear();
            tmp2.clear();
        }
        if (next.find(finish) != next.end()) {
            std::cout << step << "\n";
            k = true;
            break;
        }
        if (k)
            break;
        current = next;
    }

    if (!k)
        std::cout << -1;

    return 0;
}
