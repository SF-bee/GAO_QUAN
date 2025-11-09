#include <bits/stdc++.h>
using ll = long long;
const int MAX = 8e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int T,las;
int n,m,q,k,s;
struct EDGE{ //边
    int u,v;
    ll l,a;
    bool operator < (const EDGE &rhs) const {return a > rhs.a;}
}e[MAX];
int cnt;
ll val[MAX]; //重构树点权
std::vector<int> ga[MAX]; //重构树
struct MGS{ //并查集
    int fa[MAX];
    void init(){
        for(int i = 1;i <= 2 * n + 1;i++)
            fa[i] = i;
    }
    int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
    void merge(EDGE e){
        auto [x,y,l,a] = e;
        int fx = find(x),fy = find(y);
        val[++cnt] = a;
        ga[cnt].emplace_back(fx);
        ga[cnt].emplace_back(fy);
        fa[fx] = fa[fy] = cnt;
    }
}mgs;
std::vector<std::pair<ll,int>> g[MAX]; //原图
bool vis[MAX];
int fa[22][MAX];
ll dis[MAX],mdis[MAX];

void solve(){
    std::memset(val,0,sizeof(val));
    std::memset(dis,0x3f,sizeof(dis));
    std::memset(mdis,0x3f,sizeof(mdis));
    std::memset(vis,0,sizeof(vis));
    std::cin >> n >> m;
    mgs.init();
    for(int i = 1;i <= m;i++){
        std::cin >> e[i].u >> e[i].v >> e[i].l >> e[i].a;
        g[e[i].u].emplace_back(e[i].l,e[i].v);
        g[e[i].v].emplace_back(e[i].l,e[i].u);
    }
    //重构树
    std::sort(e + 1,e + m + 1);
    cnt = n;
    for(int pe = n,i = 1;i <= m && pe > 1;i++)
        if(mgs.find(e[i].u) != mgs.find(e[i].v)){
            mgs.merge(e[i]);
            pe--;
    }
    //最短路
    std::priority_queue<std::pair<ll,int>,
      std::vector<std::pair<ll,int> >,std::greater<std::pair<ll,int> > > que;
    for(que.push({dis[1] = 0,1});!que.empty();){
        auto [ds,u] = que.top(); que.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto [d,v] : g[u]) if(dis[v] > dis[u] + d)
            que.push({dis[v] = dis[u] + d,v});
    }
    //预处理子树最短距离
    std::memset(mdis,0x3f,sizeof(mdis));
    for(int i = 1;i <= n;i++) mdis[i] = dis[i];
    
    auto prep = [&](auto &dfs,int u,int f) -> void
    {
        fa[0][u] = f;
        for(auto v : ga[u]){
            dfs(dfs,v,u);
            mdis[u] = std::min(mdis[u],mdis[v]);
        }
    };
    prep(prep,cnt,cnt);
    for(int k = 1;k <= 21;k++)
        for(int i = 1;i <= cnt;i++)
            fa[k][i] = fa[k - 1][fa[k - 1][i]];
    auto query = [&](int u,ll p)
    {
        for(int k = 21;k >= 0;k--)
            if(fa[k][u] != 0 && val[fa[k][u]] > p)
                u = fa[k][u];
        return u;
    };
    las = 0;
    std::cin >> q >> k >> s;
    while(q--){
        int u0; ll p0;
        std::cin >> u0 >> p0;
        int u = (u0 + k * las - 1) % n + 1;
        int p = (p0 + k * las) % (s + 1); 
        las = mdis[query(u,p)];
        std::cout << las << '\n';
    }
    for(int i = 1;i <= n;i++)
        g[i].clear();
    for(int i = 1;i <= cnt;i++)
        ga[i].clear();
}

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> T;
    while(T--)
        solve();
    return 0;
}