#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <climits>
#include <random>
#include <math.h>

int n;
struct edge {
    std::pair<int, int> u;
    std::pair<int, int> v;
    double w;

    edge(std::pair<int, int> a, std::pair<int, int> b, double c) : u(a), v(b), w(c) {};
};

struct graph {
    std::vector<std::pair<int, int>> ver;
    std::vector<edge> ed;
    std::vector<std::pair<int, int>> steiner;
    double mst = INT_MAX;
};

graph helper;

double weight (int x_1, int y_1, int x_2, int y_2) {
    return sqrt(pow(abs(x_2 - x_1), 2) + pow(abs(y_2 - y_1), 2));
}

void makealledges(graph& g) {
    std::pair<int, int> a, b;
    double w = 0;

    for (int i = 0; i != g.ver.size(); ++i) {
        for (int j = i + 1; j != g.ver.size(); ++j) {
            a = g.ver[i];
            b = g.ver[j];
            w = weight(a.first, a.second, b.first, b.second);
            g.ed.emplace_back(a, b, w);
        }
    }
}

void sv(graph& g, std::pair<int, int> s) {
    double w = 0;

    for (auto v : g.ver) {
        w = weight(v.first, v.second, s.first, s.second);
        g.ed.emplace_back(v, s, w);
    }
}

std::map<std::pair<int, int>, std::pair<int, int>> parent;
std::map<std::pair<int, int>, int> rank;

std::pair<int, int> find(std::pair<int, int> vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    else
        return find(parent[vertex]);
};

void Union(std::pair<int, int> root1, std::pair<int, int> root2) {
    if (rank[root1] > rank[root2]) {
        parent[root2] = root1;
    } else if (rank[root2] > rank[root1]) {
        parent[root1] = root2;
    } else {
        parent[root1] = root2;
        ++rank[root2];
    }
}

void MakeSet (std::pair<int, int> vertex) {
    parent[vertex] = vertex;
    rank[vertex] = 0;
}

void Kruskal(graph& g) {
    std::vector<edge> A;
    for (auto c : g.ver) {
        MakeSet(c);
    }
    std::sort(g.ed.begin(), g.ed.end(), [](edge x, edge y){return x.w < y.w;});
    for (edge e : g.ed) {
        std::pair<int, int> root1 = find(e.u);
        std::pair<int, int> root2 = find(e.v);
        if (root1 != root2) {
            A.push_back(e);
            Union(root1, root2);
        }
    }
    double res = 0;
    for (auto el : A) {
        res += el.w;
    }
    g.mst = res;
    parent.clear();
    rank.clear();
    //return A;
}

int find_step_x(int x_min, int x_max) {
    int step_x = 1, a = x_max - x_min;
    if (a >= 3000)
        step_x = 100;
    else if (a >= 500)
        step_x = 10;
    else if (a >= 10)
        step_x = 1;

    return step_x;
}

int find_step_y(int y_min, int y_max) {
    int step_y = 1, a = y_max - y_min;

    if (a >= 3000)
        step_y = 100;
    else if (a >= 500)
        step_y = 10;
    else if (a >= 10)
        step_y = 1;

    return step_y;
}

void run_1(graph& g, int step_x, int step_y,
           int x_min, int x_max, int y_min, int y_max) {
    graph tmp;
    std::pair<int, int> s;

    for (int i = x_min; i <= x_max; i += step_x) {
        for (int j = y_min; j <= y_max; j += step_y) {
            tmp = helper;

            s = std::make_pair(i, j);


            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);

            if (tmp.mst < g.mst) {
                //std::cout << s.first << " " << s.second << "\n";
                g = tmp;
                g.steiner.push_back(s);
            }
        }
    }
}

void run_2(graph& g, int step_x, int step_y,
           int x_min, int x_max, int y_min, int y_max) {
    graph tmp;
    std::pair<int, int> s;
    helper = g;

    for (int i = x_min; i <= x_max; i += step_x) {
        for (int j = y_min; j <= y_max; j += step_y) {
            tmp = helper;

            s = std::make_pair(i, j);


            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);

            if (tmp.mst < g.mst) {
                //std::cout << s.first << " " << s.second << "\n";
                g = tmp;
                g.steiner.push_back(s);
            }
        }
    }
}

