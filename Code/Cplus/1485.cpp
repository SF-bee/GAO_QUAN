#include <bits/stdc++.h>
const int MAX = 1e3 + 5;
using ll = long long;
using Row = std::array<ll, MAX>;

int l, n;
std::array<int, MAX> c, v;
std::array<Row, MAX> dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> l >> n;
    std::memset(&dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
        std::cin >> c[i], dp[i][i] = 0;
    c[n + 1] = l;
    dp[n + 1][n + 1] = 0;

    for (int len = 2; len <= n + 1; len++)
        for (int i = 1; i + len - 1 <= n + 1; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + c[j] - c[i - 1]);
        }

    std::cout << "The minimum cutting is " << dp[1][n + 1] << ".\n";
    return 0;
}