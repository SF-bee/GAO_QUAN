#include <bits/stdc++.h>
#define int long long
const int MAX = 2e3 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
std::array<int, MAX> dis;
std::vector<std::pair<int, int>> g[MAX];

void solve() {
    dis.fill(INF);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int u, v, w, i = 1; i <= m; i++) {
        std::cin >> u >> v >> w;
        if (w >= 0) {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        } else
            g[u].push_back({v, w});
    }

    auto bmf = [&]() {
        dis[1] = 0;
        for (int i = 1; i <= n; i++) {
            bool flag = 0;
            for (int j = 1; j <= n; j++)
                for (auto [v, w] : g[j]) {
                    if (dis[j] != INF && dis[v] > dis[j] + w) {
                        dis[v] = dis[j] + w;
                        flag = 1;
                    }
                }
            if (!flag)
                return 0;
            else if (i == n)
                return 1;
        }
        return 0;
    };
    if (bmf())
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

signed main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int T;
    std::cin >> T;
    while (T--)
        solve();
    return 0;
}