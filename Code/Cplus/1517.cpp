#include <bits/stdc++.h>
using ll = long long;
const int N = 5e2 + 5;
const int P = 8e2 + 5;

int n, p, c;
std::array<int, N> pos;
std::vector<std::pair<ll, int>> g[P];
using PARK = std::array<ll, P>;
using DIS = std::array<PARK, P>;
DIS dis;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> p >> c;
    for (int i = 1; i <= n; i++)
        std::cin >> pos[i];
    for (int u, v, d, i = 1; i <= c; i++) {
        std::cin >> u >> v >> d;
        g[u].emplace_back(d, v);
        g[v].emplace_back(d, u);
    }

    std::memset(&dis, 0x3f, sizeof(dis));
    auto dij = [&](int st) {
        std::priority_queue<std::pair<ll, int>> q;
        std::vector<bool> vis(p + 1, 0);
        auto &dist = dis[st];
        for (q.push({dist[st] = 0, st}); !q.empty();) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [d, v] : g[u])
                if (dist[v] > dist[u] + d)
                    q.push({-(dist[v] = dist[u] + d), v});
        }
    };
    for (int i = 1; i <= p; i++)
        dij(i);
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= p; i++) {
        ll sum = 0;
        for (int j = 1; j <= n; j++)
            sum += dis[i][pos[j]];
        ans = std::min(ans, sum);
    }
    std::cout << ans << '\n';
    return 0;
}