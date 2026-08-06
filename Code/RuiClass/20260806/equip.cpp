#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e3 + 5;

int n, m;
char eq[MAX + 2][MAX + 2];
ll dp[MAX + 2][MAX + 2];

int main() {
    freopen("equip.in", "r", stdin);
    freopen("equip.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            eq[i][j] = '.';

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> eq[i][j];

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (eq[i][j] == '*') {
                dp[i][j] = 1;
                if (eq[i + 1][j] == '*' && eq[i + 1][j - 1] == '*' && eq[i + 1][j + 1] == '*')
                    dp[i][j] = std::min(dp[i + 1][j - 1], dp[i + 1][j + 1]) + 1;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += dp[i][j];
    std::cout << ans << '\n';
    return 0;
}
/*
一眼dp
dp[i][j] 表示以i,j为顶点的最大三角形
转移方程显然
现在考虑如何统计答案，因为转移存在覆盖，因此直接加贡献必然会有重复
考虑如何避免重复
可以只在最大的三角形计算贡献
可是我怎么知道现在是不是最大？？？
其实不需要，三角形大小就是这个顶点三角形的个数
*/