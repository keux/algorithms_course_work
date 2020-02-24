#include <iostream>
#include <vector>
#include <set>

const long long int INF = 1000000000000000000;

int main() {
    long long n, k, a, b, to, len;
    std::cin >> n >> k;

    std::vector<std::vector<std::pair<long long, long long>>> adj(n + 1);
    std::vector<long long> d(n + 1, INF);
    std::vector<bool> mark(n + 1, false);

    for (int i = 1; i != k + 1; ++i) {
        std::cin >> a >> b >> len;
        adj[a].emplace_back(std::make_pair(b, len));
        adj[b].emplace_back(std::make_pair(a, len));
    }

    std::cin >> a >> b;

    if (a != b) {
        d[a] =  0;
        std::set<std::pair<long long, long long>> S;
        S.insert(std::make_pair(d[a], a));
        while (!S.empty()) {
            long long v = S.begin()->second;
            S.erase(S.begin());
            for (size_t i = 0; i != adj[v].size(); ++i) {
                to = adj[v][i].first;
                len = adj[v][i].second;
                if (d[v] + len < d[to]) {
                    S.erase(std::make_pair(d[to], to));
                    d[to] = d[v] + len;
                    S.insert(std::make_pair(d[to], to));
                }
            }
        }
        if (d[b] == INF) {
            std::cout << -1;
        } else {
            std::cout << d[b];
        }
    } else {
        std::cout << 0;
    }
    return 0;
}
