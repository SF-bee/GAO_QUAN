#include <bits/stdc++.h>
const int MAX = 1e2 + 5;

int n,q;
int siz[MAX],dp[MAX][MAX];
std::vector<std::pair<int,int> > g[MAX]; 

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q;
    for(int u,v,w,i = 1;i < n;i++){
        std::cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    auto dfs = [&](auto &dfs,int u,int f) -> void{
        int lc = 0,lw = 0,rc = 0,rw = 0;
        siz[u] = 1;
        for(auto [v,w] : g[u]) if(v != f){
            dfs(dfs,v,u);
            if(!lc) lc = v,lw = w;
            else rc = v,rw = w;
            siz[u] += siz[v];
        }
        dp[u][1] = std::max(lw,rw);
        for(int k = 2;k < siz[u];k++){
            dp[u][k] = std::max(dp[lc][k - 1] + lw,dp[rc][k - 1] + rw);
            for(int i = 1;i <= k - 1;i++){
                dp[u][k] = std::max(dp[u][k],lw + dp[lc][i - 1] + rw + dp[rc][k - i - 1]);
            }
        }
    };
    dfs(dfs,1,0);
    std::cout << dp[1][q] << '\n';
    return 0;
}