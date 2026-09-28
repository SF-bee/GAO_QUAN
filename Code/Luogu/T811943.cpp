#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 1e5;

int k, n;
ll ans;
int a[MAX], pos[MAX];
std::vector<std::tuple<int, int, int>> edge;
std::vector<std::pair<int, int>> eans;

struct DSU {
    int fa[MAX], siz[MAX];
    void init() {
        for (int i = 0; i < n; i++)
            fa[i] = i, siz[i] = 1;
    }
    int find(int x) { return fa[x] != x ? fa[x] = find(fa[x]) : x; }
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return 0;
        if (siz[fx] < siz[fy]) std::swap(fx, fy);
        fa[fy] = fx;
        siz[fx] += siz[fy];
        return 1;
    }
} dsu;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    k = n;
    {
        int res = 1;
        for (int i = 1; i <= n; i++)
            res *= 2;
        n = res;
    }
    dsu.init();
    for (int i = 0; i < n; i++)
        std::cin >> a[i], pos[i] = i;

    for (int i = 0; i < k; i++) {
        for (int st = 0; st < n; ++st) {
            if ((st >> i) & 1) {
                if (a[st] > a[st ^ (1 << i)]) {
                    int sub = st ^ (1 << i);
                    if (a[st] > a[sub]) {
                        a[st] = a[sub];
                        pos[st] = pos[sub];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (!((i >> j) & 1)) {
                edge.emplace_back(a[i], pos[i], i | (1 << j));
            }
        }
    }
    std::sort(edge.begin(), edge.end());
    for (int bs = n, i = 0; bs > 1 && i < edge.size(); i++) {
        auto [w, u, v] = edge[i];
        if (dsu.merge(u, v)) {
            ans += w;
            eans.emplace_back(u, v);
            bs--;
        }
    }
    std::cout << n - 1 << '\n';
    for (auto [u, v] : eans)
        std::cout << u << ' ' << v << '\n';
    std::cout << ans << '\n';
    return 0;
}
/*
2^20 大约是 1e6，所以我们需要一个 O(n) 的算法
题目大意：给定 n 个节点，每个节点之间的边权为它们的编号与和所对应的权值，求最小生成树
一个直观的想法：暴力建出n^2条边，然后跑最小生成树
考虑如何优化边的数量？
把a按照权值排序，枚举排序后的 i , 接着考察所有与和为 i 的节点对
固定这个 i 为中心，枚举所有 j 满足 i & j = i 的然后连边

*/