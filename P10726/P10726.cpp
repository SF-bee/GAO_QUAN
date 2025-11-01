#include <bits/stdc++.h>
const int MAX = 1e3 + 5;

struct board{
    int l,r,h;
};
struct node{
    int to,dis;
    bool operator< (const node &rhs) const{
        return dis > rhs.dis;
    }
};

inline board rd(){board x; std::cin >> x.l >> x.r >> x.h; return x;}

int n,s,t;
std::array<board,MAX> a;
std::array<int,MAX> dis;
std::array<bool,MAX> vis;  //记录节点是否抵达过
std::vector<node> g[MAX];  //g是邻接表，存储左右两边的顶点和边权
std::pair<int,int> down[MAX];  //0存左边的落点，1存右边落点

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> s >> t;
    std::generate_n(a.begin() + 1,n,rd);
    
    //存储每块板子往左右两边会掉到哪块板子
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(a[j].h < a[i].h){
                down[i].first = (a[j].l <= a[i].l && a[i].l <= a[j].r && a[j].h > a[down[i].first].h ? 
                            j : down[i].first);  //左边落点
                down[i].second = (a[j].l <= a[i].r && a[i].r <= a[j].r && a[j].h > a[down[i].second].h ? 
                            j : down[i].second);  //右边落点
            }
            
        }
    }
    // 建图，边权为落点到左右两边的距离
    for(int i = 1;i <= n;i++){
        //左边挡板的边权
        if(down[i].first != 0){
            g[down[i].first].push_back({down[down[i].first].first,a[i].l - a[down[i].first].l});
            g[down[i].first].push_back({down[down[i].first].second,a[down[i].first].r -  a[i].l});
        }
        //右边挡板的边权
        if(down[i].second != 0){
            g[down[i].second].push_back({down[down[i].second].first,a[i].r - a[down[i].second].l});
            g[down[i].second].push_back({down[down[i].second].second,a[down[i].second].r -  a[i].r});
        }
    }
    //Dijkstra
    g[s].clear();
    g[s].push_back({down[s].first,0});
    g[s].push_back({down[s].second,a[s].r - a[s].l});
    dis.fill(INT_MAX);
    dis[s] = 0;
    std::priority_queue<node> que;
    que.push({s,0});
    while(!que.empty()){
        auto [u,d] = que.top();que.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto v : g[u]){
            auto [to,d] = v;
            if(to != 0 && dis[to] > dis[u] + d){
                dis[to] = dis[u] + d;
                que.push({to,dis[to]});
            }
        }
    }
    std::cout << (dis[t] != INT_MAX ? dis[t] + a[s].h - a[t].h : -1);//完结撒花
    return 0;
}
/*
sudo apt upgrade gcc
*/