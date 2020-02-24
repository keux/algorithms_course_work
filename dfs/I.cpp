#include <iostream>
#include <vector>
#include <set>
#include <map>

int timer = 1, cnt = 0;
std::vector<int> s, up, visited;
std::set<int> points;

void dfs(int v, const std::vector<std::set<int>>& adj, int p = -1) {
    int children = 0;
    visited[v] = 1;
    s[v] = up[v] = timer++;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (s[u] == 0) {
            dfs(u, adj, v);
            up[v] = std::min(up[v], up[u]);
            if (up[u] >= s[v] && p != -1) {
                points.insert(v);
            }
            children++;
        } else {
            up[v] = std::min(up[v], s[u]);
        }
    }
    if (p == -1 && children > 1) {
        points.insert(v);
    }
}

int main() {
    int m, n, u, v;
    std::cin >> n >> m;

    std::vector<std::set<int>> adj(n + 1);

    s.assign(n + 1, 0);
    up.assign(n + 1, 0);
    visited.assign(n + 1, 0);

    for (size_t i = 0; i != m; ++i) {
        std:: cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 1; i != n + 1; ++i) {
        if (visited[i] == 0) {
            dfs(i, adj);
        }
    }

    std::cout << points.size() << "\n";

    for (auto a : points)
        std::cout << a << "\n";

    return 0;
}
