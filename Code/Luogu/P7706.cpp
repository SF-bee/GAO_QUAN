#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, m, N = 1;
struct ZKWTree {
    struct Node {
        ll mA, mB, mld = -INF, mrd = -INF, w = -INF;
        bool empty = 1;
        friend Node operator+(const Node &ls, const Node &rs) {
            if (ls.empty)
                return rs;
            if (rs.empty)
                return ls;
            Node res;
            res.empty = 0;
            res.mA = std::max(ls.mA, rs.mA);
            res.mB = std::min(ls.mB, rs.mB);
            res.mld = std::max({ls.mld, rs.mld, ls.mA - rs.mB});
            res.mrd = std::max({ls.mrd, rs.mrd, rs.mA - ls.mB});
            res.w = std::max({ls.w, rs.w, ls.mld + rs.mA, ls.mA + rs.mrd});
            return res;
        }
    } tre[MAX << 2];
    void build() {
        std::cin >> n >> m;
        for (; N <= n + 1; N <<= 1)
            ;
        for (int i = N + 1; i <= N + n; i++)
            std::cin >> tre[i].mA;
        for (int i = N + 1; i <= N + n; i++)
            std::cin >> tre[i].mB, tre[i].empty = 0;
        for (int i = N - 1; i >= 1; i--)
            tre[i] = tre[i << 1] + tre[i << 1 | 1];
    }
    void UpdateA(int p, ll A) {
        p += N;
        tre[p].mA = A;
        for (p >>= 1; p; p >>= 1)
            tre[p] = tre[p << 1] + tre[p << 1 | 1];
    }
    void UpdateB(int p, ll B) {
        p += N;
        tre[p].mB = B;
        for (p >>= 1; p; p >>= 1)
            tre[p] = tre[p << 1] + tre[p << 1 | 1];
    }
    Node Query(int ql, int qr) {
        Node lres, rres;
        ql += N - 1, qr += N + 1;
        for (; ql ^ qr ^ 1; ql >>= 1, qr >>= 1) {
            if (~ql & 1)
                lres = lres + tre[ql ^ 1];
            if (qr & 1)
                rres = tre[qr ^ 1] + rres;
        }
        return lres + rres;
    }
} zkw;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    zkw.build();
    while (m--) {
        int op;
        ll x, y;
        std::cin >> op >> x >> y;
        switch (op) {
        case 1:
            zkw.UpdateA(x, y);
            break;
        case 2:
            zkw.UpdateB(x, y);
            break;
        case 3:
            std::cout << zkw.Query(x, y).w << '\n';
            break;
        }
    }
    return 0;
}
/*
考虑线段树维护

对于查询：
    我们需要查询某个区间内一个数对 (i,j) 满足
    A_i + A_j - min(B_k) (i < k < j) 最大
    我们可以记为 w_l_r 可以在节点中维护直接取max合并
    然后考虑跨区间
    如果 k 在左节点，那么 j 的取值不影响 k，直接取区间max，可以直接维护 A 最大值，记为 mA
    那么就需要考虑 i 的取值，我们需要维护
    A_i - B_k（i < k） 和
    A_i - B_k (i > k) 的最大值
    分别记为 mld 和 mrd 考虑如何维护这个东西
    如果都在一个节点，那么答案可以取 max
    那么必然是其中一边取 A 最大，其中一边取 B 最小
    考虑边界：对于叶子：mA = A，mB = B，mld = mrd = w = 0
    考虑空节点：mA = -INF,mB = INF,mld = mrd = w = -INF
*/