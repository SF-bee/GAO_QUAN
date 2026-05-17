#include <bits/stdc++.h>
const int MAX = 1e5 + 5;
using ll = long long;
using Row = std::array<int, MAX>;

int n;
std::array<int, MAX> b;
std::vector<int> g[MAX];
// dp_{i,j} = 以i为根的子树中，0/1 选/不选 i 的最大价值
std::array<std::array<int, 2>, MAX> dp;

int main () {
    std::cin.tie(0) -> sync_with_stdio(0);
    
    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> b[i];
    for(int u,v,i = 1;i < n;i++) {
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto dfs = [&](auto &self,int u,int p) -> void {
        dp[u][0] = 0;
        dp[u][1] = b[u];
        for(auto v : g[u]) if(v != p) {
            self(self,v,u);
            dp[u][0] += std::max(dp[v][0],dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    };
    dfs(dfs,1,0);

    std::cout << std::max(dp[1][0],dp[1][1]) << "\n";
}