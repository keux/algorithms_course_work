#include <iostream>
#include <vector>
#include <set>

const int inf = 1000000000;

void dij(std::vector<int>& d, std::vector<bool>& mark, int n, int r,
         std::vector<std::vector<int>> a) {
    while (true) {
        int ind = -1;
        for (int j = 1; j != n + 1; ++j) {
            if (!mark[j] && d[j] != inf & (ind == -1 || d[j] < d[ind])) {
                ind = j;
            }
        }
        if (ind == -1)
            break;
        for (auto i = 1; i != r + 1; ++i) {
            if (a[i][0] == ind) {
                if (!mark[a[i][2]] && a[i][1] >= d[ind] && d[a[i][2]] > a[i][3]) {
                    d[a[i][2]] = a[i][3];
                }
            }
        }
        mark[ind] = true;
    }
}

int main() {
    int n, start, finish, r;
    std::cin >> n >> start >> finish >> r;

    std::vector<std::set<int>> adj(n + 1);
    std::vector<int> time(n + 1, inf);
    std::vector<bool> mark(n + 1, false);
    std::vector<std::vector<int>> a(r + 1, std::vector<int>(4));


    for (int i = 1; i != r + 1; ++i) {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        //          town       from   finish_town      to
    }

    time[start] = 0;

    dij(time, mark, n, r, a);

    /*for(auto el : time)
        std::cout << el << " ";
    std::cout << "\n";*/
    if (time[finish] >= inf)
        std::cout << -1 << "\n";
    else
        std::cout << time[finish] << "\n";
    return 0;
}
