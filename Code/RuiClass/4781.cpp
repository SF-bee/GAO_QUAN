#include <bits/stdc++.h>
using ll = long long;
const int MAX = 505;
const int INF = 0x3f3f3f3f;

int n, m, w;
std::array<int, MAX> dis;
std::vector<std::pair<int, int>> g[MAX];

void solve() {
    dis.fill(INF);
    std::cin >> n >> m >> w;
    for (int i = 0; i <= n; i++)
        g[i].clear();
    for (int u, v, p, i = 1; i <= m; i++) {
        std::cin >> u >> v >> p;
        g[u].push_back({v, p});
        g[v].push_back({u, p});
    }
    for (int u, v, p, i = 1; i <= w; i++) {
        std::cin >> u >> v >> p;
        g[u].push_back({v, -p});
    }
    for (int i = 1; i <= n; i++)
        g[0].push_back({i, 0});

    auto Bmf = [&]() -> bool {
        dis[0] = 0;
        for (int i = 0; i < n; i++) {
            bool flag = 0;
            for (int j = 0; j <= n; j++)
                for (auto [v, d] : g[j]) {
                    if (dis[v] > dis[j] + d) {
                        dis[v] = dis[j] + d;
                        flag = 1;
                    }
                }
            if (!flag)
                return false;
            if (i == n - 1)
                return true;
        }
        return true;
    };
    std::cout << (Bmf() ? "YES\n" : "NO\n");
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}