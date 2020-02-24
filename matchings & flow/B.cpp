#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <string>

int main() {
    int n;
    std::string name, tmp;
    std::cin >> n;
    std::cin >> name;

    std::vector<std::string> blocks;
    for (int i = 0; i != n; ++i) {
        std::cin >> tmp;
        blocks.push_back(tmp);
    }

    int nV = 2 * n + 2;
    int s = nV - 2, t = nV - 1;

    std::vector<std::vector<int>>
            cap(nV, std::vector<int>(nV)),
            flow(nV, std::vector<int>(nV));

    for (int i = 0; i != n; ++i) {
        cap[s][i] = 1;
    }
    for (int i = 0; i != n; ++i) {
        cap[n + i][t] = 1;
    }
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (blocks[i].find(name[j]) != std::string::npos) {
                cap[i][n + j] = 1;
            }
        }
    }

    std::vector<bool> vis;
    std::vector<int> from(nV);
    std::queue<int> q;
    for (size_t i = 0; i != name.size(); ++i) {
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
        if (!vis[t]) {
            std::cout << "NO";
            return 0;
        }
        int cur = t;
        while (cur != s) {
            int prev = from[cur];
            ++flow[prev][cur];
            --flow[cur][prev];
            cur = prev;
        }
    }
    std::cout << "YES\n";
    for (size_t i = 0; i != name.size(); ++i) {
        for (size_t j = 0; j != n; ++j) {
            if (flow[j][n + i] == 1) {
                std::cout << j + 1 << " ";
            }
        }
    }
    return 0;
}
