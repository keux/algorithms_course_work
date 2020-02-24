#include <iostream>
#include <string>
#include <vector>

int main() {
    long long n, tmp, min = 1;

    std::cin >> n;

    std::vector<long long> path(n + 1), re;
    re.reserve(n + 1);
    path[0] = -1;
    tmp = n;

    for (int i = 1; i != n + 1; ++i) {
        min = path[i - 1] + 1;
        if (i % 2 == 0) {
            min = std::min(min, (path[i / 2] + 1));
        }
        if (i % 3 == 0) {
            min = std::min(min, path[i / 3] + 1);
        }
        path[i] = min;
    }

    re.push_back(tmp);

    while (tmp != 1) {
        if (tmp % 3 == 0 && (path[tmp] - 1) == path[tmp / 3]) {
            re.push_back(tmp / 3);
            tmp /= 3;
        } else if (tmp % 2 == 0 && (path[tmp] - 1) == path[tmp / 2]) {
            re.push_back(tmp / 2);
            tmp /= 2;
        } else {
            re.push_back(tmp - 1);
            tmp -= 1;
        }
    }

    std::cout << path[n] << "\n";
    for (int elem = 0; elem != re.size(); ++elem) {
        std::cout << re[re.size() - elem - 1] << " ";
    }
    return 0;
}
