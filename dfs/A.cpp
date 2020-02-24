#include <iostream>
#include <vector>
#include <set>

int cnt = 0;
std::set<int> ver;

void dfs(int u, std::vector<int>& vis, const std::vector<std::set<int>>& adj) {
    vis[u] = 1;
    ++cnt;
    ver.insert(u);
    for (int v : adj[u]) {
        if (vis[v] == 0)
            dfs(v, vis, adj);
    }
}

int main() {
    int m, n, u, v;
    std::cin >> n >> m;

    std::vector<std::set<int>> adj(n + 1);
    std::vector<int> visited(n + 1);

    for (size_t i = 0; i != m; ++i) {
        std:: cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    dfs(1, visited, adj);
    std::cout << cnt << "\n";
    for (int elem : ver)
        std::cout << elem << " ";
    return 0;
}
