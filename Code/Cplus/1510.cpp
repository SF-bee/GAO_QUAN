#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e3 + 5;

int t, c, ts, te;
std::array<int, MAX> dis;
std::array<bool, MAX> vis;
std::vector<std::pair<ll, int>> g[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> t >> c >> ts >> te;
    for (int u, v, d, i = 1; i <= c; i++) {
        std::cin >> u >> v >> d;
        g[u].emplace_back(d, v);
        g[v].emplace_back(d, u);
    }
    std::memset(&dis, 0x3f, sizeof(dis));
    std::priority_queue<std::pair<ll, int>> q;
    for (q.push({dis[ts] = 0, ts}); !q.empty();) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto [_d, v] : g[u])
            if (dis[v] > dis[u] + _d)
                q.push({-(dis[v] = dis[u] + _d), v});
    }
    std::cout << dis[te] << '\n';
    return 0;
}