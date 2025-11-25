#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,m;
int tim,top,dfn[MAX],low[MAX],ins[MAX],stk[MAX];
int cnt,scc[MAX],siz[MAX];
std::vector<int> g[MAX];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m;
    for(int i = 0;i < m;i++) {
        int u,v; std::cin >> u >> v;
        g[u].push_back(v);
    }
    auto dfs = [&](auto &dfs,int u) -> void {
        low[u] = dfn[u] = ++tim, ins[u] = 1, stk[++top] = u;
        for(auto v : g[u]) {
            if(!dfn[v]){
                dfs(dfs,v);
                low[u] = std::min(low[u], low[v]);
            }
            else if(ins[v])
                low[u] = std::min(low[u], dfn[v]);
        }
        if(low[u] == dfn[u]) {
            cnt++;
            do {
                scc[stk[top]] = cnt;
                siz[cnt]++;
                ins[stk[top]] = 0;
            } while(stk[top--] != u);
        }
    };
    for(int i = 1;i <= n;i++)
        if(!dfn[i]) dfs(dfs,i);
    std::vector<int> ind(cnt + 1,0);
    for(int u = 1;u <= n;u++)
        for(auto v : g[u]) if(scc[u] != scc[v])
            ind[scc[v]]++;
    int c = 0;
    for(int i = 1;i <= cnt;i++)
        if(ind[i] == 0 && siz[i] == 1) c++;
    double ans = 1.0 - (double)c / (double)n;
    std::cout << std::fixed << std::setprecision(6) << ans << '\n';
    return 0;
}