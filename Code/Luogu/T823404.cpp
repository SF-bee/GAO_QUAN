#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int n, q;
std::vector<std::pair<int, int>> g[MAX];
int c[MAX], siz[MAX], son[MAX], dep[MAX], fa[MAX];
int tim, dfn[MAX], rnk[MAX], top[MAX];
ll f1;

struct SegmentTree {
    struct Node {
        int c_sum;
        ll siz, csiz_sum;
        bool tag;
    } tre[MAX << 2];
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
    bool in(int l, int r, int ql, int qr) { return ql <= l && r <= qr; }
    bool out(int l, int r, int ql, int qr) { return qr < l || ql > r; }
    void PushUp(int p) {
        tre[p].c_sum = tre[ls(p)].c_sum + tre[rs(p)].c_sum;
        tre[p].siz = tre[ls(p)].siz + tre[rs(p)].siz;
        tre[p].csiz_sum = tre[ls(p)].csiz_sum + tre[rs(p)].csiz_sum;
    }
    void Apply(int p, int l, int r) {
        tre[p].c_sum = (r - l + 1) - tre[p].c_sum;
        tre[p].csiz_sum = tre[p].siz - tre[p].csiz_sum;
        tre[p].tag ^= 1;
    }
    void PushDwon(int p, int l, int r) {
        if (!tre[p].tag) return;
        int mid = (l + r) >> 1;
        Apply(ls(p), l, mid);
        Apply(rs(p), mid + 1, r);
        tre[p].tag = 0;
        PushUp(p);
    }
    void Build(int p, int l, int r) {
        if (l == r) {
            tre[p].c_sum = c[rnk[l]];
            tre[p].siz = siz[rnk[l]];
            tre[p].csiz_sum = 1ll * c[rnk[l]] * siz[rnk[l]];
            return;
        }
        int mid = (l + r) >> 1;
        Build(ls(p), l, mid);
        Build(rs(p), mid + 1, r);
        PushUp(p);
    }
    void Update(int p, int l, int r, int ql, int qr) {
        if (in(l, r, ql, qr)) {
            Apply(p, l, r);
            return;
        }
        if (out(l, r, ql, qr)) return;
        int mid = (l + r) >> 1;
        PushDwon(p, l, r);
        Update(ls(p), l, mid, ql, qr);
        Update(rs(p), mid + 1, r, ql, qr);
        PushUp(p);
    }
    int Queryc(int p, int l, int r, int ql, int qr) {
        if (in(l, r, ql, qr)) return tre[p].c_sum;
        if (out(l, r, ql, qr)) return 0;
        int mid = (l + r) >> 1;
        PushDwon(p, l, r);
        return Queryc(ls(p), l, mid, ql, qr) + Queryc(rs(p), mid + 1, r, ql, qr);
    }
    ll Querysiz(int p, int l, int r, int ql, int qr) {
        if (in(l, r, ql, qr)) return tre[p].siz;
        if (out(l, r, ql, qr)) return 0;
        int mid = (l + r) >> 1;
        PushDwon(p, l, r);
        return Querysiz(ls(p), l, mid, ql, qr) + Querysiz(rs(p), mid + 1, r, ql, qr);
    }
    ll QueryCsiz(int p, int l, int r, int ql, int qr) {
        if (in(l, r, ql, qr)) return tre[p].csiz_sum;
        if (out(l, r, ql, qr)) return 0;
        int mid = (l + r) >> 1;
        PushDwon(p, l, r);
        return QueryCsiz(ls(p), l, mid, ql, qr) + QueryCsiz(rs(p), mid + 1, r, ql, qr);
    }
} seg;

void dfs1(int u, int f) {
    siz[u] = 1;
    dep[u] = dep[f] + 1;
    fa[u] = f;
    for (auto [v, fg] : g[u])
        if (v != f) {
            dfs1(v, u);
            siz[u] += siz[v];
            c[v] = 1 - fg;
            if (siz[son[u]] < siz[v]) son[u] = v;
        }
}
void dfs2(int u, int ftop) {
    top[u] = ftop, dfn[u] = ++tim, rnk[tim] = u;
    if (son[u]) dfs2(son[u], ftop);
    for (auto [v, fg] : g[u])
        if (v != fa[u] && v != son[u]) dfs2(v, v);
}
void Update(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        seg.Update(1, 1, n, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    seg.Update(1, 1, n, dfn[v] + 1, dfn[u]);
    f1 = seg.Querysiz(1, 1, n, 2, n) - seg.QueryCsiz(1, 1, n, 2, n);
}
ll Query(int u) {
    ll totc = 0, totsiz = 0;
    while (top[u] != 1) {
        totc += seg.Queryc(1, 1, n, dfn[top[u]], dfn[u]),
            totsiz += seg.Querysiz(1, 1, n, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if (u != 1) {
        totc += seg.Queryc(1, 1, n, 2, dfn[u]);
        totsiz += seg.Querysiz(1, 1, n, 2, dfn[u]);
    }
    return n * totc - totsiz;
}

int main() {
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
    f1 = seg.Querysiz(1, 1, n, 2, n) - seg.QueryCsiz(1, 1, n, 2, n);
    while (q--) {
        int op, u, v;
        std::cin >> op >> u;
        switch (op) {
        case 1:
            std::cin >> v;
            Update(u, v);
            break;
        case 2:
            std::cout << f1 + Query(u) << '\n';
            break;
        }
    }
    return 0;
}
/*
考虑sub2 没有修改
可以树形dp
设 c[i] 为根到 i的边 是0/否1 是逆行边
设 f[u] 表示 u 的查询答案，考虑如何从父节点转移到这个答案
从父亲顺行1到 u 那么对于 u 子树内答案的贡献不变，但是其他所有点都会贡献1，所以答案 +(n - siz[u])
从父亲逆行0到 u 那么对于 u 子树内答案全部撤销，但是到其他所有点的贡献不变，所以答案 -siz[u]

考虑正解：一眼树剖，但是线段树要维护什么信息？
f[1] = /sum siz[i] - /sum c[i]*siz[i]
前一项是定值，后一项相当于一个区间求和
f[u] = f[fa] + （1-c[i]）(-siz[u]) + c[u](n - siz[u])
     = f[fa] + c[i]siz[u]- siz[u] + c[u]n - c[i]siz[u]
     = f[fa] + c[u]n - siz[u]
     = f[1] + /sum(u /in path) c[u] - /sum(u /in path) siz[u]
df[u] = /sum(u /in path) c[u] - /sum(u /in path) siz[u]
前一项是区间求和，后一项是定值
*/