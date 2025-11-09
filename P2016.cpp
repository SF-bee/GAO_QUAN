#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int MAX = 1e5 + 5;

int n;
std::vector<int> g[MAX];
int dp[2][MAX];

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n;
    for(int id,k,u,i = 0;i < n;i++){
        std::cin >> id >> k;
        for(int j = 0;j < k;j++)
            std::cin >> u,
            g[id].push_back(u),
            g[u].push_back(id);
    }
    auto dfs = [&](auto &dfs,int u,int fa) -> void
    {
        dp[1][u] = 1;
        int sum = 0;
        for(auto v : g[u]) if(v != fa){
            dfs(dfs,v,u);
            dp[0][u] += dp[1][v];
            dp[1][u] += std::min(dp[0][v],dp[1][v]);
        }
    };
    dfs(dfs,1,1);
    std::cout << std::min(dp[0][1],dp[1][1]) << '\n';
    return 0;
}