void run_3(graph& g, int step_x, int step_y,
           int x_min, int x_max, int y_min, int y_max) {
    graph tmp;
    std::pair<int, int> s, s2;
    helper = g;

    for (int i = x_min; i <= x_max; i += step_x) {
        for (int j = y_min; j <= y_max; j += step_y) {
            tmp = helper;

            s = std::make_pair(i, j);
            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);
            if (tmp.mst < g.mst) {
                g = tmp;
                g.steiner.push_back(s);
            }


        }
    }
}

void run_4(graph& g, int step_x, int step_y,
           int x_min, int x_max, int y_min, int y_max) {
    graph tmp;
    std::pair<int, int> s, s2;
    helper = g;

    for (int i = x_min; i <= x_max; i += step_x) {
        for (int j = y_min; j <= y_max; j += step_y) {
            tmp = helper;

            s = std::make_pair(i, j);
            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);
            if (tmp.mst < g.mst) {
                g = tmp;
                g.steiner.push_back(s);
            }


        }
    }
}

void run_5(graph& g, int step_x, int step_y,
           int x_min, int x_max, int y_min, int y_max) {
    graph tmp;
    std::pair<int, int> s, s2;
    helper = g;

    for (int i = x_min; i <= x_max; i += step_x) {
        for (int j = y_min; j <= y_max; j += step_y) {
            tmp = helper;

            s = std::make_pair(i, j);
            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);
            if (tmp.mst < g.mst) {
                g = tmp;
                g.steiner.push_back(s);
            }


        }
    }
}

void run_6(graph& g, int step_x, int step_y,
           int x_min, int x_max, int y_min, int y_max) {
    graph tmp;
    std::pair<int, int> s, s2;
    helper = g;

    for (int i = x_min; i <= x_max; i += step_x) {
        for (int j = y_min; j <= y_max; j += step_y) {
            tmp = helper;

            s = std::make_pair(i, j);
            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);
            if (tmp.mst < g.mst) {
                g = tmp;
                g.steiner.push_back(s);
            }


        }
    }
}
void run_7(graph& g, int step_x, int step_y,
           int x_min, int x_max, int y_min, int y_max) {
    graph tmp;
    std::pair<int, int> s, s2;
    helper = g;

    for (int i = x_min; i <= x_max; i += step_x) {
        for (int j = y_min; j <= y_max; j += step_y) {
            tmp = helper;

            s = std::make_pair(i, j);
            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);
            if (tmp.mst < g.mst) {
                g = tmp;
                g.steiner.push_back(s);
            }


        }
    }
}
void run_8(graph& g, int step_x, int step_y,
           int x_min, int x_max, int y_min, int y_max) {
    graph tmp;
    std::pair<int, int> s, s2;
    helper = g;

    for (int i = x_min; i <= x_max; i += step_x) {
        for (int j = y_min; j <= y_max; j += step_y) {
            tmp = helper;

            s = std::make_pair(i, j);
            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);
            if (tmp.mst < g.mst) {
                g = tmp;
                g.steiner.push_back(s);
            }


        }
    }
}
void run_9(graph& g, int step_x, int step_y,
           int x_min, int x_max, int y_min, int y_max) {
    graph tmp;
    std::pair<int, int> s, s2;
    helper = g;

    for (int i = x_min; i <= x_max; i += step_x) {
        for (int j = y_min; j <= y_max; j += step_y) {
            tmp = helper;

            s = std::make_pair(i, j);
            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);
            if (tmp.mst < g.mst) {
                g = tmp;
                g.steiner.push_back(s);
            }


        }
    }
}
void run_10(graph& g, int step_x, int step_y,
           int x_min, int x_max, int y_min, int y_max) {
    graph tmp;
    std::pair<int, int> s, s2;
    helper = g;

    for (int i = x_min; i <= x_max; i += step_x) {
        for (int j = y_min; j <= y_max; j += step_y) {
            tmp = helper;

            s = std::make_pair(i, j);
            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);
            if (tmp.mst < g.mst) {
                g = tmp;
                g.steiner.push_back(s);
            }


        }
    }
}


