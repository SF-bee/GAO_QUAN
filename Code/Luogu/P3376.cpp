#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e2 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct edge {
    int to, rev;
    ll flow;
};
int n, m, s, t;
std::vector<edge> g[MAX];
int d[MAX], cur[MAX];

bool bfs() {
    memset(d, 255, sizeof(d));
    std::queue<int> q;
    for (q.push(s), d[s] = 0; !q.empty();) {
        int u = q.front();
        q.pop();
        for (auto &[v, r, flow] : g[u]) {
            if (flow && d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d[t] != -1;
}
ll dinic(int u, ll fl) {
    if (u == t) return fl;
    for (int &i = cur[u]; i < g[u].size(); i++) {
        auto &[v, r, f] = g[u][i];
        if (f && d[v] == d[u] + 1) {
            ll x = dinic(v, std::min(fl, f));
            if (x) {
                f -= x;
                g[v][r].flow += x;
                return x;
            }
        }
    }
    return 0;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> s >> t;
    for (int u, v, w, i = 1; i <= m; i++) {
        std::cin >> u >> v >> w;
        g[u].push_back({v, (int)g[v].size(), w});
        g[v].push_back({u, (int)g[u].size() - 1, 0});
    }

    ll ans = 0;
    while (bfs()) {
        std::memset(cur, 0, sizeof(cur));
        while (ll x = dinic(s, INF))
            ans += x;
    }
    std::cout << ans << '\n';
    return 0;
}