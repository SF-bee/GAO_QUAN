#include <bits/stdc++.h>
const int MAX = 1e4 + 5;

int n,m,k;
int fa[MAX];
struct edge{
    int u,v,d;
    bool operator < (const edge &rhs) const{
        return d < rhs.d;
    }
}e[MAX];

int find(int x) {return fa[x] == x ? fa[x] : find(fa[x]);}
void merge(int x,int y) {fa[find(x)] = fa[find(y)];}

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
        fa[i] = i;
    for(int i = 1;i <= m;i++)
        std::cin >> e[i].u >> e[i].v >> e[i].d;
    
    int ans = 0,cnt = n;
    std::sort(e + 1,e + m + 1);
    for(int i = 1;i <= m && cnt > k;i++){
        auto [u,v,d] = e[i];
        if(find(u) != find(v)){
            ans += d;
            merge(u,v);
            cnt--;
        }
    }
    if(cnt != k)
        std::cout << "No Answer\n";
    else
        std::cout << ans << '\n';
    return 0;
}