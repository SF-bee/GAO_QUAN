#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 3e3;

struct edge{
    ll u,v,w;
    bool operator<(const edge &rhs) const {
        return w > rhs.w;
    }
};
ll n, cnt, ans, a[MAX], pa[MAX];
std::vector<edge> e;
ll find(ll x){return (pa[x] == x ? x : find(pa[x]));}
void unite(ll x, ll y){pa[find(x)] = find(y);}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1; i <= n; i++){
        std::cin >> a[i];
        pa[i] = i;
        for(int j = i - 1; j >= 1; j--)
            e.push_back({i, j, a[i] ^ a[j]});
    }
    
    std::sort(e.begin(),e.end());
    for(auto [u,v,w] : e){
        if(find(u) != find(v)){
            unite(u, v);
            ans += w;
        }
    }
    std::cout << ans << '\n';
    return 0;
}