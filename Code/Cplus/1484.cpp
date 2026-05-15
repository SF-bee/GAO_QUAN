#include <bits/stdc++.h>
const int MAX = 2e2 + 5;
using ll = long long;
using Row = std::array<ll, MAX>;

int n;
std::array<ll, MAX> a;
std::array<Row, MAX> v, dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i < 2 * n; i++)
        a[i + n] = a[i];

    for (int l = 2; l <= n; l++)
        for (int i = 1; i + l - 1 < 2 * n; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++)
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
        }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, dp[i][i + n - 1]);
    std::cout << ans << '\n';
    return 0;
}