#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e2 + 5;

struct edge{
    ll u,v,w;
    bool operator<(const edge &rhs) const {return w < rhs.w;}
};
ll n,ans,pa[MAX];
std::vector<edge> e;

ll find(ll x){return (pa[x] == x ? x : find(pa[x]));}
void unite(ll x,ll y){pa[find(x)] = find(y);}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++) pa[i] = i;
    for(ll i = 1;i <= n;i++)
        for(ll w,j = 1;j <= n;j++){
            std::cin >> w;
            e.push_back({i,j,w});
        }
    ll cnt = 0;
    std::sort(e.begin(),e.end());
    for(int i = 0;i < e.size() && cnt != n - 1;i++){
        auto [u,v,w] = e[i];
        if(find(u) != find(v)){
            unite(u,v);
            ans += w,cnt++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}