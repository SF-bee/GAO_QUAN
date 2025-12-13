#include <bits/stdc++.h>
const int MAX = 5e4 + 5;

struct edge{
    int nxt,to,dis;
    bool operator < (const edge &rhs) const{
        return dis > rhs.dis;
    }
};
int n,m,k,s,t;
int vis[11][MAX],dis[11][MAX];
std::vector<edge> g[11][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::memset(dis,0x3f,sizeof(dis));
    std::cin >> n >> m >> k >> s >> t;
    for(int u,v,w,i = 1;i <= m;i++){
        std::cin >> u >> v >> w;
        for(int j = 0;j < k;j++){
            g[j][u].push_back({j,v,w});
            g[j][v].push_back({j,u,w});
            g[j][u].push_back({j + 1,v,0});
            g[j][v].push_back({j + 1,u,0});
        }
        g[k][u].push_back({k,v,w});
        g[k][v].push_back({k,u,w});
    }
    for(int j = 1;j <= k;j++)
        g[j - 1][t].push_back({j,t,0});
    std::priority_queue<edge> q;
    q.push({0,s,0});
    dis[0][s] = 0;
    for(int nxt,u;!q.empty();){
        nxt = q.top().nxt,u = q.top().to,q.pop();
        if(vis[nxt][u]) continue;
        vis[nxt][u] = 1;
        for(auto [nt,to,ds] : g[nxt][u]) if(dis[nt][to] > dis[nxt][u] + ds){
            q.push({nt,to,dis[nt][to] = dis[nxt][u] + ds});
        }
    }
    std::cout << dis[k][t] << '\n';
    return 0;
}