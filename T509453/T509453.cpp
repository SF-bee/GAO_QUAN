#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int T,n,k,cnt;
std::array<int,MAX> siz;
std::vector<int> g[MAX];

void init(){
    for(auto &i : g)
        i.clear();
}

void dfs(int u,int fa,int mid){
    siz[u] = 1;
    for(auto v : g[u]) if(v != fa){
        dfs(v,u,mid);
        siz[u] += siz[v];
    }
    if(siz[u] >= mid)
        siz[u] = 0,cnt ++;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> T;
    while(T--){
        init();
        std::cin >> n >> k;
        for(int u,v,i = 0;i < n - 1;i++){
            std::cin >> u >> v;
            g[u].push_back(v);
        }
        int ans = 1;
        for(int l = 2,r = n,mid = (l + r) / 2;l <= r;mid = (l + r) / 2){
            siz.fill(0);
            cnt = 0;
            dfs(1,0,mid);
            if(cnt >= k + 1)
                l = (ans = mid) + 1;
            else
                r = mid - 1;
        }
        std::cout << ans << '\n';
    }
    return 0;
}