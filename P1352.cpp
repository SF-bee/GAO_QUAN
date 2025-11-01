#include <bits/stdc++.h>
const int MAX = 6e3 + 5;

int n,root,fa[MAX],r[MAX],dp[MAX][2]; //dp[u][0/1]表示u去/不去的最优答案
std::vector<int> g[MAX];

void dfs(int u){
    dp[u][0] = 0;
    dp[u][1] = r[u];
    for(auto v : g[u]){
        dfs(v);
        dp[u][0] += std::max(dp[v][0],dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> r[i];
    root = 1;
    for(int l,k,i = 1;i < n;i++){
        std::cin >> l >> k;
        g[k].emplace_back(l);
        fa[l] = k;
    }
    while(fa[root]) root = fa[root];
    dfs(root);
    std::cout << std::max(dp[root][0],dp[root][1]) << '\n';
    return 0;
}