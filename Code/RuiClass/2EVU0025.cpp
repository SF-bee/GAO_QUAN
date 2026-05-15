#include <bits/stdc++.h>
const int MAX = 3e2 + 5;
using ll = long long;
using Row = std::array<ll, MAX>;

int n;
std::array<Row, MAX> v, dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    std::memset(&dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
        std::cin >> v[i][i], dp[i][i] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            v[i][j] = v[i][j - 1] | v[j][j];

    for (int l = 2; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i][j]);
            }
        }

    std::cout << dp[1][n] << '\n';
    return 0;
}