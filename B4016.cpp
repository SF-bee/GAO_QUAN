#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,k,dep[MAX];
std::vector<int> g[MAX];

void dfs(int u,int fa,int d){
    dep[u] = d;
    if(dep[u] > dep[k]) k = u;
    for(auto v : g[u]) if(v != fa)
        dfs(v,u,d + 1);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int u,v,i = 1;i < n;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,0);
    std::memset(dep,0,sizeof(dep));
    dfs(k,0,0);
    std::cout << dep[k] << '\n';
    return 0;
}