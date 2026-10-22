#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;
const ll mod = 1e9 + 7;

int n;
std::vector<int> g[MAX];
ll siz[MAX];

int main() {
    freopen("star.in", "r", stdin);
    freopen("star.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int u, v, i = 1; i < n; i++)
        std::cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

    ll ans = 0;
    auto dfs = [&](auto &self, int u, int fa) -> void {
        siz[u] = 1;
        ll All = 1, SumSiz = 0, SumSiz2 = 0;
        for (auto v : g[u])
            if (v != fa) {
                self(self, v, u);
                siz[u] += siz[v];
                All = All * (siz[v] + 1) % mod;
                SumSiz += siz[v];
                SumSiz2 = SumSiz2 + siz[v] * siz[v];
            }
        ll FaSiz = (n - siz[u]);
        All = All * (FaSiz + 1) % mod;
        SumSiz = SumSiz + FaSiz;
        SumSiz2 = SumSiz2 + FaSiz * FaSiz;
        ll _ = ((SumSiz * SumSiz - SumSiz2) / 2) % mod;
        ll d = (All - 1 - SumSiz % mod - _ % mod) % mod;
        d = (d + mod) % mod;
        ans = (ans + d) % mod;
    };
    dfs(dfs, 1, 0);
    std::cout << ans << '\n';
    return 0;
}
/*
又见面了老师，真是意气风发啊
考虑以 u 为根的情况吧，考虑他的儿子 v
这个儿子 v 可以延伸出多少条链? siz[v]条
正着算非常困难啊。我们应该反着算
总共多少种方案？\pi siz[v] + 1
什么是不合法的方案？只留了两条，一条，和没有的方案
没有的方案是 1
一条的方案是 \sum siz[v]
两条的方案是 \sum\sum siz[i]*siz[j]
这个需要枚举吗？不需要的，\sum siz[v] 平方，减掉 \sum siz[v]^2，最后除以二
*/