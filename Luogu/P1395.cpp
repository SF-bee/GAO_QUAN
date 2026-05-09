#include <bits/stdc++.h>
const int MAX = 5e4 + 5;

int n,ans;
int siz[MAX],wei[MAX],cen[2];
bool vis[MAX];
std::vector<int> g[MAX];

void dfs(int d,int fa){
    siz[d] = 1;
    wei[d] = 0;
    for(int i : g[d]) if(i != fa) {
        dfs(i,d);
        siz[d] += siz[i];
        wei[d] = std::max(wei[d],siz[i]);
    }
    wei[d] = std::max(wei[d],n - siz[d]);
    if(wei[d] <= n / 2)
        cen[cen[0] != 0] = d;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int u,v,i = 1;i < n;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    std::queue<int> q;
    memset(siz,0,sizeof(siz));
    if(cen[1] != 0) 
        cen[0] = std::min(cen[0],cen[1]);
    vis[cen[0]] = 1;
    for(q.push(cen[0]);!q.empty();q.pop()) {
        int u = q.front();
        for(auto v : g[u]) if(!vis[v]){
            ans += (vis[v] = 1) * (siz[v] = siz[u] + 1);
            q.push(v);
        }
    }
    std::cout << cen[0] << ' ' << ans << '\n';
    return 0;
}