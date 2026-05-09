#include <bits/stdc++.h>
const int MAX = 1e3 + 5;

int n, m;
std::vector<std::pair<int,int> > g1[MAX], g2[MAX];
std::priority_queue<std::pair<int,int>> q;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u,v,d;
        std::cin >> u >> v >> d;
        //正向反向分别建边
        g1[u].push_back({v,d});
        g2[v].push_back({u,d});
    }
    std::vector<int> dis1(n + 1,1e9);  //去的最短路
    std::vector<int> dis2(n + 1,1e9);  //回的最短路
    for(q.push({dis1[1] = 0,1}); !q.empty(); q.pop()) if(dis1[q.top().second] == -q.top().first){
        auto[d,u] = q.top();
        for(auto [to,d] : g1[u]) if(dis1[to] > dis1[u] + d) {
            q.push({-(dis1[to] = dis1[u] + d),to});
        }
    }
    for(;!q.empty();q.pop());  //清空
    for(q.push({dis2[1] = 0,1}); !q.empty(); q.pop()) if(dis2[q.top().second] == -q.top().first){
        auto[d,u] = q.top();
        for(auto [to,d] : g2[u]) if(dis2[to] > dis2[u] + d) {
            q.push({-(dis2[to] = dis2[u] + d),to});
        }
    }
    int sum = 0;
    for(int i = 2;i <= n;i++) sum += dis1[i] + dis2[i];
    std::cout << sum << '\n';
    return 0;
}
// #include <queue>
// #include <vector>
// #include <utility>
// #include <iostream>

// const int maxn = 100005;

// std::vector<std::pair<int, int>> e[maxn];
// bool vis[maxn];

// int n, m, s;
// int main() {
//   std::cin >> n >> m >> s;
//   for (int u, v, w; m; --m) {
//     std::cin >> u >> v >> w;
//     e[u].push_back({v, w});
//   }
//   std::priority_queue<std::pair<int, int>> Q;
//   std::vector<int> dist(n + 1, 2147483647);
//   Q.push({dist[s] = 0ll, s});
//   for (int u; !Q.empty(); Q.pop()) {
//     if (vis[u = Q.top().second]) continue;
//     vis[Q.top().second] = 1;
//     for (auto [vv, ww] : e[u]) if (dist[vv] > dist[u] + ww) {
//       Q.push({-(dist[vv] = dist[u] + ww), vv});
//     }
//   }
//   for (int i = 1; i <= n; ++i) std::cout << dist[i]  << " \n"[i == n];
// }