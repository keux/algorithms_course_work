#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <climits>

const int white = 0, gray = 1, black = 2;
struct edge {
    int u, v, w, color = white;
};

int getRoot(int v, std::vector<int>& parent) {
    if (parent[v] < 0) {
        return v;
    } else {
        int root = getRoot(parent[v], parent);
        parent[v] = root;
        return root;
    }
}

bool join(int a, int b, std::vector<int>& parent) {
    a = getRoot(a, parent);
    b = getRoot(b, parent);
    if (a == b) {
        return false;
    }
    assert(parent[a] < 0);
    assert(parent[b] < 0);
    if (parent[a] < parent[b]) {
        parent[a] += parent[b];
        parent[b] = a;
    } else {
        parent[b] += parent[a];
        parent[a] = b;
    }
    return true;
}

int main() {
    int n, m, sum = 0, sum2 = INT_MAX;
    std::cin >> n >> m;

    std::vector<edge> E;
    std::vector<int> parent(1 + n, - 1);
    E.reserve(n * n);

    for (size_t i = 0; i != m; ++i) {
        edge temp;
        std::cin >> temp.u >> temp.v >> temp.w;
        E.push_back(temp);
    }

    std::sort(E.begin(), E.end(), [](const edge& a, const edge& b){ return a.w < b.w;});

    for (edge &ed : E) {
        if (join(ed.u, ed.v, parent)) {
            sum += ed.w;
            ed.color = gray;
        }
    }

    for (edge &ed : E) {
        if (ed.color == gray) {
            ed.color = black;

            int temp_sum = 0, numb_ed = 0;
            parent.assign(n + 1, -1);
            for (edge& ed2 : E) {
                if (ed2.color != black && join(ed2.u, ed2.v, parent)) {
                    temp_sum += ed2.w;
                    ++numb_ed;
                }
            }
            if (numb_ed == n - 1) {
                sum2 = std::min(sum2, temp_sum);
            }
        }
        ed.color = gray;
    }

    std::cout << sum << " " << sum2;
    return 0;
}
