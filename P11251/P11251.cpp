#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,ans,r,vis[MAX],d[MAX],c[MAX];
std::vector<int> g[MAX];

void dfs(int u,int fa){
    vis[u] = 1;
    for(auto v : g[u]) if(v != fa){
        d[v] = d[u] + 1;
        if(d[v] > d[r]) r = v;
        dfs(v,u);
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> c[i];
    for(int i = 1,u,v;i < n;i++){
        std::cin >> u >> v;
        if(c[u] == c[v]) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            dfs(i,0);
            d[r] = 0,dfs(r,0);
            ans = std::max(ans,d[r]);
        }
    }
    std::cout << ans + 1 << '\n';
    return 0;
}