#include <bits/stdc++.h>
const int N = 5e4 + 5;

int n,k;
int cnt[N],dep[N],st[20][N];
std::vector<int> g[N];

void dfs(int u,int fa,int d){
    st[0][u] = fa;
    dep[u] = d;
    for(auto v : g[u]) if(v != fa)
        dfs(v,u,d + 1);
}

void solve(int u,int fa){
    for(auto v : g[u]) if(v != fa){
        solve(v,u);
        cnt[u] += cnt[v];
    }
}

int lca(int x,int y){
    if(dep[x] < dep[y]) std::swap(x,y);
    int d = dep[x] - dep[y];
    for(int k = 0;k < 20;k++)
        if((1 << k) & d) x = st[k][x];
    if(x == y) return x;
    for(int k = 19;k >= 0;k--){
        if(st[k][x] != st[k][y])
            x = st[k][x], y = st[k][y];
    }
    return st[0][x];
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    for(int u,v,i = 1;i < n;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,1);
    st[0][1] = 1;
    for(int i = 1;i < 20;i++)
        for(int j = 1;j <= n;j++)
            st[i][j] = st[i - 1][st[i - 1][j]];
    int s,t;    
    while(k--){
        std::cin >> s >> t;
        int fa = lca(s,t);
        cnt[s] += 1;
        cnt[t] += 1;
        cnt[fa] -= 1;
        cnt[st[0][fa]] -= 1;
    }
    solve(1,0);
    int ans = INT_MIN;
    for(int i = 1;i <= n;i++)
        ans = std::max(ans,cnt[i]);
    std::cout << ans << '\n';
    return 0;
}