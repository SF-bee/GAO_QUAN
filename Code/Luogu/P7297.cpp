#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e4 + 5;
const int K = 55;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, k;
// to_k 表示 k 可以到达什么点，fr_k 表示 k 可以由什么点到达
std::vector<int> ty[K], to[K];
std::vector<std::tuple<int, int, int>> g[K][MAX];
bool vis[K][MAX];
ll dis[K][MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    for (int t, i = 1; i <= n; i++)
        std::cin >> t, ty[t].push_back(i);
    for (int i = 1; i <= k; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 1; j <= k; j++) {
            if (s[j - 1] == '1') to[i].push_back(j);
        }
    }

    for (int tk = 1; tk <= k; tk++)
        for (int i = 2; i <= n; i++) {
            g[tk][i - 1].emplace_back(1, tk, i);
            g[tk][i].emplace_back(1, tk, i - 1);
        }

    for (int tk = 1; tk <= k; tk++) {
        for (auto u : ty[tk])
            g[0][u].emplace_back(0, tk, u);
        for (auto v : to[tk])
            for (auto u : ty[v])
                g[tk][u].emplace_back(0, 0, u);
    }

    std::priority_queue<std::tuple<ll, int, int>> que;
    std::memset(dis, 0x3f, sizeof(dis));
    for (que.push({0, 0, 1}), dis[0][1] = 0; !que.empty();) {
        auto [_, uk, u] = que.top();
        que.pop();
        if (vis[uk][u]) continue;
        vis[uk][u] = 1;
        for (auto [d, vk, v] : g[uk][u])
            if (dis[uk][u] + d < dis[vk][v]) que.push({-(dis[vk][v] = dis[uk][u] + d), vk, v});
    }
    std::cout << (dis[0][n] == INF ? -1 : dis[0][n]) << '\n';
    return 0;
}
/*
一个直观想法：直接建出 n^2 条边，跑朴素dij，复杂度 n^2
实际上应该跑不满？
注意到一个关键：每个点是有类型的，类型之间并不是一定可以连通的
可以分层图？按照种类进行分层
接着观察权值的式子，|i - j| 是一条链，所以每个层内其实可以只建一条链的边，这样的图是等价的
那不同层之间呢？
脑子里突然有了个很科幻的场景，就是每个人都有k个平行时空的自己
但是每个人只可以去单向到某个（满足可以发送到的那个种类）
也只能单向从某个平行时空回到现实（满足可以接受到的那个种类）
*/