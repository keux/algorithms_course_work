#include <iostream>
#include <vector>
#include <set>
#include <stack>

bool k = false;
std::vector<int> tmp;
std::vector<std::vector<int>> adj;
std::vector<int> colors;
int start;
std::stack<int> gst;

void dfs(int u) {
    gst.push(u);
    for (size_t i = 1; i != adj[u].size() + 1; ++i) {
        if (adj[u][i] == 1) {
            if (colors[i] == 0) {
                colors[i] = 3 - colors[u];
                dfs(i);
            } else if (colors[i] == colors[u]) {
                k = true;
                start = i;
            }
        }
        if (k)
            break;
    }
    if (k)
        return;
    gst.pop();
}


int main() {
    int n, a, col = 0;
    std::cin >> n;

    tmp.reserve(n);
    adj.assign(n + 1, std::vector<int>(n + 1));
    colors.assign(n + 1, 0);

    for (size_t i = 1; i != n + 1; ++i) {
        for (size_t j = 1; j != n + 1; ++j) {
            std::cin >> a;
            adj[i][j] = a;
        }
    }


    for (size_t i = 1; i != n + 1; ++i) {
        if (colors[i] == 0) {
            colors[i] = 1;
            dfs(i);
        }
        if (k)
            break;
    }

    std::stack<int> sec;
    int el;
    if (k) {
        while (gst.top() != start) {
            el = gst.top();
            sec.push(el);
            gst.pop();
        }
        el = gst.top();
        sec.push(el);
        std::cout << "YES\n";
        std::cout << sec.size() << "\n";
        while (!sec.empty()) {
            std::cout << sec.top() << " ";
            sec.pop();
        }
    } else {
        std::cout << "NO\n";
    }
    return 0;
}
