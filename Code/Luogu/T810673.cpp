#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n;
std::vector<int> g[MAX];
int fa[MAX], dep[MAX], siz[MAX], son[MAX], top[MAX];
bool vis[MAX];
int d[MAX];

void init() {
    auto dfs1 = [&](auto &self, int u, int p) -> void {
        siz[u] = 1, fa[u] = p, dep[u] = dep[p] + 1;
        for (auto v : g[u])
            if (v != p) {
                self(self, v, u);
                siz[u] += siz[v];
                if (siz[v] > siz[son[u]]) son[u] = v;
            }
    };
    dfs1(dfs1, 1, 0);
    auto dfs2 = [&](auto &self, int u, int ftop) -> void {
        top[u] = ftop;
        if (son[u]) self(self, son[u], ftop);
        for (auto v : g[u])
            if (v != son[u] && v != fa[u]) self(self, v, v);
    };
    dfs2(dfs2, 1, 1);
}
int Lca(int x, int y, std::queue<std::pair<int, int>> &s) {
    s.push({x, 0}), s.push({y, 0});
    vis[x] = vis[y] = 1;
    if (dep[x] < dep[y]) std::swap(x, y);
    while (dep[x] > dep[y]) {
        x = fa[x];
        s.push({x, 0});
        vis[x] = 1;
    }
    if (fa[x] == fa[y]) return fa[x];
    while (fa[x] != fa[y]) {
        x = fa[x], y = fa[y];
        s.push({x, 0}), s.push({y, 0});
    }
    if (fa[x] == fa[y]) return fa[x];
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    for (int u, v, i = 1; i < n; i++) {
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init();
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            for (int j = i + 1; j <= n; j++) {
                if (g[j].size() == 1) {
                    std::queue<std::pair<int, int>> q;
                    std::memset(vis, 0, sizeof(vis));
                    int lca = Lca(i, j, q), d = dep[i] + dep[j] - 2 * dep[lca], w = 0;
                    while (!q.empty()) {
                        auto [u, ds] = q.front();
                        q.pop();
                        w = std::max(w, ds);
                        for (auto v : g[u])
                            if (!vis[v]) {
                                vis[v] = 1;
                                q.push({v, ds + 1});
                            }
                    }
                    if (w * d > ans) {
                        ans = w * d;
                        cnt = 1;
                    } else if (w * d == ans) {
                        cnt++;
                    }
                }
            }
        }
    }
    std::cout << ans << ' ' << cnt << '\n';
    return 0;
}
/*
求出一个二元组(A,B)，使得w(A,B)*d(A,B)最大
固定二元组(A,B),考虑如何求出w(A,B)

*/