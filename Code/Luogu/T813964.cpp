#include <bits/stdc++.h>
const int MAX = 2e6 + 5;
const int INF = 0x3f3f3f3f;

int q, l, r;
int w[MAX];
bool NotPri[MAX];
std::vector<int> Prime;
void init() {
    for (int i = 2; i < MAX; i++) {
        if (!NotPri[i]) Prime.push_back(i), w[i] = 1;
        for (auto p : Prime) {
            if (i * p >= MAX) break;
            NotPri[i * p] = 1;
            if (i % p != 0) w[i * p] = w[i] + 1;
            if (i % p == 0) {
                w[i * p] = w[i];
                break;
            }
        }
    }
}
struct DSU {
    int fa[MAX], siz[MAX];
    void init() {
        for (int i = l; i <= r; i++)
            fa[i] = i, siz[i] = 1;
    }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return 0;
        if (siz[fx] < siz[fy]) std::swap(fx, fy);
        fa[fy] = fa[fx];
        siz[fx] += siz[fy];
        return 1;
    }
} dsu;

int solve() {
    dsu.init();
    int n = r - l + 1, ans = 0;
    std::vector<std::pair<int, int>> vec[15];
    for (int d = 1; d <= n; d++) {
        int minw = INF, m;
        for (int i = (l + d - 1) / d * d; i <= r; i += d)
            if (w[i] < minw) minw = w[i], m = i;
        for (int i = (l + d - 1) / d * d; i <= r; i += d) {
            if (i != m) vec[w[i] + w[m] - w[d]].push_back({i, m});
        }
    }
    for (int i = 0; i < 15; i++) {
        for (auto [u, v] : vec[i])
            if (dsu.merge(u, v)) {
                ans += i;
                n--;
                if (n == 1) return ans;
            }
    }
    return ans;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    init();
    std::cin >> q;
    while (q--) {
        std::cin >> l >> r;
        std::cout << solve() << '\n';
    }
    return 0;
}
/*
观察数据范围：sum_r = 2e6,这说明每次询问我们可以 O(n) 地解决
现在考虑如何求出区间 l，r 的最小生成树
w是可以On预处理的，lcm也是近似O1的，合并也是近似O1的
考虑如何优化选边
考虑最小生成树的过程：取出最小的边，然后判断是否能够合并
很明显，不能直接建出所有的边，这会退化为n^2，但是合并次数是On的，可以在这里考虑？
实际上，这个过程是在不同的连通块里选点，求出最小的w(lcm(a,b))
注意一件事情：2*3*5*7*11*13 = 30030 > 2e6，
也就是说，边权的值域非常小，只有 6，换句话说，每个数的质因子集合非常小，可以在这里考虑？
可以考虑按照质因子集合大小枚举层，然后把当前层合并直到没有合法的
现在考虑怎么快速地求出所有的合法合并
考虑一个点x,它的质因子集合是P(x)，那么合法的y应该满足质因子内包含
可以把集合大小和k做差，然后枚举对应数量与x不同的质因子？
*/