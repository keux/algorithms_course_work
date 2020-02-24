#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>

void Heapify(std::vector<int>& A, int i, int heap_size) {
    int l = 2 * i, r = 2 * i + 1, largest = i;

    if (l <= heap_size && A[l - 1] > A[i - 1]) {
        largest = l;
    }

    if (r <= heap_size && A[r - 1] > A[largest - 1]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(A[i - 1], A[largest - 1]);
        Heapify(A, largest, heap_size);
    }
}

void Heapsort(std::vector<int>& A) {
    int n = A.size();
    for (int i = n / 2; i >= 1; i--) {
        Heapify(A, i, n);
    }
    for (int i = n - 1; i >= 1; --i) {
        std::swap(A[0], A[i]);
        Heapify(A, 1, i);
    }
    for (auto el : A) {
        std::cout << el << " ";
    }
}

int main() {
    size_t n;
    int num;

    std::cin >> n;

    std::vector<int> A;
    A.reserve(n);

    for (size_t i = 0; i != n; ++i) {
        std::cin >> num;
        A.push_back(num);
    }

    Heapsort(A);
    return 0;
}
