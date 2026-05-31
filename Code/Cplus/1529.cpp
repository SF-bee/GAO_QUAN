#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e4 + 5;

struct DSU {
    std::array<int, MAX> pa;
    DSU(int _siz) {
        for (int i = 1; i <= _siz; i++)
            pa[i] = i;
    }
    int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return;
        pa[py] = px;
    }
};
int n, m, w;
std::array<ll, MAX> c, d;
std::unordered_map<int, std::pair<ll, ll>> cl;
std::vector<std::pair<int, int>> bcl;
std::array<ll, MAX> f;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> w;
    DSU mgs(n);
    for (int i = 1; i <= n; i++)
        std::cin >> c[i] >> d[i];
    for (int x, y, i = 1; i <= m; i++) {
        std::cin >> x >> y;
        mgs.merge(x, y);
    }

    for (int i = 1; i <= n; i++) {
        cl[mgs.find(i)].first += c[i];
        cl[mgs.find(i)].second += d[i];
    }
    for (auto [id, inf] : cl)
        bcl.emplace_back(inf.first, inf.second);
    for (auto [wi, va] : bcl) {
        for (int j = w; j >= wi; j--)
            f[j] = std::max(f[j], f[j - wi] + va);
    }

    std::cout << f[w] << '\n';
    return 0;
}