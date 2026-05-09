#include <bits/stdc++.h>
#define int long long
const int MAX = 1e6 + 5;

int n,ans,maxa,dp[MAX],siz[MAX];
std::vector<int> g[MAX];

main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int u,v,i = 1;i < n;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto dfs1 = [&](auto &dfs,int u,int f,int d) -> void{
        dp[u] = d;
        siz[u] = 1;
        for(auto v : g[u]) if(v != f){
            dfs(dfs,v,u,d + 1);
            dp[u] += dp[v];
            siz[u] += siz[v];
        }
    };
    auto dfs2 = [&](auto & dfs,int u,int f) -> void{
        for(auto v : g[u]) if(v != f){
            dp[v] = dp[u] - siz[v] + n - siz[v];
            if(maxa < dp[v]) maxa = dp[v],ans = v;
            dfs(dfs,v,u);
        }
    };
    dfs1(dfs1,1,0,1);
    ans = 1,maxa = dp[1];
    dfs2(dfs2,1,0);
    std::cout << ans << '\n';
    return 0;
}