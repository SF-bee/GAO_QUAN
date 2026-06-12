#include <bits/stdc++.h>
const int N = 3e2 + 5;
const int INF = 0x3f3f3f3f;

int n, m, t;
using ep = std::array<int, N>;
using sp = std::array<ep, N>;
sp g;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> t;
    memset(&g, 0x3f, sizeof(g));
    for (int u, v, d, i = 1; i <= m; i++) {
        std::cin >> u >> v >> d;
        g[u][v] = d;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = std::min(g[i][j], std::max(g[i][k], g[k][j]));
            }
        }
    }

    while (t--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << (g[a][b] != INF ? g[a][b] : -1) << '\n';
    }
    return 0;
}