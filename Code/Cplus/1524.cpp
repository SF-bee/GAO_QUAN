#include <bits/stdc++.h>
const int MAX = 1e3 + 5;

struct DSU {
    std::array<int, MAX> pa;
    DSU(int _size) {
        for (int i = 0; i <= _size; i++)
            pa[i] = i;
    }
    int find(int x) { return pa[x] != x ? pa[x] = find(pa[x]) : x; }
    bool merge(int x, int y) {
        if (find(x) == find(y))
            return 0;
        else {
            pa[find(y)] = pa[find(x)];
            return 1;
        }
    }
};

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int n, m;
    auto Solve = [&]() {
        if (n == 0)
            return;
        DSU dsu(n);
        int cnt = n;
        std::cin >> m;
        for (int x, y, i = 1; i <= m; i++) {
            std::cin >> x >> y;
            if (dsu.merge(x, y))
                cnt--;
        }
        std::cout << cnt - 1 << '\n';
    };
    while (std::cin >> n)
        Solve();
    return 0;
}