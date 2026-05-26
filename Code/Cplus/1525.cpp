#include <bits/stdc++.h>
const int MAX = 1e3 + 5;

struct DSU {
    std::array<int, MAX> pa;

    DSU(int n) {
        for (int i = 0; i <= n; i++)
            pa[i] = i;
    }
    int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
    bool merge(int x, int y) {
        if (find(x) == find(y))
            return 0;
        pa[find(y)] = pa[find(x)];
        return 1;
    }
};
int n, m, ans;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    DSU dsu(m);
    for (int x, y, i = 1; i <= n; i++) {
        std::cin >> x >> y;
        if (!dsu.merge(x, y))
            ans++;
    }
    std::cout << ans;
    return 0;
}