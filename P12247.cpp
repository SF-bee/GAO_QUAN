#include <bits/stdc++.h>
using ll = long long;
const int MAX = 5e5 + 5;

int n,m,k;
ll l[MAX],r[MAX],w[MAX];
ll ans,g[MAX],f[MAX]; //f[i]表示最后一局游戏从i时刻开始的最大价值
std::vector<int> add[MAX],red[MAX];
struct node{
    int id,w;
    node(int _id,int _w) : id(_id),w(_w) {}
    bool operator < (const node &rhs) const
        {return w > rhs.w;}
};

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        std::cin >> l[i] >> r[i] >> w[i];
        if(r[i] - l[i] + 1 >= k){
            add[l[i]].push_back(i);
            red[r[i] - k + 2].push_back(i);
        }
    }
    std::set<node> que;
    for(int i = 1;i <= m - k + 1;i++){
        for(auto j : add[i]) que.insert(node(j,w[j]));
        for(auto j : red[i]) que.erase(node(j,w[j]));
        ll from = g[std::max(0,i - k)];
        if(!que.empty()) f[i] = from + (*que.begin()).w;
        g[i] = std::max(g[i - 1],f[i]);
        ans = std::max(ans,f[i]);
    }
    std::cout << ans << '\n';
    return 0;
}