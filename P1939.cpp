#include <bits/stdc++.h>
using ll = long long;
const ll mod = 1e9 + 7;

std::vector<std::vector<ll> > operator * (const std::vector<std::vector<ll> > &a,const std::vector<std::vector<ll> > &b){
    std::vector<std::vector<ll> > c(3,std::vector<ll>(3));
    for(int i = 0;i < 3;i++)
        for(int l = 0;l < 3;l++)
            for(int j = 0;j < 3;j++)
                c[i][j] = (c[i][j] + a[i][l] * b[l][j]) % mod;
    return c;
}
std::vector<std::vector<ll> > qpow(std::vector<std::vector<ll> > x,ll k){
    std::vector<std::vector<ll> > res(x.size(),std::vector<ll>(x.size()));
    for(int i = 0;i < res.size();i++)
        res[i][i] = 1;
    while (k){
        if(k & 1) res = res * x;
        x = x * x;
        k >>= 1;
    }
    return res;
    
}

int main(){
    freopen("P1939.in","r",stdin);
    freopen("P1939.out","w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::vector<std::vector<ll> > base(3,std::vector<ll>(3));
    base[0] = {1,0,1};
    base[1] = {1,0,0};
    base[2] = {0,1,0};

    ll T,n;
    std::cin >> T;
    while(T--){
        std::cin >> n;
        std::vector<std::vector<ll> > d(3,std::vector<ll>(3));
        if(n <= 3) std::cout << 1 << '\n';
        else{
            d = qpow(base,n - 3);
            std::cout << (d[0][0] + d[0][1] + d[0][2]) % mod << '\n';
        }
        
    }
    return 0;
}