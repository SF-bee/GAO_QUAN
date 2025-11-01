#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 3e6 + 5;

ll n,m,ans,a[MAX],s,tot;
struct edge{
    ll u,v,w;
    bool operator < (const edge &rhs) const{
        return w < rhs.w;
    }
}e[MAX];
struct mg{
    ll fa[MAX],siz[MAX];
    int find(int x){
        return (fa[x] == x ? x : find(fa[x]));
    }
    void merge(int x,int y){
        int fx = find(x),fy = find(y);
        if(siz[fx] < siz[fy]) std::swap(fx,fy);
        fa[fy] = fx,siz[fx] += siz[fy];
    }
}mgt;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> s;
    for(int i = 1;i <= n + s;i++) mgt.fa[i] = i,mgt.siz[i] = 1;
    for(int u,v,w,i = 1;i <= m;i++){
        std::cin >> u >> v >> w;
        e[++tot] = {u,v,w};
    }
    for(int p,i = 1;i <= s;i++){
        ll pos = n + i;
        std::cin >> p;
        ll mina = INT_MAX,minb = 0;
        for(int j = 1;j <= p;j++)
            std::cin >> a[j];
        for(int w,j = 1;j <= p;j++){
            std::cin >> w;
            e[++tot] = {a[j],pos,w};
            if(w < mina) mina = w,minb = a[j];
        }
        mgt.merge(minb,pos);
        ans += mina;
    }
    std::sort(e + 1,e + tot + 1);
    n += s;
    for(int i = 1;i <= tot && n > 1;i++){
        auto [u,v,w] = e[i];
        if(mgt.find(u) != mgt.find(v)){
            mgt.merge(u,v);
            ans += w;
            n--;
        }
    }
    std::cout << ans << '\n';
    return 0;
}