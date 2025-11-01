#include <bits/stdc++.h>
#define Nanami return
#define ChiaKi 0
using ll = long long;
const int MAX = 2e5 + 5;

int T;
int n,siz[MAX];
ll a[MAX],f[MAX],m[MAX];
std::vector<int> g[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        std::cin >> n;
        for(int i = 1;i <= n;i++)
            std::cin >> a[i];
        for(int u,v,i = 1;i < n;i++){
            std::cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        auto dfs = [&](auto &dfs,int u,int fa) -> void{
            siz[u] = 1;
            for(auto v : g[u]) if(v != fa){
                dfs(dfs,v,u);
                siz[u] += siz[v];
                f[u] += f[v] + siz[v] * (a[u] ^ a[v]);
            }
        };
        dfs(dfs,1,0);
        m[1] = f[1];
        auto dfs2 = [&](auto &dfs,int u,int fa) -> void{
            for(auto v : g[u]) if(v != fa){
                m[v] = m[u] + f[v] - (f[v] + siz[v]*(a[v]^a[u])) + (n - siz[v])*(a[v]^a[u]);
                dfs(dfs,v,u);
            }
        };
        dfs2(dfs2,1,0);
        for(int i = 1;i <= n;i++){
            std::cout << m[i] << " \n"[i == n];
            siz[i] = f[i] = m[i] = 0;
            g[i].clear();
        }
    }
    Nanami ChiaKi;
}