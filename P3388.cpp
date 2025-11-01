#include <bits/stdc++.h>
const int MAX = 2e4 + 5;

std::vector<int> g[MAX];
int tim,cnt,root;
int dfn[MAX],low[MAX],cut[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,m;
    std::cin >> n >> m;
    for(int u,v,i = 1;i <= m;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    auto tarjan = [&](auto & dfs,int u) -> void{
        dfn[u] = low[u] = ++tim;
        if(u == root && g[u].size() == 0) return;
        int son = 0;
        for(auto v : g[u]){
            if(!dfn[v]){
                dfs(dfs,v);
                low[u] = std::min(low[u],low[v]);
                if(low[v] >= dfn[u])
                    if(++son > 1 || u != root) cut[u] = 1;
            }
            else low[u] = std::min(low[u],dfn[v]);
        }
    };
    for(int i = 1;i <= n;i++)
        if(!dfn[i]) root = i,tarjan(tarjan,i);
    int cnt = 0;
    std::vector<int> ans;
    for(int i = 1;i <= n;i++)
        if(cut[i]) cnt++,ans.push_back(i);
    std::cout << cnt << '\n';
    for(auto i : ans)
        std::cout << i << ' ';
    return 0;
}