#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;
const ll mod = 1e9 + 7;

int n, sum = 0;
int a[MAX], b[MAX];

struct DSU {
    int fa[MAX], siz[MAX];
    bool in[MAX];
    void init() {
        for (int i = 0; i <= n; i++) fa[i] = i, siz[i] = 1;
    }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (siz[fx] < siz[fy]) std::swap(fx, fy);
        fa[fy] = fa[fx];
        siz[fx] += siz[fy];
        in[fx] |= in[fy];
    }
} dsu;

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n;
    dsu.init();
    std::vector<int> book;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], sum ^= a[i], book.push_back(a[i]);
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];
    a[++n] = sum, b[n] = sum;
    book.push_back(sum);
    dsu.in[sum] = 1;

    std::sort(book.begin(), book.end());
    book.erase(std::unique(book.begin(), book.end()), book.end());
    for (int i = 1; i <= n; i++) {
        a[i] = std::lower_bound(book.begin(), book.end(), a[i]) - book.begin();
        b[i] = std::lower_bound(book.begin(), book.end(), b[i]) - book.begin();
        dsu.merge()
    }
    return 0;
}
/*
又见面了老师，真是意气风发啊
如果把异或和单独拎出来，那么这就变成了一个交换题
每次可以和异或和换位置，求最小交换次数
置换问题就是建环嘛
如果一个环里面已经有异或和，那么这个环就不管，单独贡献环长 -1

*/