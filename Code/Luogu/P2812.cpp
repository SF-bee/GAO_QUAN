#include <bits/stdc++.h>
const int MAX = 1e4 + 5;

int n, m;
std::vector<int> g[MAX];
int tim, dfn[MAX], low[MAX];
int top, stk[MAX], ins[MAX];
int cnt, scc[MAX];
int ind[MAX], oud[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int v;;) {
            std::cin >> v;
            if (v == 0) break;
            g[i].push_back(v);
        }
    }

    auto dfs = [&](auto &self, int u) -> void {
        ins[u] = low[u] = dfn[u] = ++tim;
        stk[++top] = u;
        for (auto v : g[u]) {
            if (!dfn[v]) {
                self(self, v);
                low[u] = std::min(low[u], dfn[v]);
            } else if (ins[v])
                low[u] = std::min(low[u], low[v]);
        }
        if (dfn[u] == low[u]) {
            cnt++;
            do {
                scc[stk[top]] = cnt;
                ins[stk[top]] = 0;
            } while (stk[top--] != u)
        }
    };
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs(dfs, i);

    if (cnt == 1) {
        std::cout << 1 << '\n' << 0 << '\n';
    }
    for (int i = 1; i <= n; i++) {
        for (auto v : g[i])
            ind[scc[v]]++, oud[scc[i]]++;
    }
    int i0 = 0, o0 = 0;
    for (int i = 1; i <= cnt; i++) {
        if (ind[i] == 0) i0++;
        if (oud[i] == 0) o0++;
    }

    return 0;
}