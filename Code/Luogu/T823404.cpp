#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int n, q;
std::vector<std::pair<int, int>> g[MAX];
int fe[MAX], fa[MAX], son[MAX], siz[MAX], dep[MAX];
int tim, top[MAX], dfn[MAX], idfn[MAX];

struct SegmentTree {
    // sum存从根到某个点路径上的逆行道数量
    struct Node {
        int sum;
        bool tag = 0;
    } node[4 * MAX];
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
    void PushUp(int p) { node[p].sum = node[ls(p)].sum + node[rs(p)].sum; }
    void Apply(int p, int l, int r) {
        node[p].sum = r - l + 1 - node[p].sum;
        node[p].tag ^= 1;
    }
    void PushDown(int p, int l, int r) {
        if (!node[p].tag) return;
        int mid = (l + r) >> 1;
        Apply(ls(p), l, mid);
        Apply(rs(p), mid + 1, r);
        node[p].tag = 0;
    }
    void Build(int p, int l, int r) {
        if (l == r) {
            node[p].sum = fe[idfn[l]];
            return;
        }
        int mid = (l + r) >> 1;
        Build(ls(p), l, mid);
        Build(rs(p), mid + 1, r);
        PushUp(p);
    }
    void Update(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            Apply(p, l, r);
            return;
        }
        PushDown(p, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) Update(ls(p), l, mid, ql, qr);
        if (qr > mid) Update(rs(p), mid + 1, r, ql, qr);
        PushUp(p);
        return;
    }
    int Query(int p, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) return node[p].sum;
        PushDown(p, l, r);
        int mid = (l + r) >> 1;
        return Query(ls(p), l, mid, ql, qr) + Query(rs(p), mid + 1, r, ql, qr);
    }
} seg;

void dfs1(int u, int f) {
    siz[u] = 1;
    dep[u] = dep[f] + 1;
    for (auto [v, fg] : g[u])
        if (v != f) {
            dfs1(v, u);
            fe[v] = fg ^ 1;
            fa[v] = u;
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) son[u] = v;
        }
}
void dfs2(int u, int t) {
    dfn[u] = ++tim;
    idfn[dfn[u]] = u;
    top[u] = t;
    if (son[u]) dfs2(son[u], t);
    for (auto [v, fg] : g[u])
        if (v != fa[u] && v != son[u]) dfs2(v, v);
}
void Update(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        seg.Update(1, 1, n, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v]) std::swap(u, v);
    if (dfn[u] < dfn[v]) seg.Update(1, 1, n, dfn[u] + 1, dfn[v]);
}
int Query(int u, int v) {
    auto getLca = [](int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] > dep[top[y]]) x = fa[top[x]];
            else
                y = fa[top[y]];
        }
        return dep[x] < dep[y] ? x : y;
    };
    auto getSum = [](int x, int anc) {
        int sum = 0;
        while (top[x] != top[anc]) {
            sum += seg.Query(1, 1, n, dfn[top[x]], dfn[x]);
            x = fa[top[x]];
        }
        if (x != anc) sum += seg.Query(1, 1, n, dfn[anc] + 1, dfn[x]);
        return sum;
    };
    int p = getLca(u, v);
    int su = getSum(u, p);
    int sv = getSum(v, p);
    return su + (dep[v] - dep[p]) - sv;
}

int main() {
#if !ONLINE_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> q;
    for (int u, v, i = 1; i < n; i++) {
        std::cin >> u >> v;
        g[u].emplace_back(v, 0);
        g[v].emplace_back(u, 1);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    seg.Build(1, 1, n);

    while (q--) {
        int op, u, v;
        ll ans = 0;
        std::cin >> op >> u;
        switch (op) {
        case 1:
            std::cin >> v;
            Update(u, v);
            break;

        case 2:
            for (int i = 1; i <= n; i++) {
                if (i == u) continue;
                ans += Query(u, i);
            }
            std::cout << ans << '\n';
            break;
        }
    }
    return 0;
}
/*
树剖板子？？？
打部分分走人
考虑已知 u,v 的 lca fa和路径长度 l 与儿子到祖先路径上的的反向边数量 c
那么查询 w(u,v) 就是u_c + (l - v_c)
每次修改nlogn，每次查询n^2logn
坏了，不兑！
*/