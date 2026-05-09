#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

int n,m;
struct edge{
    int u,v,w;
    bool operator<(const edge &b) const {
        return w < b.w;
    }
}e[MAX];
struct MGS{
    int fa[MAX];
    void init() {for(int i = 1;i <= n;i++) fa[i] = i;}
    int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
    void merge(int x,int y){fa[find(x)] = fa[find(y)];}
}mgs;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m;
    for(int i = 1;i <= m;i++)
        std::cin >> e[i].u >> e[i].v >> e[i].w;
    
    int ans = 0;
    mgs.init();
    std::sort(e + 1,e + m + 1);
    for(int i = 1;n > 1 && i <= m;i++){
        auto [u,v,w] = e[i];
        if(mgs.find(u) != mgs.find(v)){
            mgs.merge(u,v);
            ans += w;
            n--;
        }
    }
    if(n > 1) std::cout << "orz\n";
    else std::cout << ans << '\n';
    return 0;
}