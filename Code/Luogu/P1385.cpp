/*
dp_{i,j} 考虑到第 i 个字符，已经使用了总和为 j 的字典序的方案数
注意到每次询问真正有效的信息只有长度和字典序总和，考虑预处理

dp_{i,j} = /sum_{k = 1}^{n} dp_{i - 1,j - k}
考虑边界：dp_{0,0} = 1;

！！注意不包括串本身！！
*/
#include <bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9 + 7;
const int MAX = 1e2 + 5;
const int MAX_SUM = 3e3 + 5;

int T;
using Row = std::array<ll, MAX_SUM>;
std::array<Row, MAX> dp;

void add(ll &a, ll b) { a = (a + b >= MOD ? a + b - MOD : a + b); }
void PreSol() {
    dp[0][0] = 1;
    for (int i = 1; i < MAX; i++)
        for (int j = 0; j < MAX_SUM; j++) {
            for (int k = 0; k <= 25; k++) {
                if (j - k < 0)
                    continue;
                add(dp[i][j], dp[i - 1][j - k]);
            }
        }
}
void Solve() {
    std::string s;
    std::cin >> s;
    int len = s.size(), sum = 0;
    for (auto &ch : s)
        sum += ch - 'a';
    std::cout << dp[len][sum] - 1 << '\n';
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    PreSol();
    std::cin >> T;
    while (T--)
        Solve();
    return 0;
}