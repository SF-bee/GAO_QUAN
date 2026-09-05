#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;
const int MAXL = 46;

int n, q;
struct ZkwTree {
    struct node {
        std::array<ll, MAXL> l;
        int size = 0;
        ll trag = 0;
        bool empty = 1;
        friend node operator+(const node &ls, const node &rs) {
            if (ls.empty) return rs;
            if (rs.empty) return ls;
            node res;
            res.empty = 0;
            int i = 0, j = 0;
            while (i < ls.size && j < rs.size && res.size < MAXL) {
                if (ls.l[i] < rs.l[j]) res.l[res.size++] = rs.l[j++];
                else
                    res.l[res.size++] = ls.l[i++];
            }
            while (i < ls.size && res.size < MAXL)
                res.l[res.size++] = ls.l[i++];
            while (j < rs.size && res.size < MAXL)
                res.l[res.size++] = rs.l[j++];
            for (int i = 0; i + 2 < res.size; i++) {
                if (res.l[i + 1] + res.l[i + 2] > res.l[i]) {
                    res.trag = std::max(res.trag, res.l[i + 1] + res.l[i + 2] + res.l[i]);
                    break;
                }
            }
            return res;
        }
    } tre[MAX << 2];
    int N = 1;
    void build() {
        std::cin >> n >> q;
        for (; N <= n + 1; N <<= 1)
            ;
        for (int a, i = N + 1; i <= N + n; i++) {
            std::cin >> a;
            tre[i].empty = 0;
            tre[i].l[tre[i].size++] = a;
        }
        for (int i = N - 1; i >= 1; i--)
            tre[i] = tre[i << 1] + tre[i << 1 | 1];
    }
    void Update(int p, ll x) {
        p += N;
        tre[p].l[0] = x;
        for (p >>= 1; p; p >>= 1)
            tre[p] = tre[p << 1] + tre[p << 1 | 1];
    }
    node Query(int ql, int qr) {
        node res;
        ql += N - 1, qr += N + 1;
        for (; ql ^ qr ^ 1; ql >>= 1, qr >>= 1) {
            if (~ql & 1) res = res + tre[ql ^ 1];
            if (qr & 1) res = tre[qr ^ 1] + res;
        }
        return res;
    }
} zkw;

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    zkw.build();
    while (q--) {
        int op, x, y;
        std::cin >> op >> x >> y;
        switch (op) {
        case 0:
            zkw.Update(x + 1, y);
            break;
        case 1:
            std::cout << zkw.Query(x + 1, y + 1).trag << '\n';
            break;
        }
    }
    return 0;
}
/*
我们需要维护的信息是最大三角形的周长 c,
那么它其实等价于在区间内选择三个数字x,y,z满足三角不等式
假定x <= y <= z
那么其实只需要 x + y > z,y - x < z
可以直接在左右儿子取，c=max(c_l,c_r)
或者是在左儿子取 x,y，右儿子取 z ，反之。
注意到，y - x 是一定小于 z 的，所以只需要维护x + y的最大值，然后去查右儿子最大的小于x + y的数字
又或者左儿子取 x,右儿子取y,z
那么就有y + z一定是大于 x 的，所以只需要维护y + z的最大值，然后取右儿子查最大的小于 y - z 的数字
不对不对，我怎么知道这个最大的可以令左右儿子取到？
*/