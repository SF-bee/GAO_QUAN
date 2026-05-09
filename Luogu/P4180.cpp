#include <bits/stdc++.h>
using ll = long long;
const int N = 1e5 + 5;
const int M = 3e5 + 5;

int n,m,fa[N];
std::vector<std::pair<int,int> > g[N];
struct edge{
    int u,v;
    ll w;
    bool operator < (const edge& rhs) const {
        return w < rhs.w;
    }
}e[M];
bool vis[M];
int f[22][N],dep[N];
ll ras,ans = LONG_LONG_MAX,maxx[22][N],minx[22][N];

void init() {for(int i = 1;i <= n;i++) fa[i] = i;}
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y) {fa[find(x)] = fa[find(y)];}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    init();
    for(int i = 1;i <= m;i++)
        std::cin >> e[i].u >> e[i].v >> e[i].w;
    
    std::sort(e + 1,e + m + 1);
    for(int i = 1,c = n;i <= m && c > 1;i++) {
        auto [u,v,w] = e[i];
        if(find(u) != find(v)){
            merge(u,v);
            ras += w;
            c--,vis[i] = 1;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
    }

    auto dfs = [&](auto & dfs,int u,int dy,int d) ->void{
        dep[u] = d;
        minx[0][u] = INT_MIN;
        f[0][u] = dy;
        for(auto [v,w] : g[u]) if(v != dy){
            maxx[0][v] = w;
            dfs(dfs,v,u,d + 1);
        }
    };
    dfs(dfs,1,1,1);
    for(int k = 1;k <= 21;k++)
        for(int i = 1;i <= n;i++){
            f[k][i] = f[k - 1][f[k - 1][i]];  
            ll kk[4] = {maxx[k - 1][i], maxx[k - 1][f[k - 1][i]],
                   minx[k - 1][i], minx[k - 1][f[k - 1][i]]};
            std::sort(kk, kk + 4);
            maxx[k][i] = kk[3];
            int ptr = 2;
            while (ptr >= 0 && kk[ptr] == kk[3]) ptr--;
            minx[k][i] = (ptr == -1 ? INT_MIN : kk[ptr]);
        }
    auto lca = [&](int x,int y) -> ll{
        if(dep[x] < dep[y]) std::swap(x,y);
        int d = dep[x] - dep[y];
        for(int k = 0;k <= 21;k++) if(d & (1 << k))
            x = f[k][x];
        if(x == y) return x;
        for(int k = 21;k >= 0;k--) if(f[k][x] != f[k][y]){
            x = f[k][x];
            y = f[k][y];
        }
        return f[0][x];
    };
    auto query = [&](int _lca,int x,ll w) -> ll{
        if(_lca == x) return 0;
        ll res = INT_MIN;
        for(int k = 21;k >= 0;k--) if(dep[_lca] <= dep[f[k][x]]){
            if (w != maxx[k][x])
                res = std::max(res, maxx[k][x]);
            else
                res = std::max(res, minx[k][x]);
            x = f[k][x];
        }
        return res;
    };

    for(int i = 1;i <= m;i++) if(!vis[i]){
        auto [u,v,w] = e[i];
        if(u == v) continue;
        int _lca = lca(u,v);
        ll me = std::max(query(_lca,u,w),query(_lca,v,w));
        if(me > INT_MIN) ans = std::min(ans, ras - me + w);
    }
    std::cout << ans << '\n';
    return 0;
}