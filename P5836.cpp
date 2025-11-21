#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,m,dep[MAX],fa[20][MAX]; //fa[k][x] 表示 x 的第 2 ^ k 级祖先
bool vg[20][MAX],vh[20][MAX]; //vg[k][x] 表示从 x 到它的第 2 ^ k 级祖先是否有g牛，vh 是否有h牛
char farm[MAX];
std::vector<int> g[MAX];

void dfs(int u,int f){  //深搜初始化
    dep[u] = dep[f] + 1;
    fa[0][u] = f;
    vg[0][u] = (farm[u] == 'G' || farm[f] == 'G' ? 1 : 0);
    vh[0][u] = (farm[u] == 'H' || farm[f] == 'H' ? 1 : 0);
    for(auto v : g[u]) if(v != f)
        dfs(v,u);
}

bool lca(int x,int y,char ch){  //最近公共祖先祖先求 u 到 v 的路径
    bool flag = 0;
    if(dep[x] < dep[y]) std::swap(x,y);
    int d = dep[x] - dep[y];
    for(int k = 0;k < 20;k++) if(d & (1 << k)){
            if(ch == 'G') flag = (flag || vg[k][x]);
            else flag = (flag || vh[k][x]); 
            x = fa[k][x];
            if(flag) return 1;
        }
    if(x == y) return flag;
    for(int k = 19;k >= 0;k--)
        if(fa[k][x] != fa[k][y]){
            if(ch == 'G') flag = (flag || vg[k][x] || vg[k][y]);
            else flag = (flag || vh[k][x] || vh[k][y]); 
            x = fa[k][x];
            y = fa[k][y];
            if(flag) return 1;
        }
    if(ch == 'G') return (flag || vg[0][x] || vg[0][y]);
    else return (flag || vh[0][x] || vh[0][y]);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> farm[i];
    for(int u,v,i = 1;i < n;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    //初始化倍增数组
    dfs(1,0);
    for(int k = 1;k < 20;k++){
        for(int i = 1;i <= n;i++){
            fa[k][i] = fa[k - 1][fa[k - 1][i]];
            vg[k][i] = (vg[k - 1][i] || vg[k - 1][fa[k - 1][i]]? 1 : 0);
            vh[k][i] = (vh[k - 1][i] || vh[k - 1][fa[k - 1][i]]? 1 : 0);
        }
    }

    int u,v;
    char ch;
    for(int i = 1;i <= m;i++){
        std::cin >> u >> v >> ch;
        if(u == v){
            if(ch == 'G') std::cout << (farm[u] == 'G'? 1 : 0);
            else std::cout << (farm[u] == 'H'? 1 : 0);
        }
        else std::cout << lca(u,v,ch);
    }
    std::cout << '\n';
    return 0;
}