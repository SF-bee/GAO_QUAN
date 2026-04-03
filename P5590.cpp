#include <bits/stdc++.h>
const int MAX = 2e3 + 5;
const int INF = 0x3f3f3f3f;

int n,m;
std::pair<int,int> edg[MAX];
bool from[MAX],infr[MAX]; //存储某一个点是否 “有效”
bool vis[MAX];
struct edge {
    int to,dis;
};
std::vector<int> g0[MAX];
std::vector<edge> g[MAX];
int dis[MAX];

void init() {
    for(int i = 1;i <= n;i++) g0[i].clear();
    for(int i = 1;i <= m;i++) g0[edg[i].second].emplace_back(edg[i].first);
}

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        std::cin >> edg[i].first >> edg[i].second;
        g0[edg[i].first].emplace_back(edg[i].second);
    }   
        
    auto bfs = [&](int d,int beg) {
        bool *vi = (beg == 1 ? from : infr);
        std::queue<int> q;
        for(q.push(beg);!q.empty();q.pop()) {
            int u = q.front();
            if(vi[u]) continue;
            vi[u] = 1;
            for(auto v : g0[u]) if(!vi[v])
                q.push(v);
        }
    };

    bfs(1,1);
    if(!from[n]) {
        std::cout << -1 << '\n';
        return 0;
    }
    init();
    bfs(n,n);
    for(int i = 1;i <= m;i++) {
        auto [u,v] = edg[i];
        if(from[u] && infr[u] && from[v] && infr[v])
            g[u].push_back({v,9}),
            g[v].push_back({u,-1});
    }
    for(int i = 1;i <= n;i++)
        g[0].push_back({i,0});

    auto bmf = [&]() -> bool {
        std::memset(dis,0x3f,sizeof(dis));
        dis[0] = 0;
        for(int i = 0;i <= n;i++) {
            bool jud = false;
            for(auto u = 0;u <= n;u++)
                for(auto [v,d] : g[u])
                    if(dis[v] > dis[u] + d)
                        dis[v] = dis[u] + d, jud = true;
            if(jud && i == n) return false;
            if(!jud) return true;
        }
        return true;
    };
    if(!bmf()) {
        std::cout << -1;
        return 0;
    }
    std::cout << n << ' ' << m << '\n';
    for(int i = 1; i <= m; i++) {
        auto [u, v] = edg[i];
        if(from[u] && infr[u] && from[v] && infr[v])
            std::cout << u << ' ' << v << ' ' << dis[v] - dis[u] << '\n';
        else 
            std::cout << u << ' ' << v << ' ' << 1 << '\n';
    }
    return 0;
}