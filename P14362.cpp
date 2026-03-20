/*
注意到如果一个村庄必须被选择，那边它必须被接入图中。
为了最小化开销，我们应该使用最小的一个边来接入图
不对不对，我们不应该加入村庄，我们应该把村庄当成生成树的一部分
*/
#include <bits/stdc++.h>
using ll = long long;
const int N = 1e4 + 50;
const int M = 1e6 + 5;
const int K = 15;

struct edge {
    ll u,v,w,vil; //vil表示村庄编号，0表示是城市
    bool operator < (const edge &rhs) const {
        return w < rhs.w;
    }
}e[M];
int n,m,k;
ll c[K],a[K][N];
ll ans,e_ans;
struct MGset {
    int fa[N];
    void init() {
        for(int i = 1;i <= n + k;i++)
            fa[i] = i;
    }
    int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
    void merge(int x,int y) {fa[find(x)] = fa[find(y)];}
}mgs;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);
    
    std::cin >> n >> m >> k;
    mgs.init();
    for(int i = 1;i <= m;i++){
        std::cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].vil = 0;
    }
    std::vector<edge> road;
    for(int i = 1;i <= k;i++) {
        std::cin >> c[i];
        for(int j = 1;j <= n;j++) {
            std::cin >> a[i][j];
            road.push_back({n + i,j,a[i][j],i});
        }
    }
    std::sort(e + 1,e + m + 1);
    for(int i = 1,cnt = 0;i <= m && cnt < n;i++) {
        auto [u,v,w,vil] = e[i];
        if(mgs.find(u) != mgs.find(v)) {
            mgs.merge(u,v);
            ans += w;
            road.push_back(e[i]);
            cnt++;
        }
    }
    std::sort(road.begin(),road.end());
    for(int i = (1 << k) - 1;i;i--) {
        ll oth = 0;
        int vi = 0;
        for(int j = 1;j <= k;j++)
            if((1 << (j - 1)) & i)
                oth += c[j],vi++;
        mgs.init();
        for(int j = 0,cnt = 0;j < road.size() && cnt < n + vi;j++) {
            auto [u,v,w,vil] = road[j];
            if(mgs.find(u) != mgs.find(v)) {
                if(!vil || (1 << (vil - 1)) & i) {
                    mgs.merge(u,v);
                    oth += w;
                    cnt++;
                } 
            }
        }
        ans = std::min(ans,oth);
    }
    std::cout << ans << '\n';
    return 0;
}