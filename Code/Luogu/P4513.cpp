#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;
const int MAXN = MAX << 2;

int n, m;
ll a[MAX];
struct SegmentTree {
    struct Node {
        int ls, rs;
        ll sum, maxv, maxl, maxr;
        Node() : ls(0), rs(0), sum(0), maxv(0), maxl(0), maxr(0) {};
    } tr[MAXN];
    int tot = 0;
    int NewNode() {
        tot++;
        tr[tot].ls = tr[tot].rs = tr[tot].sum = 0;
        return tot;
    }
    bool in(int l, int r, int ql, int qr) { return ql <= l && r <= qr; }
    void PushUp(Node &p, Node &ls, Node &rs) {
        p.sum = ls.sum + rs.sum;
        p.maxv = std::max({ls.maxv, rs.maxv, ls.maxr + rs.maxl});
        p.maxl = std::max(ls.maxl, ls.sum + rs.maxl);
        p.maxr = std::max(rs.maxr, rs.sum + ls.maxr);
    }
    int build(int l, int r) {
        int node = NewNode();
        if (l == r) {
            tr[node].maxl = tr[node].maxr = tr[node].maxv = tr[node].sum = a[l];
            return node;
        }
        int mid = (l + r) >> 1;
        tr[node].ls = build(l, mid);
        tr[node].rs = build(mid + 1, r);
        PushUp(tr[node], tr[tr[node].ls], tr[tr[node].rs]);
        return node;
    }
    void Update(int p, int l, int r, int qp, ll k) {
        if (l == r) {
            tr[p].maxl = tr[p].maxr = tr[p].maxv = tr[p].sum = k;
            return;
        }
        int mid = (l + r) >> 1;
        if (qp <= mid)
            Update(tr[p].ls, l, mid, qp, k);
        else
            Update(tr[p].rs, mid + 1, r, qp, k);
        PushUp(tr[p], tr[tr[p].ls], tr[tr[p].rs]);
        return;
    }
    Node Query(int p, int l, int r, int ql, int qr) {
        if (in(l, r, ql, qr))
            return tr[p];
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return Query(tr[p].ls, l, mid, ql, qr);
        else if (ql > mid)
            return Query(tr[p].rs, mid + 1, r, ql, qr);
        else {
            Node ls = Query(tr[p].ls, l, mid, ql, qr);
            Node rs = Query(tr[p].rs, mid + 1, r, ql, qr);
            Node res;
            PushUp(res, ls, rs);
            return res;
        }
    }
} st;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    int root = st.build(1, n);
    for (int i = 1; i <= m; i++) {
        int k, a, b;
        std::cin >> k >> a >> b;
        switch (k) {
        case 1:
            if (a > b)
                std::swap(a, b);
            std::cout << st.Query(root, 1, n, a, b).maxv << '\n';
            break;
        case 2:
            st.Update(root, 1, n, a, b);
            break;
        }
    }
    return 0;
}