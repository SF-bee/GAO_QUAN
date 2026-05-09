#include <bits/stdc++.h>
const int MAX = 3e5 + 5;

int n,k,ans,l,r,mid,cnt;
int siz[MAX];
std::vector<int> g[MAX];

void dfs(int u,int fa){
    siz[u] = 1;
    for(auto v : g[u]) if(v != fa){
        dfs(v,u);
        siz[u] += siz[v];
    }
    if(siz[u] >= mid)
        siz[u] = 0,cnt++;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    for(int i = 1,u,v;i < n;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(l = 1,r = n,mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
        cnt = 0;
        dfs(1,0);
        if(cnt >= k + 1)
            l = (ans = mid) + 1;
        else
            r = mid - 1;
    }
    std::cout << ans << '\n';
    return 0;
}