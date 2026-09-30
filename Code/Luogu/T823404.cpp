#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int n, q;
std::vector<std::pair<int, int>> g[MAX];
ll ssiz[MAX]; // 下标是dfn
int c[MAX], siz[MAX], son[MAX], dep[MAX], fa[MAX];
int tim, dfn[MAX], rnk[MAX], top[MAX];
ll f1;

struct SegmentTree {
    struct Node {
        int c_sum;
        ll csiz_sum;
        bool tag;
    } tre[MAX << 2];
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
    bool in(int l, int r, int ql, int qr) { return l <= ql && qr <= r; }
    bool out(int l, int r, int ql, int qr) { return qr < l || ql > r; }
    void PushUp(int p) {
        tre[p].c_sum = tre[ls(p)].c_sum + tre[rs(p)].c_sum;
        tre[p].csiz_sum = tre[ls(p)].csiz_sum + tre[rs(p)].csiz_sum;
    }
    void Apply(int p, int l, int r) {
        tre[p].c_sum = (r - l + 1) - tre[p].c_sum;
        tre[p].csiz_sum = (ssiz[r] - ssiz[l - 1]) - tre[p].csiz_sum;
        tre[p].tag ^= 1;
    }
    void Build(int p, int l, int r) {
        if (l == r) {
            tre[l].c_sum = c[rnk[l]];
            tre[l].csiz_sum = c[rnk[l]] * siz[l];
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
        if (out(l, q, ql, qr)) return;
        int mid = (l + r) >> 1;
        Update(ls(p), l, mid, ql, qr);
        Update(rs(p), mid + 1, r, ql, qr);
    }
    int Queryc(int p, int l, int r, int ql, int qr) {
        if (in(l, r, ql, qr)) return tre[p].c_sum;
        if (out(l, r, ql, qr)) return 0;
        int mid = (l + r) >> 1;
        return Queryc(ls(p), l, mid, ql, qr) + Queryc(rs(p), mid + 1, r, ql, qr);
    }
    ll Querysiz(int p, int l, int r, int ql, int qr) {
        if (in(l, r, ql, qr)) return tre[p].csiz_sum;
        if (out(l, r, ql, qr)) return 0;
        int mid = (l + r) >> 1;
        return Querysiz(ls(p), l, mid, ql, qr) + Querysiz(rs(p), mid + 1, r, ql, qr);
    }
} seg;

void dfs1(int u, int f) {
    siz[u] = 1;
    dep[u] = dep[f] + 1;
    、 for (auto [v, fg] : g[u]) if (v != f) {
        dfs1(v, u);
        siz[u] += siz[v];
        c[v] = 1 - fg;
        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}
void dfs2(int u, int ftop) {
    top[u] = ftop, dfn[u] = ++tim, siz[tim] = 1, rnk[u] = tim;
    if (son[u]) dfs2(son[u], ftop), siz[tim] += siz[rnk[son[u]]];
    for (auto [v, fg] : g[u])
        if (v != fa[u] && v != son[u]) dfs2(v, v), siz[tim] += siz[rnk[v]];
}
void Update(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        seg.Update(1, 1, n, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    seg.Update(1, 1, n, dfn[v] + 1, dfn[u]);
    f1 = siz[n] - siz[1] - seg.Querysiz(1, 1, n, 2, n);
}
int Query(int u) {
    int tot = 0;
    while (top[u] != 1)
        tot += seg.Queryc(1, 1, n, dfn[top[u]], dfn[u]);
    if (u != 1) tot += seg.Queryc(1, 1, n, 2, dfn[u]);
    return tot;
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
    for (int i = 1; i <= n; i++)
        siz[i] += siz[i - 1];
    seg.Build(1, 1, n);
    f1 = siz[n] - siz[1] - seg.Querysiz(1, 1, n, 2, n);
    while (q--) {
        int op, u, v;
        std::cin >> op >> u;
        switch (op) {
        case 1:
            std::cin >> v;
            Update(u, v);
            break;

        default:
            std::cout << f1 + Query(u) - siz[u] << '\n';
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
     = f[1] + n*(路径上c[i]=1的数量) - /sum siz[u]
df[u] = n*(路径上c[i]=1的数量) - /sum siz[u]
前一项是区间求和，后一项是定值
*/