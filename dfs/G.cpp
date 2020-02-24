#include <iostream>
#include <vector>
#include <set>

int col = 0, cnt_glob = 0, tout = 0;
std::vector<int> order;
std::vector<int> component;

void dfs1(int u, std::vector<int>& vis,
         const std::vector<std::set<int>>& adj) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 0)
            dfs1(v, vis, adj);
    }
    order.push_back(u);
}

void dfs2(int u, std::vector<int>& vis,
          const std::vector<std::set<int>>& adj, int col) {
    vis[u] = 1;
    component[u] = col;
    for (int v : adj[u]) {
        if (vis[v] == 0)
            dfs2(v, vis, adj, col);
    }
}


int main() {
    int m, n, u, v;
    std::cin >> n >> m;

    order.reserve(n);
    component.assign(n + 1, 0);

    std::vector<std::set<int>> adj(n + 1);
    std::vector<std::set<int>> adj_t(n + 1);
    std::vector<int> visited(n + 1);

    for (size_t i = 0; i != m; ++i) {
        std:: cin >> u >> v;
        adj[u].insert(v);
        adj_t[v].insert(u);
    }

    for (size_t i = 1; i != n + 1; ++i) {
        if (visited[i] == 0) {
            dfs1(i, visited, adj);
        }
    }
    dfs1(1, visited, adj);

    visited.assign(n + 1, 0);
    for (size_t i = 0; i != n; ++i) {
        v = order[n - 1 - i];
        if (visited[v] == 0) {
            ++col;
            dfs2(v, visited, adj_t, col);
        }
    }
    std::cout << col << "\n";
    for (size_t i = 1; i != n + 1; ++i) {
        std::cout << component[i] << " ";
    }
    return 0;
}
