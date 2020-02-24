#include <iostream>
#include <vector>
#include <set>
#include <stack>

int n;
std::vector<std::set<int>> adj;
std::vector<bool> visited;
int cnt = 0, max1 = 0, ind = 0;

void dfs(int u) {
    visited[u] = true;
    cnt += 1;
    for (auto i : adj[u]) {
        if (visited[i] == 0) {
            if (cnt > max1) {
                max1 = cnt;
                ind = i;
            }
            dfs(i);
        }
    }
    cnt -= 1;
}
int main() {
    int u, v;
    std::cin >> n;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    for (size_t i = 1; i != n; ++i) {
        std:: cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    dfs(1);
    cnt = 0;
    max1 = 0;
    visited.assign(n + 1, false);
    dfs(ind);
    std::cout << max1;
    return 0;
}
