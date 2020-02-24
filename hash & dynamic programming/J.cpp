#include <iostream>
#include <string>
#include <vector>

const int inf = 32000;

std::string X, Y, t;
std::vector<std::vector<int>> L(80, std::vector<int>(80, -1)),
        H1(80, std::vector<int>(80)), H2(80, std::vector<int>(80)),
        Min1(80, std::vector<int>(80)), Min2(80, std::vector<int>(80));

int M(int p, int i, int j) {
    if (i > j) {
        return 0;
    } else {
        if (p == 1)
            return Min1[i][j];
        else if (p == 2)
            return Min2[i][j];
    }
}

std::string GetM(int p, int i, int j) {
    int k;
    std::string s;
    char ch;

    s = "";
    for (k = i; k != j + 1; ++k) {
        if (p == 1) {
            ch = X[k];
        } else if (p == 2) {
            ch = Y[k];
        }
        if (ch == '?')
            ch = 'a';
        if (ch != '*')
            s += ch;
    }
    return s;
}

int CalcLength(int a, int b) {
    if (L[a][b] == -1) {
        L[a][b] = inf;
        if (a > 0 && X[a] == '*') {
            for (int i = b; i >= 0; --i) {
                if (L[a][b] > CalcLength(a - 1, i) + M(2, i + 1, b)) {
                    L[a][b] = CalcLength(a - 1, i) + M(2, i + 1, b);
                    H1[a][b] = a - 1;
                    H2[a][b] = i;
                }
            }
        } else if (b > 0 && Y[b] == '*') {
            for (int i = a; i >= 0; --i) {
                if (L[a][b] > CalcLength(i, b - 1) + M(1, i + 1, a)) {
                    L[a][b] = CalcLength(i, b - 1) + M(1, i + 1, a);
                    H2[a][b] = b - 1;
                    H1[a][b] = i;
                }
            }
        } else if (a > 0 && b > 0 && (X[a] == '?' || Y[b] == '?' || X[a] == Y[b])) {
            L[a][b] = CalcLength(a - 1, b - 1) + 1;
            H1[a][b] = a - 1;
            H2[a][b] = b - 1;
        }
    }
    return L[a][b];
}


void writeM(int a, int b, int c) {
    t += GetM(a, b, c);
}

void writeStr(int a, int b) {
    int i;
    if (a > 0 && X[a] == '*') {
        i = H2[a][b];
        writeStr(H1[a][b], H2[a][b]);
        writeM(2, i + 1, b);
    } else if (b > 0 && Y[b] == '*') {
        i = H1[a][b];
        writeStr(H1[a][b], H2[a][b]);
        writeM(1, i + 1, a);
    } else if (a > 0 && b > 0 && (X[a] == '?' || Y[b] == '?' || X[a] == Y[b])) {
        writeStr(H1[a][b], H2[a][b]);
        if (X[a] != '?')
            t += X[a];
        else if (Y[b] != '?')
            t += Y[b];
        else
            t += 'a';
    }
}

int main() {
    int k, l;
    std::cin >> t;
    X = "0";
    X += t;
    std::cin >> t;
    Y = "0";
    Y += t;
    L[0][0] = 0;

    for (int i = 1; i != X.size() + 1; ++i) {
        k = 0;
        for (int j = i; j != X.size() + 1; ++j) {
            if (X[j] != '*')
                ++k;
            Min1[i][j] = k;
        }
    }
    for (int i = 1; i != Y.size() + 1; ++i) {
        k = 0;
        for (int j = i; j != Y.size() + 1; ++j) {
            if (Y[j] != '*')
                ++k;
            Min2[i][j] = k;
        }
    }
    t = "";
    l = CalcLength(X.size(), Y.size());
    if (l >= inf) {
        std::cout << "No solution!";
    } else {
        writeStr(X.size(), Y.size());
        for (size_t i = 0; i != t.size() - 1; ++i) {
            std::cout << t[i];
        }
    }

    return 0;
}
