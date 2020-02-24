#include <iostream>
#include <vector>
#include <set>
#include <queue>

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
    int n, a, start, finish;
    std::cin >> n;

    adj.assign(n + 1, std::vector<int>(n + 1));
    d.assign(n + 1, -1);
    from.assign(n + 1, -1);

    for (size_t i = 1; i != n + 1; ++i) {
        for (size_t j = 1; j != n + 1; ++j) {
            std::cin >> a;
            adj[i][j] = a;
        }
    }

    std::cin >> start >> finish;

    d[start] = 0;
    tmp.push(start);

    bfs();
    std::cout << d[finish] << "\n";
    if (d[finish] != 0 && d[finish] != -1) {
        print(start, finish);
    }
    return 0;
}
