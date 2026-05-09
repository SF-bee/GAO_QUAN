#include <bits/stdc++.h>
const int MAX = 1e4 + 5;

int n,m,a[MAX];
std::vector<int> g[MAX],scg[MAX];
int tim,dfn[MAX],low[MAX],stk[MAX],top;
bool ins[MAX],vis[MAX];
int cnt,scc[MAX],val[MAX],ind[MAX],dis[MAX];

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int u,v,i = 1;i <= m;i++) {
        std::cin >> u >> v;
        g[u].push_back(v);
    }

    auto dfs = [&](auto &self,int u) -> void {
        dfn[u] = low[u] = ++tim;
        stk[++top] = u;
        ins[u] = 1;
        for(auto v : g[u]) {
            if(!dfn[v]) {
                self(self,v);
                low[u] = std::min(low[u], low[v]);
            } else if(ins[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if(low[u] == dfn[u]) {
            cnt++;
            do {
                val[cnt] += a[stk[top]];
                scc[stk[top]] = cnt;
                ins[stk[top]] = 0;
            } while (stk[top--] != u);
        }
    };
    for(int u = 1;u <= n;u++)
        if(!dfn[u]) dfs(dfs,u);
    for(int u = 1;u <= n;u++) {
        for(auto v : g[u]) if(scc[u] != scc[v]) {
            ind[scc[v]]++;
            scg[scc[u]].push_back(scc[v]);
        }
    }
    std::queue<int> q;
    for(int i = 1;i <= cnt;i++) {
        dis[i] = val[i];
        if(ind[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : scg[u]){
            if(dis[v] < dis[u] + val[v]) dis[v] = dis[u] + val[v];
            if(--ind[v] == 0) q.push(v);
        }
    }
    std::cout << *std::max_element(dis + 1, dis + cnt + 1);
    return 0;
}