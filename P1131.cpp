/*
考虑一个根相连的两棵子树的边权l1,l2，且走完两棵子树所需要的时间为t1,t2
则走完该节点的最长时间是max(l1+t1,l2+t2)
因此每一个低于这个时间的节点都应该补全与这个时间的差值。
? 是否应该有差值就应该补全呢
A 是的，若不补全，则这颗子树就不能同时结束
? 这样是否最优
A 感觉是的，因为最长的时间是由最后一个结束的节点控制的
*/
#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;

int n, s;
ll ans;
std::vector<std::pair<int, ll>> g[MAX];
std::array<ll, MAX> f; // f_i 表示走完以 i 为根的子树需要的最长时间

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> s;
    for (int u, v, d, i = 1; i < n; i++) {
        std::cin >> u >> v >> d;
        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }

    auto dfs = [&](auto &self, int u, int fa) -> void {
        ll max_tim = 0; // 表示走通与u相连的每个子树所需要的最长时间
        for (auto [v, dis] : g[u]) {
            if (v != fa) {
                self(self, v, u);
                max_tim = std::max(max_tim, dis + f[v]);
            }
        }
        f[u] = max_tim;
        for (auto [v, dis] : g[u]) {
            if (v != fa) {
                ans += max_tim - (dis + f[v]);
            }
        }
    };
    dfs(dfs, s, s);
    std::cout << ans << '\n';
    return 0;
}