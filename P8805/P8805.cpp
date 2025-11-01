#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n,m;
std::vector<int> g[MAX << 1];  //g为邻接表
int log_2[MAX],dep[MAX],fa[20][MAX],pre[MAX];

void dfs(int x,int d){  //预处理每个节点的祖先和从根到这个节点的延迟和
    dep[x] = d;
    for(int j = 1;(1 << j) <= dep[x];j++)
        fa[j][x] = fa[j - 1][fa[j - 1][x]];
    for(auto i : g[x])
        if(dep[i] == 0)
            fa[0][i] = x,
            pre[i] = pre[x] + g[i].size(),
            dfs(i,d + 1);
}

int lca(int x,int y){  //求最近公共祖先
    if(dep[x] < dep[y]) std::swap(x,y);
    int d = dep[x] - dep[y];
    for(int k = 0;k <= log_2[n];k++)
        if(d & (1 << k)) x = fa[k][x];
    if(x == y) return x;
    for(int k = log_2[n];k >= 0;k--)
        if(fa[k][x] != fa[k][y])
            x = fa[k][x],
            y = fa[k][y];
    return fa[0][x];
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i < n;i++){
        int u,v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 2;i <= n;i++)  //预处理log2
        log_2[i] = log_2[i >> 1] + 1;
    dfs(1,1);
    while(m--){
        int u,v;
        std::cin >> u >> v;
        int t = lca(u,v);
        std::cout << pre[u] + pre[v] - 2 * pre[t] + g[t].size() << '\n';
    }
    return 0;
}