#include <bits/stdc++.h>
const int MAX = 2e3 + 5;
const int INF = 0x3f3f3f3f;

struct edge{
    int u,v,w;
};
int n,m,vis[MAX],dis[MAX];
std::vector<int> g[MAX];
std::vector<std::pair<int,int> > ans;
std::vector<edge> eg;

bool dfs(int u){
    if(u == n) return true;
    bool flag = 0;
    for(auto v : g[u]) if(!vis[v]){
        vis[v] = 1;
        if(dfs(v)) {
            eg.push_back({u,v,9}),eg.push_back({v,u,-1});
            flag = 1;
        }
        vis[v] = 0;
    }
    return flag;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    std::memset(dis,0x3f,sizeof(dis));

    std::cin >> n >> m;
    for(int u,v,i = 1;i <= m;i++){
        std::cin >> u >> v;
        g[u].push_back(v);
        ans.push_back({u,v});
    }
    dfs(1);
    if(!vis[n]){
        std::cout << -1 << '\n';
        return 0;
    }
    dis[1] = 0;
    bool flag = 0;
    for(int i = 1;i <= n + 1;i++){
        flag = 0;
        for(auto [u,v,w] : eg){
            // std::cout << u << ' ' << v << ' ' << w << '\n';
            if(dis[u] == INF) continue;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                flag = 1;
            }
        }
        if(!flag) break;
    }
    if(flag){
        std::cout << -1;
        return 0;
    }

    std::cout << n << ' ' << m << '\n';
    for(auto [u,v] : ans){
        if(dis[v] == INF || dis[u] == INF) std::cout << u << ' ' << v << ' ' << 114514 << '\n';
        std::cout << u << ' ' << v << ' ' << dis[v] - dis[u] << '\n';
    }
    return 0;
}