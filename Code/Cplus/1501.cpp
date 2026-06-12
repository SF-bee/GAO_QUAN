#include <bits/stdc++.h>
const int MAX = 1e2 + 5;
const int INF = 0x3f3f3f3f;

int n, m;
std::vector<std::pair<int, int>> g[MAX];
std::array<int, MAX> dis;
std::array<bool, MAX> vis;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int u, v, d, i = 1; i <= m; i++) {
        std::cin >> u >> v >> d;
        g[u].emplace_back(d, v);
        g[v].emplace_back(d, u);
    }

    std::memset(&dis, 0x3f, sizeof(dis));
    std::priority_queue<std::pair<int, int>> q;
    for (q.push({dis[1] = 0, 1}); !q.empty();) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u])
            continue;
        for (auto [_d, v] : g[u])
            if (dis[v] > dis[u] + _d)
                q.push({-(dis[v] = dis[u] + _d), v});
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) {
            std::cout << -1 << '\n';
            return 0;
        } else {
            ans = std::max(ans, dis[i]);
        }
    }
    std::cout << ans << '\n';
    return 0;
}