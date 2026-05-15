#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n;
std::array<int, MAX> a, f;
std::vector<int> g[MAX];
std::array<int, MAX> dp;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int u, v, i = 1; i < n; i++) {
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int ans = INT_MIN;
    auto dfs = [&](auto &self, int u, int fa) -> void {
        f[u] = a[u];
        int m1 = INT_MIN, m2 = INT_MIN;
        for (auto v : g[u])
            if (v != fa) {
                self(self, v, u), f[u] += f[v];
                if (dp[v] > m1) {
                    m2 = m1;
                    m1 = dp[v];
                } else if (dp[v] > m2) {
                    m2 = dp[v];
                }
            }
        dp[u] = std::max(f[u], m1);
        if (m1 != INT_MIN && m2 != INT_MIN)
            ans = std::max(ans, m1 + m2);
        return;
    };
    dfs(dfs, 1, 1);
    if (ans != INT_MIN)
        std::cout << ans << '\n';
    else
        std::cout << "Impossible\n";
    return 0;
}
/*
f[i] 表示以 i 为根的子树的价值和
dp[i]表示以 i 为根的子树选取的最大子树价值
*/