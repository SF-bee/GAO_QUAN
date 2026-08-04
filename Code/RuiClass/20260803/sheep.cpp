#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 5;
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
int rts[MAX], last[MAX];

int bs(int ql, int k) {
    int res = ql;
    for (int l = ql, r = n, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) {
        if (ct.query(rts[mid], 1, n, ql, mid) <= k)
            l = (res = mid) + 1;
        else
            r = mid - 1;
    }
    return res;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    rts[0] = ct.build(1, n);
    for (int a, i = 1; i <= n; i++) {
        std::cin >> a;
        int pre = rts[i - 1];
        int now = ct.Update(pre, 1, n, i, 1);
        if (last[a])
            now = ct.Update(now, 1, n, last[a], -1);
        last[a] = i;
        rts[i] = now;
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int pos = 1; pos <= n; pos++) {
            pos = bs(pos, i);
            cnt++;
        }
        std::cout << cnt - 1 << '\n';
    }
    return 0;
}
/*
主席树第 i 个版本维护
*/