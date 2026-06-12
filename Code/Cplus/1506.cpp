#include <bits/stdc++.h>
#define int long long
const int N = 1e2 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n;
using SP = std::array<int, N>;
using EP = std::array<SP, N>;
EP g, dp, ans;

signed main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    std::memset(&dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> g[i][j], dp[i][j] = (g[i][j] <= 0 ? INF : g[i][j]);

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            if (g[i][j] > dp[i][j] || i == j)
                ans[i][j] = ans[j][i] = 0;
            else {
                bool flag = 0;
                for (int k = 1; k <= n; k++)
                    if (k != i && k != j && dp[i][k] + dp[k][j] == dp[i][j]) {
                        ans[i][j] = ans[j][i] = 0;
                        flag = 1;
                        break;
                    }
                if (!flag) {
                    res += g[i][j];
                    ans[i][j] = ans[j][i] = 1;
                }
            }
        }
    std::cout << res << '\n';
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cout << ans[i][j] << " \n"[j == n];
    return 0;
}