#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

struct DSU {
    int fa[MAX], siz[MAX];
    bool power[MAX];

    void init() {
        for (int i = 1; i < MAX; i++)
            fa[i] = i, siz[i] = 1;
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy)
            return;
        if (siz[fx] < siz[fy])
            std::swap(fx, fy);
        fa[fy] = fa[fx];
        siz[fx] += siz[y];
        power[fx] |= power[fy];
    }
} dsu;
std::pair<int, int> e[MAX];
int n, m, k, T;
int q[MAX], a[MAX];

int main() {
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    dsu.init();
    std::cin >> n >> m >> k >> T;
    for (int p, i = 1; i <= m; i++)
        std::cin >> p, dsu.power[p] = 1;
    for (int i = 1; i <= k; i++)
        std::cin >> e[i].first >> e[i].second;
    std::unordered_set<int> bak;
    for (int i = 1; i <= T; i++)
        std::cin >> q[i], bak.insert(q[i]);

    for (int i = 1; i <= k; i++) {
        if (bak.count(i) == 0) {
            auto [u, v] = e[i];
            dsu.merge(u, v);
        }
    }

    for (int i = T; i >= 1; i--) {
        auto [u, v] = e[q[i]];
        int fu = dsu.find(u), fv = dsu.find(v);
        if (fu != fv && dsu.power[fu] ^ dsu.power[fv]) {
            if (!dsu.power[fu])
                a[i] = dsu.siz[fu];
            else
                a[i] = dsu.siz[fv];
        }
        dsu.merge(u, v);
    }

    for (int i = 1; i <= T; i++)
        std::cout << a[i] << '\n';
    return 0;
}
/*
注意到删边是不好维护的。所以可以离线倒序处理每一次删除
这样删除就变成了连边
可以注意到：断电只发生在两个连通块内一个有发电站一个没有的情况
并查集维护连通块大小和是否有发电站即可
*/