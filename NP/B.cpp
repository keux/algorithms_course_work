#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <climits>
#include <deque>
#include <random>
#include <math.h>
#include <signal.h>

int n, done = 0;

using namespace std;

struct vertex {
    int id;
    int x;
    int y;
    int pos;
    bool visited;
    deque <vertex*> neighbor_list;

    vertex(int idin, int xin, int yin, int posin, bool visitedin) :
            id(idin), x(xin), y(yin), pos(posin), visited(visitedin) {};
};

double dist(vertex from, vertex to) {
    return sqrt(pow(abs(to.x - from.x), 2) + pow(abs(to.y - from.y), 2));
}

struct tsp {
    deque<vertex*> original_list;
    deque<vertex*> solution;
    int num_cities_otiginal_list;
    double solution_distance;
};

void copy_city_deque(deque<vertex*> &source, deque<vertex*> &dest) {
    int length = source.size();
    dest.clear();
    for (int i = 0; i < length; ++i) {
        dest.push_back(new vertex(*source[i]));
    }
}

double nearest_neighbor_basic(int start_index, tsp& g) {
    int cities_added = 0, closest_index = 0, current_num = g.num_cities_otiginal_list;
    double closest = INT_MAX, current_dist = 0, total_dist = 0;

    deque<vertex*> temp;
    copy_city_deque(g.original_list, temp);

    g.solution.clear();
    g.solution.push_back(g.original_list[start_index]);
    g.original_list.erase(g.original_list.begin() + start_index);

    --current_num; //remaining in orig_lst
    ++cities_added;

    while(current_num != 0) {
        closest = INT_MAX;

        for (int i = 0; i < current_num; ++i) {
            current_dist = dist(*g.original_list[i], *g.solution[cities_added - 1]);
            if (current_dist < closest) {
                closest_index = i;
                closest = current_dist;
            }
        }

        total_dist += closest;
        g.solution.push_back(g.original_list[closest_index]);
        g.original_list.erase(g.original_list.begin() + closest_index);

        --current_num;
        ++cities_added;
    }

    copy_city_deque(temp, g.original_list);
    return total_dist + dist(*g.solution[0], *g.solution[cities_added - 1]);

}

void get_solution_distance(tsp& g) {
    double total_dist = 0;
    for (int i = 0; i < n - 1; ++i) {
        total_dist += dist(*g.solution[i], *g.solution[i + 1]);
    }
    total_dist += dist(*g.solution[0], *g.solution[g.num_cities_otiginal_list - 1]);
    g.solution_distance = total_dist;
}

tsp swap_two(int i, int k, tsp& g) {
    tsp temporary = g;
    deque<vertex*> temp;
    int count = 0;

    for (int x = k; x >= i; --x) {
        temp.push_back(g.solution[x]);
    }

    for (int x = i; x <= k; ++x) {
        temporary.solution[x] = temp[count];
        ++count;
    }
    temp.clear();
    get_solution_distance(temporary);
    return temporary;
}

void two_opt(tsp& g) {
    int C = 0, r = 0;
    r = 10;

    tsp new_tsp;

    get_solution_distance(g);
    double best_distance = g.solution_distance;
    bool start_again = false;
    if (n > 2000) {
        for (int i = 1; i < n; ++i) {
            for (int k = i + 1; k < n - 1; ++k) {

                if (dist(*g.solution[i - 1], *g.solution[k]) + dist(*g.solution[i], *g.solution[k + 1]) <
                    dist(*g.solution[i - 1], *g.solution[i]) + dist(*g.solution[k], *g.solution[k + 1])) {
                    new_tsp = swap_two(i, k, g);
                    best_distance = new_tsp.solution_distance;
                    g = new_tsp;
                    C = 0;
                }
            }
        }
    } else {
        while (C <= r) {
            for (int i = 1; i < n; ++i) {
                for (int k = i + 1; k < n - 1; ++k) {

                    if (dist(*g.solution[i - 1], *g.solution[k]) + dist(*g.solution[i], *g.solution[k + 1]) <
                        dist(*g.solution[i - 1], *g.solution[i]) + dist(*g.solution[k], *g.solution[k + 1])) {
                        new_tsp = swap_two(i, k, g);
                        best_distance = new_tsp.solution_distance;
                        g = new_tsp;
                        C = 0;
                    }
                }
            }
            ++C;
        }
    }
}

