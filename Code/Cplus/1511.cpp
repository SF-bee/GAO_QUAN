#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e2;

int n, m, x, y;
std::array<ll, MAX> dis;
std::array<bool, MAX> vis;
std::vector<std::pair<ll, int>> g[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int u, v, d, i = 1; i <= m; i++) {
        std::cin >> u >> v >> d;
        g[u].emplace_back(d, v);
        g[v].emplace_back(d, u);
    }
    std::cin >> x >> y;
    dis.fill(0x3f3f3f3f3f3f3f3f);
    std::priority_queue<std::pair<ll, int>> q;
    for (q.push({dis[x] = 0, x}); !q.empty();) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &[e, v] : g[u])
            if (dis[v] > dis[u] + e)
                q.push({-(dis[v] = dis[u] + e), v});
    }
    if (dis[y] == 0x3f3f3f3f3f3f3f3f)
        std::cout << "No path\n";
    else
        std::cout << dis[y] << '\n';
    return 0;
}