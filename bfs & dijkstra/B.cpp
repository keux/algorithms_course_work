#include <iostream>
#include <vector>
#include <set>
#include <queue>

std::vector<std::vector<int>> adj;
std::vector<int> dx = {-1, -1, 1, 1, -2, -2, 2, 2},
        dy = {-2, 2, -2, 2, -1, 1, -1, 1};
std::queue<int> x, y;
int n, m;

void bfs() {
    int u, v, tmp, po_x, po_y;
    while (!x.empty() && !y.empty()) {
        u = x.front();
        v = y.front();
        x.pop();
        y.pop();

        tmp = adj[u][v] + 1;
        for (int i = 0; i != 8; ++i) {
            po_x = u + dx[i];
            po_y = v + dy[i];
            if (adj[po_x][po_y] == -1) {
                adj[po_x][po_y] = tmp;
                x.push(po_x);
                y.push(po_y);
            }
        }
    }
}

int main() {
    int s, t, q, u, v, sum = 0;
    std::cin >> n >> m >> s >> t >> q;

    adj.assign(n + 4, std::vector<int>(m + 4, -1));

    for (int i = 0; i < n + 4; ++i) {
        for (int j = 0; j < m + 4; ++j) {
            if (i < 2 || i > n + 1 || j < 2 || j > m + 1) {
                adj[i][j] = -2;
            }
        }
    }

    adj[s + 1][t + 1] = 0;
    x.push(s + 1);
    y.push(t + 1);

    bfs();

    for (size_t i = 1; i != q + 1; ++i) {
        std::cin >> u >> v;
        if (adj[u + 1][v + 1] != -1) {
            sum += adj[u + 1][v + 1];
        } else {
            sum = -1;
            break;
        }
    }

    std::cout << sum << "\n";
    return 0;
}