void nearest_neighbor(tsp& g) {

    g.solution.clear();
    nearest_neighbor_basic(0, g);
    g.solution.push_back(g.solution[0]);
    two_opt(g);

    deque<vertex*> best = g.solution;
    double best_dist = g.solution_distance;

    if (n <= 25) {
        for (int z = 1; z != n; ++z) {
            g.solution.clear();
            nearest_neighbor_basic(z, g);
            g.solution.push_back(g.solution[0]);
            two_opt(g);
            if (g.solution_distance < best_dist) {
                best_dist = g.solution_distance;
                best = g.solution;
            }
        }
        tsp fir = g, sec = g;

        int p = 0;
        for (int i = 0; i != best.size(); ++i) {
            if (best[i]->id + 1 == 1) {
                p = i;
                break;
            }
        }
        g.solution.clear();
        sec.solution.clear();
        fir.solution.clear();
        for (int i = p; i != best.size() - 1; ++i) {
            fir.solution.push_back(best[i]);
        }
        for (int i = 0; i <= p; ++i) {
            fir.solution.push_back(best[i]);
        }

        for (int i = p; i >= 0; --i) {
            sec.solution.push_back(best[i]);
        }

        for (size_t i = p + 1; i < best.size() - 1; ++i) {
            sec.solution.push_back(best[i]);
        }
        sec.solution.push_back(best[p]);

        get_solution_distance(fir);
        get_solution_distance(sec);
        if (fir.solution_distance < sec.solution_distance) {
            g.solution = fir.solution;
        } else {
            g.solution = sec.solution;
        }
        //g.solution = sec.solution;
    }
}

deque<vertex*> dull(tsp& g) {
    //g.original_list.push_back(g.original_list[0]);
    deque<vertex*> best;
    copy_city_deque(g.original_list, g.solution);

    /*for (auto el : g.solution) {
        std::cout << el->id + 1 << " ";
    }*/

    get_solution_distance(g);

    //std::cout << g.solution_distance << "\n";
    double best_distance = g.solution_distance;
    best = g.solution;

    while (std::next_permutation(g.solution.begin() + 1, g.solution.begin() + n)) {

        get_solution_distance(g);

        /*for (auto el : g.solution) {
                std::cout << el->id + 1 << " ";
            }
            std::cout << " | ";
            std::cout << g.solution_distance << "\n";*/

        if (best_distance > g.solution_distance) {
            /*for (auto el : g.solution) {
                std::cout << el->id + 1 << " ";
            }
            std::cout << " | ";
            std::cout << g.solution_distance << "\n";*/
            //std::cout << best_distance << "\n";
            best_distance = g.solution_distance;
            best = g.solution;
        }
    }
    best.push_back(g.original_list[0]);
    return best;
}

int main() {
    int a, b;

    std::cin >> n;

    tsp g;
    g.num_cities_otiginal_list = n;

    for (int i = 0; i != n; ++i) {
        std::cin >> a >> b;
        g.original_list.push_back(new vertex(i, a, b, i, false));
    }

    if (n <= 0) {
        deque<vertex*> tmp = dull(g);
        g.solution = tmp;
    } else {
        nearest_neighbor_basic(0, g);
        nearest_neighbor(g);
    }
    //std::cout << g.solution_distance << "\n";
    for (auto el : g.solution) {
        std::cout << el->id + 1 << " ";
    }
    return 0;
}
