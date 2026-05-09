#include <bits/stdc++.h>
const int N = 1e2 + 5;
const int M = 1e5 + 5;

int n, m;
std::array<int, N> a, c;
std::bitset<M> dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c[i]; j++)
            dp |= (dp << a[i]);
    }

    int con = 0;
    for (int i = 1; i <= m; i++)
        con += (dp[i] == 1);
    std::cout << con << '\n';
    return 0;
}
/*
注意到可行性背包
*/