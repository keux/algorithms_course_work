#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <string>

int main() {
    int l_za, r_sot;
    std::cin >> l_za >> r_sot;

    int nV = l_za + r_sot + 2;
    int s = nV - 2, t = nV - 1;

    std::vector<std::vector<int>>
            cap(nV, std::vector<int>(nV)),
            flow(nV, std::vector<int>(nV));

    for (int i = 0; i != l_za; ++i) {
        cap[s][i] = 1;
    }
    for (int i = 0; i != r_sot; ++i) {
        cap[l_za + i][t] = 1;
    }
    for (int i = 0; i != r_sot; ++i) {
        for (int j = 0; j != l_za; ++j) {
            std::cin >> cap[j][l_za + i];
        }
    }

    std::vector<bool> vis;
    std::vector<int> from(nV);
    std::queue<int> q;
    for (size_t i = 0; i != r_sot; ++i) {
        vis.assign(nV, false);
        q.push(s);
        vis[s] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nei = 0; nei != nV; ++nei) {
                if (!vis[nei]) {
                    if (flow[cur][nei] < cap[cur][nei]) {
                        q.push(nei);
                        vis[nei] = true;
                        from[nei] = cur;
                    }
                }
            }
        }
        int cur = t;
        while (cur != s) {
            int prev = from[cur];
            ++flow[prev][cur];
            --flow[cur][prev];
            cur = prev;
        }
    }
    int maxF = 0;
    for (size_t i = 0; i != r_sot; ++i) {
        if (flow[l_za + i][t] > 0)
            ++maxF;
    }
    std::cout << maxF;
    return 0;
}
