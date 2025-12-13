#include <bits/stdc++.h>
const int MAX = 3e2 + 5;

int n,m,s[MAX],siz[MAX];
int dp[MAX][MAX]; //dp[i][j] 表示在i为根的子树中选择j门课的最大学分
std::vector<int> g[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int k,i = 1;i <= n;i++){
        std::cin >> k >> s[i];
        g[k].push_back(i);
    }

    auto dfs = [&](auto & dfs,int u) -> void{
        dp[u][1] = s[u];
        siz[u] = 1;
        for(auto v : g[u]){
            dfs(dfs,v);
            siz[u] += siz[v];
        }
        for(auto v : g[u]){
            for(int i = siz[u];i >= 2;i--){ //枚举选择点的数量
                for(int j = 1;j <= std::min(i - 1,siz[v]);j++){
                    dp[u][i] = std::max(dp[u][i],
                                        dp[u][i - j] + dp[v][j]);
                }
            }
        }
    };
    dfs(dfs,0);
    std::cout << dp[0][m + 1] << '\n';
    return 0;
}