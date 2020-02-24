#include <iostream>
void anti(int n, int x, int y);

void clocko(int n, int x, int y) {
    int tmp = 6 - x - y;
    if (n > 0) {
        anti(n - 1, x, tmp);
        std::cout << n << " " << x << " " << y << "\n";
        anti(n - 1, tmp, y);
    }
}

void anti(int n, int x, int y) {
    int tmp = 6 - x - y;
    if (n > 0) {
        anti(n - 1, x, y);
        std::cout << n << " " << x << " " << tmp << "\n";
        clocko(n - 1, y, x);
        std::cout << n << " " << tmp << " " << y << "\n";
        anti(n - 1, x, y);
    }
}

int main() {
    int numb;
    std::cin >> numb;
    anti(numb, 1, 3);
    return 0;
}
