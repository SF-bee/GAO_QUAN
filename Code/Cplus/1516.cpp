/*
考虑一条路径：
必须保证人品值小于路径上所有的边权的最小值，那么这段路径最大的人品就是这段路径的最小边权。
问题转化为最长路
*/
#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e3 + 5;

int n, m, x, y;
std::array<ll, MAX> dis;
std::array<bool, MAX> vis;
std::vector<std::pair<ll, int>> g[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    {
        int u, v, d;
        while (std::cin >> u >> v >> d)
            g[u].emplace_back(d, v);
    }
    dis.fill(0);
    std::priority_queue<std::pair<ll, int>> q;
    for (q.push({dis[1] = 0x3f3f3f3f, 1}); !q.empty();) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &[e, v] : g[u])
            if (dis[v] < std::min(dis[u], e))
                q.push({dis[v] = std::min(dis[u], e), v});
    }
    for (int i = 2; i <= n; i++)
        std::cout << dis[i] << '\n';
    return 0;
}