#include <bits/stdc++.h>
const int MAX = 1e7 + 5;

struct DSU {
    std::array<int, MAX> pa, size;
    int MaxSize = 1;

    DSU(int n) {
        for (int i = 0; i <= n; i++)
            pa[i] = i, size[i] = 1;
    }
    int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
    bool merge(int x, int y) {
        if (find(x) == find(y))
            return 0;
        int px = find(x), py = find(y);
        if (size[px] < size[py])
            std::swap(px, py);
        pa[py] = pa[px];
        size[px] += size[py];
        MaxSize = std::max(MaxSize, size[px]);
        return 1;
    }
};
int n, cnt;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    DSU dsu(1e7);
    cnt = n;
    for (int x, y, i = 1; i <= n; i++) {
        std::cin >> x >> y;
        dsu.merge(x, y);
    }
    std::cout << dsu.MaxSize << '\n';
    return 0;
}