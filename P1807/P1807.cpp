#include <bits/stdc++.h>

struct node{
    long long to,dis;
    bool operator < (const node &rhs) const{return dis < rhs.dis;}
};

const int MAX = 2000;
int n,m;
std::array<long long,MAX> dis;
std::vector<node> e[MAX];
std::priority_queue<node> q;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 0;i < m;i++){
        int u,v,w;
        std::cin >> u >> v >> w;
        e[u].push_back({v,w});
    }

    dis.fill(-LONG_LONG_MAX);
    dis[1] = 0;
    q.push({1,0});
    while(!q.empty()){
        auto[u,d] = q.top();q.pop();
        for(auto v : e[u]){
            auto [to,d] = v;
            if(dis[to] < dis[u] + d){
                dis[to] = dis[u] + d;q.push({to,dis[to]});
            }
        }
    }

    std::cout << (dis[n] != 0 ? dis[n] : -1);
    return 0;
}