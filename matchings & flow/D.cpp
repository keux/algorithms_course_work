#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <string>
const int INF = INT_MAX;

int main() {
    int n;
    std::cin >> n;

    int nV = 2 * n + 2, s = nV - 2, t = nV - 1;

    std::vector<std::vector<int>> cap(nV, std::vector<int>(nV)),
    flow(nV, std::vector<int>(nV)), cost(nV, std::vector<int>(nV));

    for (size_t i = 0; i != n; ++i) {
        cap[s][i] = 1;
        cap[n + i][t] = 1;
    }

    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != n; ++j) {
            cap[i][n + j] = 1;
            std::cin >> cost[i][n + j];
            cost[n + j][i] = -cost[i][n + j];
        }
    }
    std::vector<int> dist(nV), from(nV);
    std::queue<int> q;
    std::vector<bool> in(nV);

    int sum = 0;
    for (size_t i = 0; i != n; ++i) {
        dist.assign(nV, INF);
        in.assign(nV, false);
        dist[s] = 0;
        q.push(s);
        in[s] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            in[cur] = false;
            for (int nei = 0; nei != nV; ++nei) {
                if (flow[cur][nei] < cap[cur][nei]) {
                    if (dist[nei] > dist[cur] + cost[cur][nei]) {
                        dist[nei] = dist[cur] + cost[cur][nei];
                        from[nei] = cur;
                        if (!in[nei]) {
                            q.push(nei);
                            in[nei] = true;
                        }
                    }
                }
            }
        }
        int cur = t;
        while (cur != s) {
            int prev = from[cur];
            ++flow[prev][cur];
            --flow[cur][prev];
            sum += cost[prev][cur];
            cur = prev;
        }
    }
    std::cout << sum;
    return 0;
}
