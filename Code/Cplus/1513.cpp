#include <bits/stdc++.h>
using db = double;
const int MAX = 2e3 + 5;

int n, m, x, y;
std::array<db, MAX> dis;
std::array<bool, MAX> vis;
std::vector<std::pair<db, int>> g[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int u, v, d, i = 1; i <= m; i++) {
        std::cin >> u >> v >> d;
        g[u].emplace_back(d, v);
        g[v].emplace_back(d, u);
    }
    std::cin >> x >> y;
    dis.fill(0);
    std::priority_queue<std::pair<db, int>> q;
    for (q.push({dis[x] = 1, x}); !q.empty();) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &[e, v] : g[u])
            if (dis[v] < dis[u] * (1 - e / 100))
                q.push({dis[v] = dis[u] * (1 - e / 100), v});
    }
    std::cout << std::fixed << std::setprecision(8) << 100 / dis[y] << '\n';
    return 0;
}