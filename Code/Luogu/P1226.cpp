#include <bits/stdc++.h>
typedef long long ll;

ll qpow(ll a,ll b,ll p){
    ll x = 1;
    while(b){
        if(b & 1)
            x = a * x % p;
        a = a * a % p;
        b >>= 1;
    }
    return x;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    ll a,b,p;
    std::cin >> a >> b >> p;
    std::cout << a << '^' << b << " mod " << p << '=' <<qpow(a,b,p);
    return 0;
}