#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

struct DSU {
    int fa[MAX], siz[MAX];
    bool power[MAX];

    void init() {
        for (int i = 1; i < MAX; i++)
            fa[i] = i, siz[i] = 1;
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (siz[fx] < siz[fy])
            std::swap(fx, fy);
        fa[fy] = fa[fx];
        siz[fx] += siz[y];
        power[fx] |= power[fy];
    }
} dsu;
std::pair<int, int> e[MAX];
int n, m, k, T;
int q[MAX], a[MAX];

int main() {
    // freopen("toy.in", "r", stdin);
    // freopen("toy.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    return 0;
}
/*
注意到删边是不好维护的。所以可以离线倒序处理每一次删除
这样删除就变成了连边
可以注意到：断电只发生在两个连通块内一个有发电站一个没有的情况
并查集维护连通块大小和是否有发电站即可
*/