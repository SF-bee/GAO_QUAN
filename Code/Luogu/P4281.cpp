#include <bits/stdc++.h>
const int MAX = 5e5 + 5;

int n, m;
std::vector<int> g[MAX];
int fa[MAX], son[MAX], siz[MAX], top[MAX], dep[MAX];
int tim;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int u, v, i = 1; i < n; i++)
        std::cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

    auto dfs1 = [&](auto &self, int u, int f) -> void {
        fa[u] = f;
        siz[u] = 1;
        dep[u] = dep[f] + 1;
        for (auto v : g[u])
            if (v != f) {
                self(self, v, u);
                siz[u] += siz[v];
                if (siz[v] > siz[son[u]]) son[u] = v;
            }
    };
    auto dfs2 = [&](auto &self, int u, int ftop) -> void {
        top[u] = ftop;
        if (son[u]) self(self, son[u], ftop);
        for (auto v : g[u])
            if (v != fa[u] && v != son[u]) self(self, v, v);
    };
    auto LCA = [&](int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
            u = fa[top[u]];
        }
        return dep[u] > dep[v] ? v : u;
    };
    dfs1(dfs1, 1, 1);
    dfs2(dfs2, 1, 1);
    while (m--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        int a = LCA(u, v), b = LCA(u, w), c = LCA(v, w);
        int ap = 0;
        ap = (dep[a] > dep[b] ? a : b);
        ap = (dep[ap] > dep[c] ? ap : c);
        std::cout << ap << ' ' << dep[u] + dep[v] + dep[w] - dep[a] - dep[b] - dep[c] << '\n';
    }
    return 0;
}