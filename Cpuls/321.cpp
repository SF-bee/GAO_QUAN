#include <bits/stdc++.h>
using ll = long long;
const int N = 105;
const int MAX = 2e3;

int w, h;
ll dp[MAX][N]; // dp_i_j 表示第i时刻在第j格子的最大收益

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> w >> h;
    int tim, pos, v, mak, M_tim = 0;
    while (std::cin >> tim >> pos >> v >> mak) {
        // if ((h - 1) % v == 0) {
        tim = tim + (h - 1) / v; // 向下取整
        M_tim = std::max(M_tim, tim);
        dp[tim][pos] += mak;
        // }
    }

    for (int i = M_tim - 1; i >= 0; i--) {
        for (int j = 1; j <= w; j++) {
            ll d = 0;
            if (j - 2 >= 1)
                d = std::max(d, dp[i + 1][j - 2]);
            if (j + 2 <= w)
                d = std::max(d, dp[i + 1][j + 2]);
            if (j - 1 >= 1)
                d = std::max(d, dp[i + 1][j - 1]);
            if (j + 1 <= w)
                d = std::max(d, dp[i + 1][j + 1]);
            d = std::max(d, dp[i + 1][j]);
            dp[i][j] += d;
        }
    }
    std::cout << dp[0][w / 2 + 1] << '\n';
    return 0;
}