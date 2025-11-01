#include <bits/stdc++.h>
const int MAX = 1e5 + 5;
const int K = 25;

int n,k,c[MAX];
int dp[MAX][25],ans[MAX][25];
std::vector<int> g[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    for(int u,v,i = 1;i < n;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1;i <= n;i++)
        std::cin >> c[i];
    auto dfs1 = [&](auto &dfs,int u,int f) -> void{
        dp[u][0] = c[u];
        for(auto v : g[u]) if(v != f){
            dfs(dfs,v,u);
            for(int i = 1;i <= k;i++)
                dp[u][i] += dp[v][i - 1];
        }
    };
    auto dfs2 = [&](auto &dfs,int u,int f) -> void{
        for(auto v : g[u]) if(v != f){
            ans[v][0] = c[v];
            ans[v][1] = dp[v][1] + c[u];
            for(int i = 2;i <= k;i++)
                ans[v][i] = dp[v][i] + ans[u][i - 1] - dp[v][i - 2];
            dfs(dfs,v,u);
        }
    };
    dfs1(dfs1,1,0);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= k;j++)
            dp[i][j] += dp[i][j - 1];
    for(int i = 1;i <= k;i++) ans[1][i] = dp[1][i];
    dfs2(dfs2,1,0);
    for(int i = 1;i <= n;i++)
        std::cout << ans[i][k] << '\n';
    return 0;
}