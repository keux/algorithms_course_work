#include <iostream>
#include <vector>
#include <set>
#include <map>

int main() {
    size_t n, k;
    int pushes;
    char elem;

    std::cin >> n;

    std::map<char, int> alphabet;
    std::string temp = "";

    for (size_t i = 0; i != n; ++i) {
        std::cin >> elem;
        if (alphabet.find(elem) != alphabet.end()) {
            alphabet[elem] += 1;
        } else {
            alphabet[elem] = 1;
        }
    }

    for (auto letter : alphabet) {
        for (size_t i = 0; i != letter.second / 2; ++i) {
            std::cout << letter.first;
            temp += letter.first;
        }
    }

    for (auto letter : alphabet) {
        if (letter.second % 2 == 1) {
            std::cout << letter.first;
            break;
        }
    }

    for (int i = temp.size() - 1; i != -1; --i) {
        std::cout << temp[i];
    }

    return 0;
}
