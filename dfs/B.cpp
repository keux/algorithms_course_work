#include <iostream>
#include <vector>
#include <set>

int col = 0, cnt_glob = 0;
std::set<int> ver;
std::set<std::set<int>> comp_sv;

void dfs(int u, std::vector<int>& vis,
         const std::vector<std::set<int>>& adj,
         int col, std::vector<int>& colors) {
    vis[u] = 1;
    colors[u] = col;
    ver.insert(u);
    for (int v : adj[u]) {
        if (vis[v] == 0)
            dfs(v, vis, adj, col, colors);
    }
}

void component(std::vector<int>& colors, int n,
               std::vector<int>& vis,
               const std::vector<std::set<int>>& adj) {
    for (size_t i = 1; i != n + 1; ++i) {
        if (colors[i] == 0) {
            ++cnt_glob;
            ++col;
            dfs(i, vis, adj, col, colors);

            comp_sv.insert(ver);
            ver.clear();
        }
    }
}

int main() {
    int m, n, u, v;
    std::cin >> n >> m;

    std::vector<std::set<int>> adj(n + 1);
    std::vector<int> visited(n + 1);
    std::vector<int> color(n + 1);

    for (size_t i = 0; i != m; ++i) {
        std:: cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    component(color, n, visited, adj);

    std::cout << comp_sv.size() << "\n";

    for (auto elem : comp_sv) {
        std::cout << elem.size() << "\n";
        for (int v : elem)
            std::cout << v << " ";
        std::cout << "\n";
    }
    return 0;
}
