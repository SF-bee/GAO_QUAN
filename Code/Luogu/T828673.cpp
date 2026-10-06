#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int n, q;
std::vector<int> g[MAX];
int tim, dfn[MAX], idx[MAX], siz[MAX], son[MAX], top[MAX], fa[MAX], dep[MAX];

struct SegmentTree {
    struct node {
        ll sum, tag;
    } tre[MAX << 2];
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
    bool in(int l, int r, int ql, int qr) { return ql <= l && r <= qr; }
    bool out(int l, int r, int ql, int qr) { return qr < l || ql > r; }
    void Update(int p, int l, int r, int ql, int qr, ll k) {
        if (in(l, r, ql, qr)) {
            tre[p].tag += k;
            tre[p].sum += (r - l + 1) * k;
            return;
        }
        if (out(l, r, ql, qr)) return;
        int mid = l + r;
        Update(ls(p), l, mid, ql, qr, k), Update(rs(p), mid + 1, ql, qr, k);
        tre[p].sum += tre[ls(p)].sum + tre[rs(p)].sum + tre[p].tag * (r - l + 1);
    }
    ll Query(int p, int l, int r, int ql, int qr) {
        if (in(l, r, ql, qr)) return tre[p].sum;
        if (out(l, r, ql, qr)) return 0;
        int mid = (l + r) >> 1;
        ll res = tag[p] * (min(r, qr) - max(l, ql) + 1) + Query(ls(p), );
    }
}

void dfs1(int u) {
    siz[u] = 1;
    for (auto v : g[u]) {
        dfs1(v), siz[u] += siz[v], dep[v] = dep[u] + 1;
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int ftop) {
    dfn[u] = ++tim, idx[dfn[u]] = u;
    if (son[u]) dfs2(son[u], ftop);
    for (auto v : g[u])
        if (v != son[u]) dfs2(v, v);
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> q;
    for (int f, i = 1; i < n; i++) {
        std::cin >> f;
        g[f].push_back(i + 1);
        fa[i + 1] = f;
    }

    return 0;
}