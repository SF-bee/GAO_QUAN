#include <bits/stdc++.h>
#define int long long
const int MAX = 1e3 + 5;

int d,p,c,f,s,dis[MAX],cnt[MAX];
std::vector<std::pair<int,int>> g[MAX];
bool vis[MAX];

signed main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::memset(dis,0,sizeof(dis));
    std::cin >> d >> p >> c >> f >> s;
    for(int u,v,i = 1;i <= p;i++)
        std::cin >> u >> v,
        g[u].push_back({d,v});
    for(int u,v,t,i = 1;i <= f;i++)
        std::cin >> u >> v >> t,
        g[u].push_back({d - t,v});
    
    auto spfa = [&]() -> bool
    {
        dis[s] = d,vis[s] = 1;
        std::queue<int> que;
        for(que.push(s);!que.empty();){
            int u = que.front();
            que.pop(),vis[u] = 0;
            for(auto [ds,v] : g[u]) if(dis[v] < dis[u] + ds){
                dis[v] = dis[u] + ds;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] > c) return 0;
                if(!vis[v]) que.push(v),vis[v] = 1;
            }
        }
        return 1;
    };
    if(!spfa())
        std::cout << -1 << '\n';
    else
        std::cout << *std::max_element(dis + 1,dis + c + 1) << '\n';
    return 0;
}