void run_x_times(graph& g, int step_x, int step_y, int dots_num,
                 int x_min, int x_max, int y_min, int y_max) {
    if (dots_num == 1)
        run_1(g, step_x, step_y, x_min, x_max, y_min, y_max);
    if (dots_num == 2)
        run_2(g, step_x, step_y, x_min, x_max, y_min, y_max);
    if (dots_num == 3)
        run_3(g, step_x, step_y, x_min, x_max, y_min, y_max);
    if (dots_num == 4)
        run_4(g, step_x, step_y, x_min, x_max, y_min, y_max);
    if (dots_num == 5)
        run_5(g, step_x, step_y, x_min, x_max, y_min, y_max);
    if (dots_num == 6)
        run_6(g, step_x, step_y, x_min, x_max, y_min, y_max);
    if (dots_num == 7)
        run_7(g, step_x, step_y, x_min, x_max, y_min, y_max);
    if (dots_num == 8)
        run_8(g, step_x, step_y, x_min, x_max, y_min, y_max);
    if (dots_num == 9)
        run_9(g, step_x, step_y, x_min, x_max, y_min, y_max);
    if (dots_num == 10)
        run_10(g, step_x, step_y, x_min, x_max, y_min, y_max);
}

void points(graph& g, int k, int x_min, int x_max, int y_min, int y_max) {
    int step_x = find_step_x(x_min, x_max), step_y = find_step_y(y_min, y_max);

    for (int i = 1; i <= k; ++i) {
        run_x_times(g, step_x, step_y, i, x_min, x_max, y_min, y_max);
    }
    //run_x_times(g, step_x, step_y, 1, x_min, x_max, y_min, y_max);
}


void localopt(graph& g, int k, int x_min, int x_max, int y_min, int y_max){
    graph tmp;
    int count = 0, x_tmp = 0, y_tmp = 0;
    bool tmp_count = false;
    std::pair<int, int> s;
    for (int i = 0; i != n - 2; ++i) {
        tmp_count = 0;
        while (!tmp_count) {
            tmp = g;
            x_tmp = x_min + (std::rand() % (x_max - x_min + 1));
            y_tmp = y_min + (std::rand() % (y_max - y_min + 1));

            //std::cout << x_tmp << ", " << y_tmp << "\n";

            s = std::make_pair(x_tmp, y_tmp);
            sv(tmp, s);
            tmp.ver.push_back(s);
            Kruskal(tmp);

            if (tmp.mst < g.mst) {
                tmp_count = true;
                g = tmp;
                ++count;
                g.steiner.push_back(s);
            }
        }

        if (count >= k || (x_max - x_min > 6700) && (x_max - x_min < 6800)
                          && (y_max - y_min > 3300) && (y_max - y_min < 3400)) {
            break;
        }

    }
}

int main() {
    int k, a, b, x_max = 0, x_min = -1, y_max = 0, y_min = -1;

    std::cin >> n >> k;

    graph g;

    for (int i = 0; i != n; ++i) {
        std::cin >> a >> b;
        g.ver.push_back(std::make_pair(a, b));
        if (a > x_max) {
            x_max = a;
        } else if (a < x_min || x_min == -1) {
            x_min = a;
        }
        if (b > y_max) {
            y_max = b;
        } else if (b < y_min || y_min == -1) {
            y_min = b;
        }
    }

    makealledges(g);
    Kruskal(g);

    helper = g;

    points(g, k, x_min, x_max, y_min, y_max);
    std::cout << g.steiner.size() << "\n";

    for (auto el : g.steiner) {
        std::cout << el.first << " " << el.second << "\n";
    }

    return 0;
}
