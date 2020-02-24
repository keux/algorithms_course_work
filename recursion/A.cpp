#include <iostream>

void move(int n, int x, int y) {
    int tmp = 0;
    if (n == 1) {
        std::cout << 1 << " " << x << " " << y << "\n";
    } else {
        tmp = 6 - x - y;
        move(n - 1, x, tmp);
        std::cout << n << " " << x << " " << y << "\n";
        move(n - 1, tmp, y);
    }
}

int main() {
    int numb;
    std::cin >> numb;
    move(numb, 1, 3);
    return 0;
}
