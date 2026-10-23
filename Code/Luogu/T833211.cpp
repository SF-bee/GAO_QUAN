#include <bits/stdc++.h>
const int MAX = 5e2 + 5;

int n, k;
int v[MAX], a[MAX], b[MAX];

void solve1() {
    std::sort(a + 1, a + n + 1);
    double ans = 0;
    for (int i = 1; i <= k; i++)
        ans += 1.0 * a[i] / v[0];
    std::cout << std::fixed << std::setprecision(6) << ans << '\n';
}
void solve2() { std::cout << 114514; }

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    bool flag1 = 1, flag2 = 1;
    std::cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        std::cin >> v[i];
        if (i > 0 && v[i] != v[i - 1]) flag1 = 0;
    }

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> b[i];
        if (b[i] != -1) flag2 = 0;
    }
    if (flag1 || flag2) solve1();
    else
        solve2();
    return 0;
}
/*
打部分分吧
#4-6 都不能提供模块，所以直接排个序就可以算了
#7-9 所有速度都相等，那么就是相当于拿模块没用，和上一档一样的
n < 70
是不是分层图啊
接入模块是不是越早越好呢？
如果我不修好这座塔，那么我也没必要为了拿模块去修这座塔？
不对吧，万一这座塔的拿模块费用很低呢？
背包吗？
设 dp[i][j][k] 表示考虑到第 i 个塔，有 j 个模块，修好了 k 座塔的最小用时
那么转移方程
第 i 座塔可以是修一半 dp[i - 1][j - 1][k] + b[i] / a[j - 1]
第 i 座塔可以是从修一半修好了 dp[i - 1][j][k - 1] + (a[i] - b[i]) / a[j]
或者是直接从 0 修好 dp[i - 1][j - 1][k - 1] + a[i] / a[j - 1]
枚举顺序呢？
不对，这样设计有后效性了，我先修后面的塔有可能让前面更优，可能需要排序
*/