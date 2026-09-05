#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int T, n, c;
ll dis[21][MAX];
bool vis[21][MAX];
std::vector<std::tuple<int, int, ll>> g[21][MAX];

void init() {
    for (int i = 0; i < 21; i++)
        for (int j = 1; j <= n; j++)
            g[i][j].clear();
}
void solve() {
    std::cin >> n >> c;
    int max_w = 0;
    for (int u, v, w, i = 1; i < n; i++) {
        std::cin >> u >> v >> w;
        g[0][u].push_back({0, v, w});
        g[0][v].push_back({0, u, w});
        max_w = std::max(max_w, w);
    }
    int K = 0, N = 1;
    for (; N <= max_w; N <<= 1, K++)
        ;
    for (int k = 1; k <= K; k++)
        for (int i = 1; i <= n; i++)
            for (auto [f, to, d] : g[k - 1][i])
                g[k][i].push_back({f + 1, to, (d + 1) / 2});
    for (int im, i = 1; i <= n; i++) {
        std::cin >> im;
        if (im) {
            for (int j = 1; j <= K; j++)
                g[j - 1][i].push_back({j, i, c});
        }
    }
    auto dij = [&](int s, int t) {
        std::memset(dis, 0x3f, sizeof(dis));
        std::memset(vis, 0, sizeof(vis));
        std::priority_queue<std::tuple<ll, int, int>> q;
        for (q.push({dis[0][s] = 0, 0, s}); !q.empty();) {
            auto [dd, fl, u] = q.top();
            q.pop();
            if (vis[fl][u]) continue;
            vis[fl][u] = 1;
            for (auto [f, v, d] : g[fl][u])
                if (dis[f][v] > dis[fl][u] + d) q.push({-(dis[f][v] = dis[fl][u] + d), f, v});
        }
        ll ans = INF;
        for (int k = 0; k <= K; k++)
            ans = std::min(ans, dis[k][t]);
        return ans;
    };
    int q;
    std::cin >> q;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << dij(u, v) << '\n';
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> T;
    while (T--) {
        solve();
        init();
    }
    return 0;
}