#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n;
std::array<int, MAX> r, g, b;
std::array<int, MAX> f[3];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> r[i];
    for (int i = 1; i <= n; i++)
        std::cin >> g[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    for (int i = 1; i <= n; i++) {
        f[0][i] = std::min(f[1][i - 1], f[2][i - 1]) + r[i];
        f[1][i] = std::min(f[0][i - 1], f[2][i - 1]) + g[i];
        f[2][i] = std::min(f[0][i - 1], f[1][i - 1]) + b[i];
    }

    std::cout << std::min({f[0][n], f[1][n], f[2][n]}) << '\n';
    return 0;
}
/*
f[c][i] 表示把第 i 个瓶子，涂成 c 色的最小花费
f[c][i] = std::min({f[c' != c][i - 1]}) +
*/