#include <bits/stdc++.h>
const int MAX = 1e3 + 5;
const int MAX_O = 30;
const int MAX_N = 100;

int o2, n2, n;
std::array<int, MAX> t, a, w;
int dp[MAX_O][MAX_N]; // dp_i_j 表示至少氧气i氮气j的最小负载

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> o2 >> n2 >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> t[i] >> a[i] >> w[i];

        std::memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = o2; j >= 0; j--) {
            for (int k = n2; k >= 0; k--) {
                dp[j][k] =
                    std::min(dp[j][k], dp[std::max(0, j - t[i])][std::max(0, k - a[i])] + w[i]);
            }
        }
    }
    std::cout << dp[o2][n2] << '\n';
    return 0;
}