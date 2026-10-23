#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int t, T;
int n, m;
std::vector<int> g[MAX];

struct node {
    int u, dis;
    bool operator<(const node &rhs) const {
        if (dis != rhs.dis) return dis < rhs.dis;
        return u > rhs.u;
    }
};

void Art() {
    int c = 0;
    std::vector<int> d(n + 1, INF);
    std::priority_queue<node> q;
    for (q.push({1, d[1] = 0}); !q.empty();) {
        auto [u, dis] = q.top();
        q.pop();
        if (dis != d[u]) continue;
        c++;
        for (int v : g[u]) {
            if (d[v] > dis + 1) q.push({v, d[v] = dis + 1});
        }
    }
    std::cout << c << '\n';
}

int main() {
#if !ONLINE_JUDGE
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
#endif
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> t >> T;
    while (T--) {
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1, u, v; i <= m; i++)
            std::cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
        Art();
    }
    return 0;
}