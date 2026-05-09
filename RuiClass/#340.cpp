#include <bits/stdc++.h>
using ll = long long;
const int MAX = 100;

int a, b, x, m, y, n;
ll lov;
ll map[MAX][MAX], dis[MAX][MAX];
bool vis[MAX][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int abc = 0;
    std::cin >> a >> b;
    std::cin >> x >> m >> y >> n;
    std::cin >> lov;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            std::cin >> map[i][j];

    int dx[5] = {1, 0, -1, 0, -1};
    int dy[5] = {0, 1, 0, -1, -1};
    auto in = [&](int x, int y) { return 1 <= x && x <= a && 1 <= y && y <= b; };
    std::priority_queue<std::tuple<ll, int, int>> que;
    std::memset(dis, 0x3f, sizeof(dis));
    for (que.push({-(dis[x][m] = 0), x, m}); !que.empty();) {
        auto [d, nx, ny] = que.top();
        que.pop();
        if (vis[nx][ny])
            continue;
        vis[nx][ny] = 1;
        //! 点权化边权
        for (int i = 0, tx = nx + dx[i], ty = ny + dy[i]; i < 4; tx = nx + dx[++i], ty = ny + dy[i])
            if (in(tx, ty) && dis[tx][ty] > dis[nx][ny] + map[tx][ty])
                que.push({-(dis[tx][ty] = dis[nx][ny] + map[tx][ty]), tx, ty});
    }
    if (dis[y][n] >= lov)
        std::cout << lov << '\n';
    else
        std::cout << lov - dis[y][n] << '\n';
    return 0;
}