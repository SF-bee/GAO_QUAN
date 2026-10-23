#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, m, s, t;
ll L, K, c[MAX];
std::pair<int, int> edge[MAX];
std::vector<std::pair<int, ll>> g[MAX];
bool vis[MAX];
ll diss[MAX], dist[MAX];

void dijkstra(int a, ll *dis) {
    std::memset(vis, 0, sizeof(vis));
    std::priority_queue<std::pair<ll, int>> q;
    for (q.push({dis[a] = 0, a}); !q.empty();) {
        auto [_, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, d] : g[u])
            if (dis[v] > dis[u] + d) q.push({-(dis[v] = dis[u] + d), v});
    }
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> s >> t >> L >> K;
    for (int i = 1; i <= n; i++)
        std::cin >> c[i];
    for (int u, v, w, i = 1; i <= m; i++) {
        std::cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        edge[i] = {u, v};
    }

    memset(diss, 0x3f, sizeof(diss));
    memset(dist, 0x3f, sizeof(dist));
    dijkstra(s, diss);
    dijkstra(t, dist);
    if (diss[t] <= K) {
        std::cout << n * (n - 1) / 2 - m << '\n';
        return 0;
    }
    std::vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        arr[i] = (diss[i] += c[i]), dist[i] += c[i];

    std::sort(arr.begin() + 1, arr.begin() + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll cnt = std::upper_bound(arr.begin() + 1, arr.begin() + n + 1, K - L - dist[i]) -
                 arr.begin() - 1;
        ans += cnt;
    }
    for (int i = 1; i <= m; i++) {
        auto [u, v] = edge[i];
        if (diss[u] + dist[v] <= K - L || diss[v] + dist[u] <= K - L) ans--;
    }
    std::cout << ans << '\n';
    return 0;
}
/*
建出以 t 为根的最短路树，对某个点的最短路有影响 w 的一定是满足
w < /sum_{i /in tree} w_i
好像表明，在这棵树上添加一条边一定只会让最短路只降不增的
先吧dis[s] <= K的情况特判掉，答案C(n,2) - m
然后 s 是 t 的一个儿子
新的最短路是什么？
假设选择的点是 u,v
那么新的最短路是
min(dis[s],dis_s[u] + dis_t[v] + L + c[u] + c[v])
就是
(dis_s[u] + c[u]) + (dis_t[v] + c[v]) <= K - L
跑两遍dij就可以得到这些数据了
这个是二分，可以枚举一个点，然后二分另外一个，可以 nlogn 统计
但是要除掉已有点，除掉自环，除掉有序的方案
好复杂
*/