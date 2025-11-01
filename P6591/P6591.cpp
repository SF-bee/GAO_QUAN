#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n,siz[MAX];
std::bitset<1000005> vis;
std::vector<int> g[MAX];

int dfs(int d,int fa){
    siz[d] = 1;
    for(auto u : g[d]) if(u != fa)
        siz[d] += dfs(u,d);
    return siz[d];
}

void solve(int u,int fa){
    bool flag = 1;
    int pre = -1;
    for(auto v : g[u]){
        if(v == fa){
            if(pre == -1) pre = n - siz[u];
            else if(pre != n - siz[u]) flag = 0;
        }
        else{
            if(pre == -1) pre = siz[v];
            else if(pre != siz[v]) flag = 0;
            solve(v,u);
        }
    }
    if(flag) vis[u] = 1;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1,u,v;i < n;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);
    solve(1,0);
    for(int i = 1;i <= n;i++)
        if(vis[i]) std::cout << i << ' ';
    return 0;
}