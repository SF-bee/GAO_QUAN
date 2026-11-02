#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e3 + 5;
const ll mod = 1e9 + 7;

int n;
std::string s;
ll dp[MAX][27][27];

int main() {
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> s;
    s = '&' + s;

    // 先判不合法
    if (s[2] != '?' && s[1] != '?' && s[1] == s[2]) {
        std::cout << "Sorry!\n";
        return 0;
    }
    for (int i = 3; i <= n; i++)
        if (s[i] != '?') {
            if (s[i - 1] != '?' && s[i - 1] == s[i]) {
                std::cout << "Sorry!\n";
                return 0;
            }
            if (s[i - 2] != '?' && s[i - 2] == s[i]) {
                std::cout << "Sorry!\n";
                return 0;
            }
        }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 26; j++) {
            for (int k = 0; k <= 26; k++) {
                for (int c = 1; c <= 26; c++) {
                    if (s[i] != '?' && s[i] - 'a' + 1 != c) continue;
                    if (c != k && c != j) dp[i][c][j] = (dp[i][c][j] + dp[i - 1][j][k]) % mod;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 26; i++)
        for (int j = 1; j <= 26; j++)
            ans = (ans + dp[n][i][j]) % mod;
    std::cout << ans << '\n';
    return 0;
}
/*
相邻一定不能相同
相隔一个也不能相同
相同字符不能出现超过一半，那么按照鸽巢原理
不合法字符串的字符至少是相隔一个甚至相邻出现
那么也就是说，只要相邻不相同，相隔也不相同，那么就不会出现超过一半的字符
更加严谨的证明：
假设长度为 l-3 的字符串是合法的，那么 [l-2,l] 如果不会有超过一半的数据
那么拼接起来也一定不会有超过一半的某个字符
问题转化为：求一个字符串中相邻不相同，相隔也不相同的方案
设 f[i][j][k] 表示前 i 个字符，最后一个字符是 j，倒数第二个字符是 k 的方案数
考虑转移
枚举当前位c，前一位j，前两位k，当且仅当
c
*/