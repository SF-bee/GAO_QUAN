#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;

int n, m, q;
std::vector<std::pair<int, int>> g[MAX];

void sol1() {
    while (q--) {
        ll x, y, l, r;
        std::cin >> x >> y >> l >> r;
        std::cout << 0 << '\n';
    }
};
void sol2() {}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> q;
    for (int u, v, w, i = 1; i <= m; i++) {
        std::cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, -w);
    }

    if (m == 0) sol1();
    return 0;
}
/*
考虑树怎么做：
每个连通块深搜，不可能走重复的，因为不会有贡献，所以：
x y 不连通，那么0
x y 连通。那么可能的只有是顺着走一遍或者反着走一遍
然后考虑基环树：
环上的话，必然是一个方向无限增，一个方向无限减
设环上边权和，那么环上的贡献就是 a + kw 或者 b - wk
a,b分别是两个方向绕不成一圈的边权
tarjan缩点，然后在连通分量上
*/