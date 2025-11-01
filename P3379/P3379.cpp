#include <bits/stdc++.h>
const int MAX = 5e5 + 5;

int n,m,s,mx = 0;
std::vector<int> g[MAX];
int dep[MAX],fa[MAX][20];

void dfs(int x,int d){
    dep[x] = d;
    for(auto i : g[x])
        if(dep[i] == 0) fa[i][0] = x,dfs(i,d + 1);
}

void init(){
    fa[s][0] = s;
    for(int j = 1;(1 << j) <= n;j++){
        mx = j;
        for(int i = 1;i <= n;i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
        
}

int LCA(int a,int b){
    if(dep[a] < dep[b]) std::swap(a,b);
    int d = dep[a] - dep[b];
    for(int k = 0;k <= mx;k++)
        if(d & (1 << k)) a = fa[a][k];
    if(a == b) return a;
    for(int k = mx;k >= 0;k--)
        if(fa[a][k] != fa[b][k])
            a = fa[a][k],b = fa[b][k];
    return fa[a][0];
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> s;
    for(int i = 1;i < n;i++){
        int x,y;
        std::cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(s,1);
    init();
    while(m--){
        int a,b;
        std::cin >> a >> b;
        std::cout << LCA(a,b) << '\n';
    }
    return 0;
}