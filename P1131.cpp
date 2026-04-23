#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;

int n, s, ans;
std::vector<std::pair<int, ll>> g[MAX];
std::array<ll, MAX> f; // f_i 表示走完以 i 为根的子树需要的最长时间

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> s;
    for (int u, v, d, i = 1; i <= n; i++) {
        std::cin >> u >> v >> d;
        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }

    auto dfs = [&](auto &self, int u, int fa) -> void {
        for (auto [v, dis] : g[u]) {
            if (v != fa) {
                if ()
            }
        }
    };
    return 0;
}