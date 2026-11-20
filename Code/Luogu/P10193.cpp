#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e4 + 5;

int n, m, c, r, k;
std::vector<std::pair<ll, int>> g[MAX];

// 记录每一个点的覆盖情况
std::unordered_set<int> vis[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> c >> r >> k;
    for (int u, v, w, i = 1; i <= m; i++)
        std::cin >> u >> v >> w, g[u].emplace_back(w, v), g[v].emplace_back(w, u);

    std::priority_queue<std::tuple<ll, int, int>> q;
    for (int i = 1; i <= c; i++)
        q.push({0, i, i});
    while (!q.empty()) {
        auto [dist, u, pre] = q.top();
        q.pop();
        if (vis[u].size() > k || vis[u].count(pre)) continue;
        vis[u].insert(pre);
        for (auto [d, v] : g[u]) {
            if (d - dist > r || vis[v].size() > k || vis[v].count(pre)) continue;
            q.push({-(d - dist), v, pre});
        }
    }

    std::vector<int> ans;
    for (int i = c + 1; i <= n; i++)
        if (vis[i].size() >= k) ans.push_back(i);
    std::cout << ans.size() << '\n';
    for (auto u : ans)
        std::cout << u << '\n';
    return 0;
}
/*
给定一张图和若干个关键点，每个关键点可以覆盖距离不超过R的点
求所有被覆盖至少 k 次的节点

看起来是某种覆盖问题？我们是可以处理所有特殊点的覆盖集合的
看这个 k，说明算法一定是一个和 k 相关的复杂度
而且这道题看起来是某种多源最短路？
实际上我们可以建立一个超级源点，连向特殊点，这样就可以从所有的特殊点一起出发了！
！？多源最短路！？

考虑需要什么信息？需要最短路，需要被覆盖点集。
每次松弛就松弛所有距离小于 r 的点
然后已经被覆盖 k 次的不用管，说明这个点是答案
！注意！最短路要记录的是来自于哪个点的最短路，否则可能导致互相覆盖
*/