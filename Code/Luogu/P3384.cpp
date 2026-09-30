#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;

int n, m, r, p;
int v[MAX];
std::vector<int> g[MAX];

struct SegmentTree {
    struct node {
        ll sum, tag;
    } tre[MAX << 2];

#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
    void PushUp(int p) { tre[p].sum = tre[ls(p)].sum + tre[rs(p)].sum; }
    void Apply(int p, int l, int r, ll k) {}
} seg;

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++)
        std::cin >> v[i];
    for (int u, v, i = 1; i < n; i++) {
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    return 0;
}