#include <algorithm>
#include <iostream>
#include <vector>

struct edge {
    int u, v;
    double w = 0.0;
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
    int n, m, u, v;
    double sum = 0.0;
    std::cin >> n;

    std::vector<edge> E;
    std::vector<int> parent(1 + n, - 1);
    std::vector<int> x(n + 1), y(n + 1);
    E.reserve(m);

    for (size_t i = 1; i != n + 1; ++i) {
        std::cin >> x[i] >> y[i];
    }

    std::cin >> m;
    for (size_t i = 0; i != m; ++i) {
        std::cin >> u >> v;
        join(u, v, parent);
    }

    for (size_t i = 1; i != n + 1; ++i) {
        for (size_t j = i + 1; j != n + 1; ++j) {
            edge temp;
            temp.u = i;
            temp.v = j;
            int dx = (x[i] - x[j]) * (x[i] - x[j]);
            int dy = (y[i] - y[j]) * (y[i] - y[j]);
            temp.w = std::sqrt((dx + dy));
            E.push_back(temp);
        }
    }

    std::sort(E.begin(), E.end(), [](edge a, edge b){ return a.w < b.w;});

    for (auto ed : E) {
        if (join(ed.u, ed.v, parent)) {
            sum += ed.w;
        }
    }
    printf("%.5f", sum);

    return 0;
}
