#include <bits/stdc++.h>
const int MAX = 1e4 + 5;

int cnt,tim,top;
int a[MAX],dfn[MAX],low[MAX],scc[MAX],sta[MAX],siz[MAX];
bool ins[MAX];
std::vector<int> g[MAX];
std::vector<int> sg[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,m;
    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) std::cin >> a[i];
    for(int u,v,i = 0;i < m;i++) {
        std::cin >> u >> v;
        g[u].push_back(v);
    }
    auto tarjan = [&](auto &dfs,int u) -> void{
        dfn[u] = low[u] = ++tim;
        ins[sta[++top] = u] = 1;
        for(auto v : g[u]){
            if(!dfn[v]){
                dfs(dfs,v);
                low[u] = std::min(low[u],low[v]);
            }
            else if(ins[v])
                low[u] = std::min(low[u],dfn[v]);
        }
        if(dfn[u] == low[u]){
            cnt++;
            do{
                scc[sta[top]] = cnt;
                siz[cnt] += a[sta[top]];
                ins[sta[top]] = 0;
            }while(sta[top--] != u);
        }
    };
    for(int i = 1;i <= n;i++) if(!dfn[i])
        tarjan(tarjan,i);
    std::vector<int> id(cnt + 1,0),od(cnt + 1,0),dis(cnt + 1,0);
    std::vector<bool> vis(cnt + 1,0);
    for(int u = 1;u <= n;u++)
        for(auto v : g[u]) if(scc[u] != scc[v]){
            sg[scc[u]].push_back(scc[v]);
            id[scc[v]]++;
            od[scc[u]]++;
        }
    std::priority_queue<std::pair<int,int> > que;
    for(int i = 1;i <= cnt;i++) if(id[i] == 0)
        que.push({i,dis[i] = siz[i]});
    while(!que.empty()){
        auto [u,d] = que.top();
        que.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto v : sg[u]) if(dis[v] < dis[u] + siz[v])
            que.push({v,dis[v] = dis[u] + siz[v]});
    }
    int ans = -1;
    for(int i = 1;i <= cnt;i++)
        ans = std::max(ans,dis[i]);
    std::cout << ans << '\n';
    return 0;
}