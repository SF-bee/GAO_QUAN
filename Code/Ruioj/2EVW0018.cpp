#include <bits/stdc++.h>
const int MAX = 100;
using ll = long long;
using Row = std::array<ll, MAX>;

std::string s;
std::array<Row, MAX> dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> s;

    for (int len = 2; len <= s.size(); len++)
        for (int i = 0; i + len - 1 < s.size(); i++) {
            int j = i + len - 1;
            if (i == j - 1) {
                if (s[i] == '(' && s[j] == ')')
                    dp[i][j] = 1;
                continue;
            }
            for (int k = i; k < j; k++)
                if (dp[i][k] && dp[k + 1][j])
                    dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            if (dp[i + 1][j - 1] && s[i] == '(' && s[j] == ')')
                dp[i][j] = std::max(dp[i][j], 2 * dp[i + 1][j - 1]);
        }

    ll ans = 0;
    for (int len = 2; len <= s.size(); len++)
        for (int i = 0; i + len - 1 < s.size(); i++) {
            int j = i + len - 1;
            ans = std::max(ans, dp[i][j]);
        }
    std::cout << ans << '\n';
    return 0;
}