#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

std::ostream& operator << (std::ostream& out, const
     std::vector<std::vector<std::string> >& mas) {
    for (size_t i = 0; i != mas.size(); ++i) {
        for (size_t j = 0; j != mas[0].size(); ++j) {
            if (mas[i][j] == "")
                out << " ";
            else
                out << mas[i][j];
        }
        out << "\n";
    }
    return out;
}

int main() {
    std::string line;
    std::map<char, int> letters;
    char c;
    int maximum = 0;
    while (std::cin >> c) {
        letters[c] += 1;
        if (letters[c] > maximum) maximum = letters[c];
    }
    std::vector<std::pair<char, int> > items(letters.begin(), letters.end());
    std::vector<std::vector<std::string> > gistogramm(maximum + 1,
                        std::vector<std::string>(letters.size()));
    for (size_t i = 0; i != items.size(); ++i) {
        for (size_t j = 0; j != items[i].second; ++j) {
            gistogramm[maximum - j - 1][i] = '#';
        }
        gistogramm[maximum][i] = items[i].first;
    }
    std::cout << gistogramm;
    return 0;
}
