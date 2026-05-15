#include <bits/stdc++.h>
const int MAX = 5e2;
template <typename T> using Row = std::array<T, MAX>;

std::string s;
std::array<Row<int>, MAX> dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> s;

    for (int len = 2; len <= s.size(); len += 2) {
        for (int l = 0; l + len - 1 < s.size(); l++) {
            int r = l + len - 1;
            if (l == r - 1 && s[l] == '(' && s[r] == ')') {
                dp[l][r] = 1;
                continue;
            }
            for (int k = l; k < r; k++)
                if (dp[l][k] && dp[k + 1][r]) {
                    dp[l][r] = 1;
                    break;
                }
            if (dp[l + 1][r - 1] && s[l] == '(' && s[r] == ')')
                dp[l][r] = 1;
        }
    }

    int ans = 0;
    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0; l + len - 1 < s.size(); l++) {
            int r = l + len - 1;
            if (dp[l][r])
                ans = std::max(ans, r - l + 1);
        }
    }
    std::cout << ans << '\n';
    return 0;
}