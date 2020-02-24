#include <iostream>
#include <vector>
#include <set>

bool k = true;

bool dfs(int u, const std::vector<std::set<int>>& adj, std::vector<int>& colors) {
    for (int v : adj[u]) {
        if (colors[v] == 0) {
            colors[v] = 3 - colors[u];
            dfs(v, adj, colors);
        } else if (colors[v] == colors[u]) {
            k = false;
        }
    }
}

int main() {
    int m, n, u, v;
    std::cin >> n >> m;

    std::vector<std::set<int>> adj(n + 1);
    // std::vector<int> visited(n + 1);
    std::vector<int> color(n + 1);

    for (size_t i = 0; i != m; ++i) {
        std:: cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (size_t i = 1; i != n + 1; ++i) {
        if (color[i] == 0)
            color[i] = 1;
        k = true;
        dfs(i, adj, color);
        if (k == false)
            break;
    }
    if (k == false)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";

    return 0;
}
