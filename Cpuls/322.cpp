/*
关键注意：
按照行进行转移不容易，并且容易产生重复贡献，需要考虑如何更优势的转移顺序
考虑按照对角线进行转移：
dp_i_j_k表示第 i 条从对角线已经敲掉了j块砖，这条对角线敲掉了k块砖的收益
这么看来，只需要思考我应该分别要在哪些对角线敲几块砖就可以了，有点像背包
是的，是很像背包，这就像是一个有依赖的背包，如果想要选某一个，就必须选某一个
如果提前预处理出每条对角线的前缀和呢？是的，那就完全变成依赖背包了
好吧，转移方程确实是一个难倒我的地方，我似乎不能想到应该如何处理依赖的问题。
不如回忆一下未加优化的背包
dp_i_j表示考虑到第i种物品，背包大小为j的最大收益
两种决策，选/不选
dp_i_j = /max{dp_i_j,dp_{i-1}_{j - w_i} + v_i}
哎，那么似乎这道题就可以做了
dp_i_j_k = /max(dp_i_j_k,dp_{i-1}_{j - W_i}_{k+?} + v_i)
k应该加多少似乎成了问题，首先，它应该从前一个-1或者更大的k转移过来
*/
#include <bits/stdc++.h>
const int N = 100;
const int M = 5e2 + 5;
template <typename T> using Row = std::array<T, N>;

int n, m;
std::array<Row<int>, N> a;
std::array<Row<int>, N> sum; // sum_i_j 表示第 i 条对角线敲掉了 k 块的得分
int dp[N][M][N];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - i + 1; j++)
            std::cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= i; k++)
            sum[i][k] = sum[i][k - 1] + a[k][i - k + 1];
    std::memset(dp, 0xf3, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++) {     // 枚举背包大小
            for (int k = 0; k <= i; k++) { // 枚举当前敲了多少块
                // 考虑从哪里转移过来
                if (j >= k)
                    for (int p = std::max(0, k - 1); p <= i - 1; p++)
                        if (dp[i - 1][j - k][p] >= 0)
                            dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j - k][p] + sum[i][k]);
            }
        }
    int ans = 0;
    for (int j = 1; j <= m; j++) // 枚举背包大小
        for (int k = 0; k <= n; k++)
            ans = std::max(ans, dp[n][j][k]);
    std::cout << ans << '\n';
    return 0;
}