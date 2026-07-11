/*
给定m个限制
每个限制内容为 c_y - c_x >= w
求 c_n - c_1 的最大值
c_n - c_1 <= d

c_x - c_y <= -w
dis_v <= dis_u + w
dis_v - dis_u <= w

*/
#include <bits/stdc++.h>
using ll = long long;
const int MAX = 3e4 + 5;

int n, m;
std::vector<std::pair<ll, int>> g[MAX];
std::array<ll, MAX> cnt, dis;
std::array<bool, MAX> vis;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int x, y, w, i = 1; i <= m; i++) {
        std::cin >> x >> y >> w;
        g[y].emplace_back(-w, x);
    }

    std::memset(&dis, 0x3f, sizeof(dis));
    std::queue<int> q;
    auto spfa = [&]() {
        for (q.push(1), dis[1] = 0; !q.empty(); q.pop()) {
            int u = q.front();
            vis[u] = 0;
            for (auto [d, v] : g[u])
                if (dis[v] > dis[u] + d) {
                    dis[v] = dis[u] + d;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] > n - 1) return;
                    if (!vis[v]) q.push(v), vis[v] = 1;
                }
        }
    };

    std::cout << dis[n] << '\n';
}