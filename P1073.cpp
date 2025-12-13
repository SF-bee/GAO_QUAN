#include <bits/stdc++.h>
const int N = 1e5 + 5;

int n,m,a[N];
std::vector<std::tuple<int,int,int> > g[3][N];
bool vis[3][N];
int dis[3][N];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::memset(dis,0xf3,sizeof(dis));
    std::cin >> n >> m;
    for(int i = 1;i <= n;i++){
        std::cin >> a[i];
        g[0][i].push_back({-a[i],1,i});
        g[1][i].push_back({+a[i],2,i});
    }
    for(int u,v,z,i = 1;i <= m;i++){
        std::cin >> u >> v >> z;
        g[0][u].push_back({0,0,v});
        g[1][u].push_back({0,1,v});
        g[2][u].push_back({0,2,v});
        if(z == 2){
            g[0][v].push_back({0,0,u});
            g[1][v].push_back({0,1,u});
            g[2][v].push_back({0,2,u});
        }
    }

    std::queue<std::pair<int,int> > que;
    que.push({0,1});
    dis[0][1] = 0;
    while(!que.empty()){
        auto [lay,u] = que.front();
        que.pop(),vis[lay][u] = 0;
        for(auto [d,f,v] : g[lay][u]) if(dis[f][v] < dis[lay][u] + d){
            dis[f][v] = dis[lay][u] + d;
            if(!vis[f][v]) que.push({f,v}),vis[f][v] = 1;
        }
    }
    std::cout << dis[2][n] << '\n';
    return 0;
}