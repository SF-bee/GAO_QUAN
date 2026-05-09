#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 998244353;

ll n;

ll qpow(ll a,ll b){
    ll res = 1;
    for(;b;b >>= 1){
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    std::cout << 26 * qpow(25,n - 1) % mod << '\n';
    return 0;
}