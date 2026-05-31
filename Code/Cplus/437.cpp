#include <bits/stdc++.h>
const int N = 2e4 + 5;

struct dsu {
    std::array<int, N> pa, siz;

    dsu(int _size) {
        for (int i = 1; i <= _size; i++)
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
int n, m, q;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    dsu mgs(n);
    for (int a, b, i = 1; i <= m; i++)
        std::cin >> a >> b, mgs.merge(a, b);
    std::cin >> q;
    while (q--) {
        int c, d;
        std::cin >> c >> d;
        std::cout << (mgs.check(c, d) ? "Yes\n" : "No\n");
    }
    return 0;
}