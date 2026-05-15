/*
考虑dp
dp[t][i] 表示第t秒到达位置i时的最大收益
! 注意到t过大而不能直接开这么大的数组，尝试进行离散化
! 注意到x只有10,所以随便开
！注意到只能转移上次转移到的
*/
#include <bits/stdc++.h>
using Row = std::array<int, 20>;
const int MAX = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n;
std::array<Row, MAX> dp;

void solve() {
    dp.fill({});
    int T = 0;
    for (int t, x, i = 1; i <= n; i++) {
        std::cin >> x >> t;
        dp[t][x]++;
        T = std::max(T, t);
    }
    for (int t = T - 1; t >= 0; t--) {
        for (int i = 0; i <= 10; i++) {
            int d = 0;
            if (i - 1 >= 0)
                d = std::max(d, dp[t + 1][i - 1]);
            if (i + 1 <= 10)
                d = std::max(d, dp[t + 1][i + 1]);
            d = std::max(d, dp[t + 1][i]);
            dp[t][i] += d;
        }
    }
    std::cout << dp[0][5] << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    while (std::cin >> n) {
        if (n == 0)
            break;
        else
            solve();
    }
    return 0;
}