#include <iostream>

void move(int n, int x, int y) {
    int tmp = 6 - x - y;
    if (n == 1) {
        std::cout << n << " " << x << " " << y << "\n";
    } else {
        move(n - 1, x, y);
        std::cout << n << " " << x << " " << tmp << "\n";
        move(n - 1, y, x);
        std::cout << n << " " << tmp << " " << y << "\n";
        move(n - 1, x, y);
    }
}

int main() {
    int numb;
    std::cin >> numb;
    move(numb, 1, 3);
    return 0;
}
