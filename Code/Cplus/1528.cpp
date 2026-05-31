#include <bits/stdc++.h>
const int N = 1e3 + 5;

struct DSU {
    std::array<int, N> pa;

    DSU(int _siz) {
        for (int i = 1; i <= _siz; i++)
            pa[i] = i;
    }
    int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
    bool merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return false;
        pa[py] = pa[px];
        return true;
    }
};
int n, m, cnt;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    DSU mgs(n);
    cnt = n;
    for (int a, b, i = 1; i <= m; i++) {
        std::cin >> a >> b;
        if (mgs.merge(a, b))
            cnt--;
        else {
            std::cout << "No\n";
            return 0;
        }
    }
    std::cout << (cnt == 1 ? "Yes\n" : "No\n");
    return 0;
}