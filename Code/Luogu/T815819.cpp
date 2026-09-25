#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e2 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, r;
int p[MAX], a[MAX][MAX];
std::vector<std::pair<int, int>> pr[MAX];

ll solve(int s) {
    std::vector<std::pair<int, int>> g[MAX];
    std::vector<bool> vis(n + 1);
    for (auto [u, v] : pr[r]) {
        g[u].emplace_back(v, 1);
        g[v].emplace_back(u, 1);
    }
    for (auto [u, v] : pr[s]) {
        g[u].emplace_back(v, 2);
        g[v].emplace_back(u, 2);
    }
    ll s1 = 0, s2 = 0;
    auto dfs = [&]() {};
    for (int i = 1; i <= n; i++) {
        if (i == r || i == s || i == a[r][s]) continue;
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> r;
    for (int i = 1; i <= n; i++)
        std::cin >> p[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
            pr[a[i][j]].push_back({i, j});
        }

    ll ans = INF;
    for (int s = 1; s <= n; s++) {
        if (s == r) continue;
        ans = std::min(ans, solve(s));
    }
    std::cout << ans << '\n';
    return 0;
}