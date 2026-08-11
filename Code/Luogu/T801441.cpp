#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int n, N = 1;
int q;
struct ZkwTree {
    ll tre[MAX << 2];
    void Build() {
        std::cin >> n >> q;
        for (; N <= n + 1; N <<= 1)
            ;
        for (int i = N + 1; i <= N + n; i++)
            std::cin >> tre[i];
        for (int i = N - 1; i >= 1; i--)
            tre[i] += tre[i << 1] + tre[i << 1 | 1];
    }
    void Update(int p, ll k) {
        p = N + p;
        tre[p] = k;
        for (p >>= 1; p >= 1; p >>= 1)
            tre[p] = tre[p << 1] + tre[p << 1 | 1];
    }
    ll Query(int l, int r) {
        ll res = 0;
        for (l = N + l - 1, r = N + r + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1)
                res += tre[l ^ 1];
            if (r & 1)
                res += tre[r ^ 1];
        }
        return res;
    }
} zkw;
ll GetAns(int l, int r) {
    ll R = 0;
    int k = std::upper_bound(zkw.tre + N + l, zkw.tre + N + r + 1, R + 1) - zkw.tre - 1;
    while (k - N >= l) {
        ll res = zkw.Query(l, k - N);
        if (R == res)
            break;
        R = res;
        k = std::upper_bound(zkw.tre + N + l, zkw.tre + N + r + 1, R + 1) - zkw.tre - 1;
    }
    return R + 1;
}

int main() {
    // freopen("ex_b.in", "r", stdin);
    // freopen("ex_b.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    zkw.Build();
    while (q--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        switch (op) {
        case 1:
            zkw.Update(x, y);
            break;
        case 2:
            std::cout << GetAns(x, y) << '\n';
            break;
        }
    }
    return 0;
}