#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,q,c[MAX],dep[MAX],fa[30][MAX],val[30][MAX];
std::vector<int> g[MAX];

//深搜处理每个节点的父亲，每个节点权值与父亲权值的按位或，每个节点的深度
void dfs(int u,int f){
    fa[0][u] = f;
    val[0][u] = c[u] | c[f];
    dep[u] = dep[f] + 1;
    for(auto v : g[u]) if(v != f) dfs(v,u);
}
//获取一个数字有多少位为1
int get(int x){
    int cnt = 0;
    for(int k = 0;k <= 25;k++)
        if(x & (1 << k)) cnt++;
    return cnt;
}
//最近公共祖先处理路径上每个节点权值的按位或
int ask(int x,int y){
    int res = c[x] | c[y];  //按位或的值
    if(dep[x] < dep[y]) std::swap(x,y);
    int d = dep[x] - dep[y];
    for(int k = 0;k < 20;k++)
        if(d & (1 << k)) res |= val[k][x],x = fa[k][x];
    if(x == y) return res;
    for(int k = 20;k >= 0;k--)
        if(fa[k][x] != fa[k][y]){
            res |= val[k][x] | val[k][y];
            x = fa[k][x];
            y = fa[k][y];
        }
    return res | val[0][x];
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q;
    for(int i = 1;i <= n;i++)
        std::cin >> c[i],c[i] = 1 << (c[i] - 1);  //将颜色变为一个二进制位
    for(int i = 1,u,v;i < n;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    //初始化st表
    for(int j = 1;j < 20;j++)
        for(int i = 1;i <= n;i++)
            val[j][i] = val[j - 1][i] | val[j - 1][fa[j - 1][i]],
            fa[j][i] = fa[j - 1][fa[j - 1][i]];
    int s,t;
    while(q--){
        std::cin >> s >> t;
        std::cout << get(ask(s,t)) << '\n';        
    }
    return 0;
}