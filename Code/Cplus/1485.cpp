/*

dp_{i,j} 表示在区间 [i,j]可以获得的最大收益

*/

#include <bits/stdc++.h>

const int MAX = 1e3 + 5;

using ll = long long;

using Row = std::array<ll, MAX>;

int l, n;

std::array<ll, MAX> a;

std::array<Row, MAX> dp;

int main() {

    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> l >> n;

    std::memset(&dp, 0x3f, sizeof(dp));

    a[0] = 0, a[n + 1] = l;

    for (int i = 1; i <= n; i++)

        std::cin >> a[i], dp[i - 1][i] = 0;

    dp[n][n + 1] = 0;

    for (int len = 3; len <= n; len++)

        for (int i = 0; i + len - 1 <= n + 1; i++) {

            int j = i + len - 1;

            for (int k = i + 1; k <= j - 1; k++) {

                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] + (a[j] - a[k]));

                std::cout << dp[i][j] << " \n"[k == j - 1];
            }
        }

    std::cout << dp[0][n + 1] << '\n';

    return 0;

} /*

 dp_{i,j} 表示在区间 [i,j]可以获得的最大收益

 */

#include <bits/stdc++.h>

const int MAX = 1e3 + 5;

using ll = long long;

using Row = std::array<ll, MAX>;

int l, n;

std::array<ll, MAX> a;

std::array<Row, MAX> dp;

int main() {

    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> l >> n;

    std::memset(&dp, 0x3f, sizeof(dp));

    a[0] = 0, a[n + 1] = l;

    for (int i = 1; i <= n; i++)

        std::cin >> a[i], dp[i - 1][i] = 0;

    dp[n][n + 1] = 0;

    for (int len = 3; len <= n; len++)

        for (int i = 0; i + len - 1 <= n + 1; i++) {

            int j = i + len - 1;

            for (int k = i + 1; k <= j - 1; k++) {

                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] + (a[j] - a[k]));

                std::cout << dp[i][j] << " \n"[k == j - 1];
            }
        }

    std::cout << dp[0][n + 1] << '\n';

    return 0;
}