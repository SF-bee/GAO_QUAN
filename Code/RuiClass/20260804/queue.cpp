#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;
const int MAXN = MAX << 5;

struct ChairmanTree {
    struct Node {
        int ls, rs, sum;
    } tre[MAXN];
    int tot = 0;

    int newNode(int l = 0, int r = 0, int s = 0) {
        tre[++tot] = {l, r, s};
        return tot;
    }
    int clone(int node) {
        tre[++tot] = tre[node];
        return tot;
    }
    int build(int l, int r) {
        int node = newNode();
        if (l == r)
            return node;
        int mid = (l + r) >> 1;
        tre[node].ls = build(l, mid);
        tre[node].rs = build(mid + 1, r);
        return node;
    }
    int Update(int pre, int l, int r, int pos, int val) {
        int now = clone(pre);
        if (l == r) {
            tre[now].sum += val;
            return now;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            tre[now].ls = Update(tre[now].ls, l, mid, pos, val);
        else
            tre[now].rs = Update(tre[now].rs, mid + 1, r, pos, val);
        tre[now].sum = tre[tre[now].ls].sum + tre[tre[now].rs].sum;
        return now;
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (!node)
            return 0;
        if (ql <= l && r <= qr)
            return tre[node].sum;
        int mid = (l + r) >> 1;
        int res = 0;
        if (ql <= mid)
            res += query(tre[node].ls, l, mid, ql, qr);
        if (qr > mid)
            res += query(tre[node].rs, mid + 1, r, ql, qr);
        return res;
    }
} ct;
int n;
int roots[MAX], top[MAX];

int main() {
    // freopen("queue.in", "r", stdin);
    // freopen("queue.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    int last = 0, Lastans = 0;
    std::cin >> n;
    roots[0] = ct.build(1, n);
    for (int i = 1; i <= n; i++) {
        int op, x;
        std::cin >> op >> x;
        op = (Lastans * 229 + op * 239) % 3 + 1;
        x = (Lastans * 251 + x * 269) % 100000;
        switch (op) {
        case 1:
            roots[last + 1] = ct.Update(roots[last], 1, n, (top[last + 1] = top[last] + 1), x);
            last++;
            break;
        case 2:
            roots[last + 1] = ct.clone(roots[last - x]);
            top[last + 1] = top[last - x];
            last++;
            break;
        case 3:
            Lastans = ct.query(roots[last], 1, n, x, x);
            std::cout << Lastans << '\n';
            break;
        }
    }
    return 0;
}
/*
主席树第 i 个版本维护第 i 次操作的结果
*/