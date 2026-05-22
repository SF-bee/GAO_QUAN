#include <bits/stdc++.h>
using ll = long long;
const int N = 2e2 + 5;
const int MAX = 2e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
using Row = std::array<ll, N>;

int n, m, cnt;
std::array<Row, N> g, f;
std::array<ll, MAX> ans;
std::vector<std::tuple<int, int, int>> q;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> g[i][j], f[i][j] = g[i][j];
    for (int c, x, y, i = 1; i <= m; i++) {
        std::cin >> c >> x >> y;
        q.emplace_back(c, x, y);
        if (c == 1)
            f[x][y] = INF;
    }

    std::reverse(q.begin(), q.end());
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
    for (auto [c, x, y] : q) {
        switch (c) {
        case 1:
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    f[i][j] = std::min(f[i][j], f[i][x] + g[x][y] + f[y][j]);
                }
            }
            break;
        case 2:
            ans[++cnt] = f[x][y] >= INF / 2 ? -1 : f[x][y];
            break;
        }
    }

    while (cnt)
        std::cout << ans[cnt--] << '\n';
    return 0;
}