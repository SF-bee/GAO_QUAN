#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e3;

struct node{
    int fa[MAX];
    node(){
        for(int i = 1;i < MAX;i++)
            fa[i] = i;
    }
    int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
    void merge(int x,int y){fa[find(x)] = find(y);}
}fa;
struct graph{
    ll u,v,w;
    bool operator< (const graph &rhs) const{
        return w < rhs.w;
    }
};

ll n,m,cnt,ans;
ll c[MAX];
std::priority_queue<graph> e;

ll qpow(ll a,ll b){
    ll x = 1;
    for(;b;b >>= 1){
        if(b & 1)
            x = a * x % m;
        a = a * a % m;
    }
    return x;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> c[i];
    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)
            e.push({i,j,(qpow(c[i],c[j]) + qpow(c[j],c[i])) % m}),cnt++;
    
    for(int i = 1;i <= cnt && n > 1;i++){
        auto [u,v,w] = e.top();e.pop();
        if(fa.find(u) != fa.find(v))
            fa.merge(u,v),
            ans += w,
            n--;
    }

    std::cout << ans << '\n';
    return 0;
}