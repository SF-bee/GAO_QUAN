#include <bits/stdc++.h>
const int MAX = 2e3 + 5;

int n,m,k;
int vis[MAX][MAX],dis[MAX][MAX];
std::vector<std::tuple<int,int,int> > g[MAX][MAX]; //g[k][i]存储第k层i的出边

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::memset(dis,0x3f,sizeof(dis));
    std::cin >> n >> m >> k;
    for(int u,v,w,i = 1;i <= m;i++){
        std::cin >> u >> v >> w;
        g[0][u].push_back({0,v,w});
        g[0][v].push_back({0,u,w});
        for(int j = 1;j <= k;j++){
            g[j][u].push_back({j,v,w});
            g[j][v].push_back({j,u,w});
            g[j - 1][u].push_back({j,v,w >> 1});
            g[j - 1][v].push_back({j,u,w >> 1});
        }
    }
    // for(int i = 1;i <= n;i++){
    //     for(auto [a,b,c] : g[0][i])
    //         std::cout << '[' <<b << ',' << c << ']' << ' ';
    //     std::cout << '\n';
    // }
    for(int i = 1;i <= k;i++)
        g[i - 1][n].push_back({i,n,0});
    std::priority_queue<std::tuple<int,int,int> > que;
    que.push({dis[0][1] = 0,1,0});
    for(;!que.empty();){
        auto [ds,u,f] = que.top(); que.pop();
        if(vis[f][u]) continue;
        vis[f][u] = 1;
        // if(f == 1) std::cout << dis[f][u] << ' ';
        for(auto [fl,v,di] : g[f][u]) if(dis[fl][v] > dis[f][u] + di)
            que.push({-(dis[fl][v] = dis[f][u] + di),v,fl});
    }
    // for(int i = 0;i <= k;i++){
    //     for(int j = 1;j <= n;j++){
    //         std::cout << dis[i][j] << " \n"[j == n];
    //     }
    // }
    std::cout << dis[k][n] << '\n';
    return 0;
}