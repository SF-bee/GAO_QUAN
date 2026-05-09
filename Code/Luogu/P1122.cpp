#include <bits/stdc++.h>
const int MAX = 2e4;

int n,ans = INT_MIN,a[MAX];
std::vector<int> g[MAX];
int f[MAX]; //f_i表示以i为根的子树所能得到的最大贡献

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int u,v,i = 1;i < n;i++){
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    auto dfs = [&](auto &dfs,int u,int fa) -> void{
        f[u] = a[u];
        for(auto v : g[u]) if(v != fa)
            dfs(dfs,v,u);
        for(auto v : g[u]) if(v != fa)
            f[u] = std::max(f[u],f[u] + f[v]);
        ans = std::max(ans,f[u]);
    };
    dfs(dfs,1,0);
    std::cout << ans << '\n';
    return 0;
}