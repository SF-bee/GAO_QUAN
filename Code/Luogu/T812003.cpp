#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m;
int x[MAX], to[MAX];
struct SegTree {
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
    struct Node {
        int mina, tag;
    } tre[MAX << 2];
    void PushUp(int p) { tre[p] = {std::min(tre[ls(p)].mina, tre[rs(p)].mina), 0}; }
    void Apply(int p, int k) {
        tre[p].mina += k;
        tre[p].tag += k;
    }
    void PushDown(int p) {
        if (!tre[p].tag) return;
        Apply(ls(p), tre[p].tag);
        Apply(rs(p), tre[p].tag);
        tre[p].tag = 0;
    }
    void Update(int p, int l, int r, int ql, int qr, int k) {
        if (ql <= l && r <= qr) {
            Apply(p, k);
            return;
        }
        PushDown(p);
        int mid = (l + r) >> 1;
        if (ql <= mid) Update(ls(p), l, mid, ql, qr, k);
        if (qr > mid) Update(rs(p), mid + 1, r, ql, qr, k);
        PushUp(p);
    }
    int Query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tre[p].mina;
        if (l > qr || r < ql) return INF;
        int mid = (l + r) >> 1;
        PushDown(p);
        return std::min(Query(ls(p), l, mid, ql, qr), Query(rs(p), mid + 1, r, ql, qr));
    }
#undef ls
#undef rs
} sgt;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> x[i];
    for (int h, i = 1; i <= n; i++) {
        std::cin >> h;
        to[i] = std::lower_bound(x + i + 1, x + n + 1, x[i] + h) - x - 1;
        if (to[i] != i) sgt.Update(1, 1, n, i + 1, to[i], 1);
    }
    while (m--) {
        int op, i, y;
        std::cin >> op;
        switch (op) {
        case 1:
            std::cin >> i >> y;
            if (to[i] != i) sgt.Update(1, 1, n, i + 1, to[i], -1);
            to[i] = std::lower_bound(x + i + 1, x + n + 1, x[i] + y) - x - 1;
            if (to[i] != i) sgt.Update(1, 1, n, i + 1, to[i], 1);
            break;
        case 2:
            std::cin >> i;
            if (i <= to[1]) std::cout << i - 1 << '\n';
            else
                std::cout << sgt.Query(1, 1, n, to[1] + 1, i) << '\n';
            break;
        }
    }
    return 0;
}
/*
考虑维护每个牌被覆盖的次数，那么查询等价于在在2～i-1中查询被覆盖次数最小的牌
*/