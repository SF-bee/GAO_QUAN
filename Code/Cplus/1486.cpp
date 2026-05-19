#include <bits/stdc++.h>
const int MAX = 1e2 + 5;
using ll = long long;
using Row = std::array<ll, MAX>;

int n;
std::array<ll, MAX> a;
// dp_{i,j} 表示仅剩余区间[i,j]内的最大得分
std::array<Row, MAX> dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    std::memset(&dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], dp[i][i + 1] = 0;

    for (int l = 3; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            for (int k = i + 1; k <= j - 1; k++)
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
        }

    std::cout << dp[1][n] << '\n';
    return 0;
}