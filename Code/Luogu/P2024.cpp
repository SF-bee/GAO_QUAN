/*
考虑扩展域并查集

考虑三种关系：同类，猎物，天敌
对于同类的关系，很明显这是具有传递性的，可以使用并查集维护。
对于猎物的关系，如果X吃Y,Z和Y是同类，那么X肯定也吃Z，也就是说我们这里认为“X的猎物”和"Y所属的类"是等价的
对于天敌关系

这启示我们：并查集维护的是“等价”的关系

对于同类关系：
当 X 和 Y 不是猎物关系，那么这条关系是合法的
*/
#include <bits/stdc++.h>
const int N = 5e4 + 5;

struct dsu {
    // [1,n] 代表同类域，[n + 1，2n] 代表猎物域，[2n + 1,3n] 代表天敌域
    std::array<int, N * 3> pa, siz;

    dsu(int _size) {
        for (int i = 1; i <= _size * 3; i++)
            pa[i] = i, siz[i] = 1;
    }
    int find(int x) { return pa[x] != x ? pa[x] = find(pa[x]) : x; }
    bool check(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return;
        if (siz[px] < siz[py])
            std::swap(px, py);
        pa[py] = pa[px];
        siz[px] += siz[py];
    }
};
int n, k, ans;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> k;
    dsu mgs(n);
    for (int op, x, y, i = 1; i <= k; i++) {
        std::cin >> op >> x >> y;
        if (x > n || y > n) {
            ans++;
            continue;
        }
        switch (op) {
        case 1: // x = y
            if (mgs.check(x + n, y) || mgs.check(y + n, x) || mgs.check(x + 2 * n, y) ||
                mgs.check(y + 2 * n, x)) {
                ans++;
                break;
            }
            mgs.merge(x, y);
            mgs.merge(x + n, y + n);
            mgs.merge(x + 2 * n, y + 2 * n);
            break;
        case 2: // x -> y
            if (mgs.check(x, y) || mgs.check(y + n, x) || mgs.check(x + 2 * n, y)) {
                ans++;
                break;
            }
            mgs.merge(x + n, y);
            mgs.merge(y + 2 * n, x);
            mgs.merge(y + n, x + 2 * n);
            break;
        }
    }
    std::cout << ans << '\n';
    return 0;
}