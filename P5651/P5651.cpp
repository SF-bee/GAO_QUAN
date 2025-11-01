#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,m,q,dis[MAX];
bool vis[MAX];
std::vector<std::pair<int,int> > g[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> q;
    for(int u,v,w; m; m--){
        std::cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    std::queue<int> que;
    que.push(1);
    for(int u;!que.empty();que.pop()){
        if(vis[u = que.front()]) continue;
        vis[u] = 1;
        for(auto [v,w] : g[u]) if(!vis[v]){
            dis[v] = dis[u] ^ w;
            que.push(v);
        }
    }
    while(q--){
        int x,y;
        std::cin >> x >> y;
        std::cout << (dis[x] ^ dis[y]) << '\n';
    }
    return 0;
}