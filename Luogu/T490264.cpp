#include <bits/stdc++.h>
const int MAX = 5e5 + 5;

int n,q,p;
std::vector<int> g[MAX];
bool vis[MAX];
int fa[MAX][20];  //fa_i_j代表 i 节点的第 2^j 级父亲

void dfs(int d){  //深搜处理每个节点的父亲
    vis[d] = 1;
    for(auto i : g[d])
        if(!vis[i]){
            vis[i] = 1;
            fa[i][0] = d;
            dfs(i);
        }
}

int query(int u,int k){  //查询第 k 级父亲
    int now = u,cnt = 0;
    if(now == 1) return now;
    while(k){  //二进制拆分k
        if(now == 1) return now;
        int x = k & 1;
        now = (x == 1 ? fa[now][cnt] : now);
        cnt++;
        k >>= 1;
    }
    return now;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q >> p;
    for(int i = 1;i < n;i++){
        int u,v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    fa[1][0] = 1;
    for(int j = 1;(1 << j) <= n;j++)  //st表预处理
        for(int i = 1;i <= n;i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    while(q--){
        int op,k;
        std::cin >> op >> k;
        switch (op){
            case 1:
            p = k;
            break;
            case 2:
            p = query(p,k);
            std::cout << p << '\n';
            break;
        }
    }
    return 0;
}