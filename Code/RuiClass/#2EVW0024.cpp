#include <bits/stdc++.h>
const int MAX = 2e2 + 5;
const int MOD = 1e9 + 7;
using ll = long long;
using Row = std::array<ll, MAX>;

int n;
std::string s;
std::array<Row, MAX> dp; // dp_{i,j} 表示区间 [i,j] 中回文子序列的数量

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> s;
    n = s.size();
    s = "$" + s;

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            if (l == 1)
                dp[i][i] = 1;
            else {
                int j = i + l - 1;
                if (s[i] != s[j])
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                else
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
            }
        }
    }

    std::cout << dp[1][n] << '\n';
    return 0;
}