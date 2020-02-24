#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

int digit(std::string a, size_t i) {
    return a[a.size() - i] - '0';
}

int main() {
    size_t n;
    int len;
    std::string num, comma = "";

    std::cin >> n;

    std::vector<std::string> now;
    now.reserve(n);

    std::cout << "Initial array:\n";

    for (size_t i = 0; i != n; ++i) {
        std::cin >> num;
        now.push_back(num);
        std::cout << comma << num;
        comma = ", ";
    }
    std::cout << "\n**********\n";

    len = now[0].size();
    std::vector<int> C(10), C_copy(10);
    std::vector<std::string> result(now.size());
    int ind, cnt = 0, tmp;

    for (size_t i = 1; i <= len; ++i) {
        std::cout << "Phase " << i << "\n";
        for (size_t j = 0; j != now.size(); ++j) {
            ind = digit(now[j], i);
            C[ind] += 1;
        }
        cnt = 0;
        for (size_t j = 0; j != 10; ++j) {
            tmp = C[j];
            C[j] = cnt;
            cnt += tmp;
        }
        C_copy = C;
        for (size_t j = 0; j != now.size(); ++j) {
            ind = digit(now[j], i);
            result[C[ind]] = now[j];
            C[ind] += 1;
        }
        now = result;
        comma = "";
        std::cout << "Bucket " << 0 << ": ";
        if (C[0] == 0)
            std::cout << "empty";
        for (size_t w = 0; w != C[0]; ++w) {
            std::cout << comma << now[w];
            comma = ", ";
        }
        std::cout << "\n";
        for (size_t j = 0; j != 9; ++j) {
            comma = "";
            std::cout << "Bucket " << j + 1 << ": ";
            if (C[j + 1] == C[j])
                std::cout << "empty";
            for (size_t w = C[j]; w != C[j + 1]; ++w) {
                std::cout << comma << now[w];
                comma = ", ";
            }
            std::cout << "\n";
        }
        std::cout << "**********\n";
        C.assign(10, 0);
    }

    std::cout << "Sorted array:\n";

    comma = "";
    for (auto el : now) {
        std::cout << comma << el;
        comma = ", ";
    }

    return 0;
}
