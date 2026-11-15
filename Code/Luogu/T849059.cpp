#include <bits/stdc++.h>
using ll = long long;
const int K = 102;
const int MAX = 2e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, r[MAX], s[MAX];
ll a[MAX];
std::vector<int> g[MAX];
ll dp[MAX][K];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int k = -50; k <= 51; k++)
            dp[i][k + 50] = -INF;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> r[i];
    for (int u, v, i = 1; i < n; i++)
        std::cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

    auto dfs = [&](auto &self, int u, int fa) -> void {
        for (auto v : g[u])
            if (v != fa) self(self, v, u);

        // 选 u
        ll res = a[u];
        for (auto v : g[u])
            if (v != fa) {
                ll mr = 0;
                for (int k = r[u]; k <= 51; k++)
                    mr = std::max(mr, dp[v][k + 50]);
                res += mr;
            }
        dp[u][-r[u] + 50] = res;
        // 不选
        ll f[K];
        for (int k = -50; k <= 51; k++)
            f[k + 50] = -INF;
        f[51 + 50] = 0;
        for (auto v : g[u])
            if (v != fa) {
                ll g[K];
                for (int s = -50; s <= 51; s++)
                    g[s + 50] = -INF;
                for (int s = -50; s <= 51; s++) {
                    int k = std::min(51, s + 1);
                    g[k + 50] = std::max(g[k + 50], dp[v][s + 50]);
                }
                ll F[K + 1], G[K + 1];
                F[K] = G[K] = -INF;
                for (int s = 51; s >= -50; s--)
                    F[s + 50] = std::max(f[s + 50], F[s + 51]),
                          G[s + 50] = std::max(g[s + 50], G[s + 51]);
                ll h[K];
                for (int k = -50; k <= 51; k++)
                    h[k + 50] = -INF;
                for (int k = 51; k >= -50; k--) {
                    int p = std::max(k, 1 - k);
                    if (f[k + 50] != -INF && G[p + 50] != -INF)
                        h[k + 50] = std::max(h[k + 50], f[k + 50] + G[p + 50]);
                    if (g[k + 50] != -INF && F[p + 50] != -INF)
                        h[k + 50] = std::max(h[k + 50], g[k + 50] + F[p + 50]);
                }
                std::memcpy(f, h, sizeof f);
            }
        for (int k = -50; k <= 51; k++)
            dp[u][k + 50] = std::max(dp[u][k + 50], f[k + 50]);
    };
    dfs(dfs, 1, 1);
    ll ans = 0;
    for (int k = -50; k <= 51; k++)
        ans = std::max(ans, dp[1][k + 50]);
    std::cout << ans;
    return 0;
}
/*
正向求解是很困难的，因为具有后效性。
算了，看部分分：
n <= 20，枚举所有选择，20 * 2^20
r = 1，说明每个点都不会影响到其他点，那么最有当然是全部都选上
  答案就是 \sum{a_i}
退化成链，那么，线段覆盖？？？对，这不就是线段覆盖吗
我们是怎么做的？按照右端点排序然后 dp，dp_i 表示以 i 结束的最大价值
然后就可以转移了。二分优化：因为结尾已经有序了，所以二分最后一个小于当前左端点就可以了
那强化到树上？r_i 是很小的，这也许是突破口
d_u,v > r_u + r_v
设 b_u,v = d_u,v - r_v
换句话说：覆盖到外头的我们就记会覆盖 -b 条边，否则就没有覆盖到外头，离根 b 条边
那么一颗子树内最远的覆盖就是 s_u = min{b_u,v}
那么 x 的两棵子树不冲突当且仅当
s_u + s_v > 0
换句话说，要么你都离根有一定距离，要么一个很远，但是另一个能让出足够的位置
那么设 dp[x][s] 表示 以 x 为根节点，覆盖参数为 s 的最大价值
转移就是:
1、不选 u，尝试合并所有的儿子
  记录一个参数 t，能够合并当 s + t > 0
2、选择 u，枚举每一个儿子的 s' ，那么就要
  s' + 1 > r_u
复杂度是 O(nr^2)，这里怎么优化

*/
