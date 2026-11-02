#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n, m, x, y;
std::vector<int> g[MAX];
int tim, dfn[MAX], low[MAX];
int top, stk[MAX];
int cnt, in[MAX];
std::vector<int> edc[MAX], ig[MAX];


int count(int u,int fa,int ty) {
    int res = edc[u].size();
    // 正在找 x 的子树
    if(ty == 0 && in[y] == u) return 0;
    if(ty == 1 && in[x] == u) return 0;
    for(auto v : ig[u]) if(v != fa){
        int gt = count(v,u,ty);
        if(!gt) return 0;
        res += gt;
    }
    return res;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> n >> m >> x >> y;
    for (int u, v, i = 1; i <= m; i++)
        std::cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

    dfs(1,1);
    for (int i = 1;i <= n;i++) {
        for(auto v : g[i])
            if(in[v] != in[i])
                ig[in[i]].push_back(in[v]);
    }
    int cntx = 0,cnty = 0;
    for(auto v : g[x])
        if(in[v] != in[x])
            cntx += count(in[v],in[x],0);
    for(auto v : g[y])
        if(in[v] != in[y])
            cnty += count(in[v],in[y],1);
    std::cout << cntx * cnty << '\n';
    return 0;
}
/*
给定一张无向图和两个节点 x,y
求出所有的有序数对 (a,b)
满足 a 到 b 的路径必须经过 x y

双连通分量缩点，这样就变成树了

x,y 只要不连着外向边，那么一定是可以有不经过 x,y 的路径的
只需要考虑 x,y 连着外向边
那么所有连着x外向边的分量都必须经过x
所有连着y外向边的分量都必须经过y
这两个分量会贡献答案，其他都不会
就是我们统计 x 为根不包含 y 的子树大小，y 相反
这两个子树分别代表必须经过 x 的点和必须经过 y 的点
乘起来就是答案
*/
