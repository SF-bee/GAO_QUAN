#include <bits/stdc++.h>
const int N = 1e2 + 5;
const int INF = 0x3f3f3f3f;

int n, m;
using SP = std::array<int, N>;
using EP = std::array<SP, N>;
EP f, g;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    auto solve = [&]() {
        std::memset(&f, 0x3f, sizeof(g));
        std::memset(&g, 0x3f, sizeof(g));
        for (int u, v, d, i = 1; i <= m; i++) {
            std::cin >> u >> v >> d;
            f[u][v] = f[v][u] = g[u][v] = g[v][u] = std::min(g[u][v], d);
        }

        int ans = INF;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i < k; i++)
                for (int j = i + 1; j < k; j++) {
                    if (g[i][j] != INF && f[i][k] != INF && f[k][j] != INF)
                        ans = std::min(ans, g[i][j] + f[i][k] + f[k][j]);
                }
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
        }

        if (ans == INF)
            std::cout << "No solution.\n";
        else
            std::cout << ans << '\n';
        return;
    };
    while (std::cin >> n >> m) {
        solve();
    }
    return 0;
}