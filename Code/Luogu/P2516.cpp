#include <bits/stdc++.h>
const int MAX = 5e3 + 5;
const int mod = 1e8;

int n, m;
int dp[2][MAX], cnt[2][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::string a, b;
    std::cin >> a >> b;
    a.pop_back();
    b.pop_back();
    n = a.size();
    m = b.size();
    a = '#' + a;
    b = '#' + b;

    for (int i = 0; i <= m; i++)
        cnt[0][i] = 1;

    for (int i = 1; i <= n; i++) {
        memset(cnt[i & 1], 0, sizeof(cnt[i & 1]));
        cnt[i & 1][0] = 1;
        for (int j = 1; j <= m; j++) {
            dp[i & 1][j] = std::max(dp[(i & 1) ^ 1][j], dp[i & 1][j - 1]);
            if (a[i] == b[j]) {
                dp[i & 1][j] = std::max(dp[i & 1][j], dp[(i & 1) ^ 1][j - 1] + 1);
                if (dp[i & 1][j] == dp[(i & 1) ^ 1][j - 1] + 1)
                    (cnt[i & 1][j] += cnt[(i & 1) ^ 1][j - 1]) %= mod;
            }
            if (dp[(i & 1) ^ 1][j] == dp[i & 1][j]) (cnt[i & 1][j] += cnt[(i & 1) ^ 1][j]) %= mod;
            if (dp[i & 1][j - 1] == dp[i & 1][j]) (cnt[i & 1][j] += cnt[i & 1][j - 1]) %= mod;
            if (dp[i & 1][j - 1] == dp[(i & 1) ^ 1][j] && dp[i & 1][j - 1] == dp[i & 1][j]) {
                if (dp[i & 1][j] == dp[(i & 1) ^ 1][j - 1])
                    cnt[i & 1][j] = (cnt[i & 1][j] - cnt[(i & 1) ^ 1][j - 1] + mod) % mod;
            }
        }
    }
    std::cout << dp[n & 1][m] << '\n' << cnt[n & 1][m] << '\n';
    return 0;
}
/*
观察一件事情
最长公共子序列会增加当且仅当元素相同时，那么对于不同自序列的贡献，我们也可以仿照这种转移
cnt_i,j 表示到达 i，j 时的不同下标的个数
我们考虑答案是如何贡献的
如果dp[i - 1][j] = dp[i][j]
那么说明答案是从这个方向贡献过来的，直接加
另一个方向也是一样。
但是要考虑去重，如果上和下都是从左上转移过来的，那么就会重复，判断这个就可以
*/