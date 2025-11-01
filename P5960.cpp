#include <bits/stdc++.h>
const int MAX = 5e3 + 5;
const int INF = 0x3f3f3f3f;

struct edge {int u,v,w;};
int n,m,dis[MAX];
std::vector<edge> eg;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::memset(dis,0x3f,sizeof(dis));
    std::cin >> n >> m;
    for(int v,u,w,i = 1;i <= m;i++){
        std::cin >> v >> u >> w;
        eg.push_back({u,v,w});
    }
    for(int i = 1;i <= n;i++) eg.push_back({0,i,0});
    bool flag = 0;
    dis[0] = 0;
    for(int i = 1;i <= n + 1;i++){
        flag = 0;
        for(auto [u,v,w] : eg){
            if(dis[u] == INF) continue;
            if(dis[v] > w + dis[u]){
                dis[v] = dis[u] + w;
                flag = 1;
            }
        }
        if(!flag) break;
    }
    if(flag) std::cout << "NO\n";
    else{
        for(int i = 1;i <= n;i++)
            std::cout << dis[i] << " \n"[i == n];
    }
    return 0;
}