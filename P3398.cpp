#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,q;
int dep[MAX],siz[MAX],fa[MAX],son[MAX],top[MAX];
std::vector<int> g[MAX];
int cnt[MAX];

void dfs1(int u,int f,int d){
    siz[u] = 1,dep[u] = d,fa[u] = f;
    for(auto v : g[u]) if(v != f){
        dfs1(v,u,d + 1);
        siz[u] += siz[v];
        if(siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u,int t){
    top[u] = t;
    if(son[u] == 0) return;
    dfs2(son[u],t);
    for(auto v : g[u]) if(v != son[u] && v != fa[u])
        dfs2(v,v);
}
int lca(int x,int y){
    while(top[x] != top[y]){
        if(dep[top[x]] > dep[top[y]])
            x = fa[top[x]];
        else y = fa[top[y]];
    }
    return dep[x] > dep[y] ? y : x;
}
int dis(int x,int y){
    return dep[x] + dep[y] - 2 * dep[lca(x,y)];
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q;
    for(int u,v,i = 1;i < n;i++){
        std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs1(1,0,0);
    dfs2(1,1);
    for(int i = 1;i <= q;i++){
        int a,b,c,d;
        std::cin >> a >> b >> c >> d;
        int x = lca(a,b),y = lca(c,d);
        if(dis(a,y) + dis(b,y) == dis(a,b) || dis(c,x) + dis(d,x) == dis(c,d))
            std::cout << "Y\n";
        else std::cout << "N\n";
    }
    return 0;
}