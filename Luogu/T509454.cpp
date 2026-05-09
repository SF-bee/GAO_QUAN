#include <bits/stdc++.h>
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

ll n,k;
ll sum,mx = 0;
std::array<ll,MAX> a,f;

ll qpow(ll a,ll b){
    ll res = 1;
    for(;b;b >>= 1){
        if(b & 1)
            res = (a * res) % MOD;
        a = (a * a) % MOD;
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    std::generate_n(a.begin() + 1,n,[](){ll x;std::cin >> x;sum = (sum + x) % MOD;return x;});
    for(int i = 1;i <= n;i++)  //求最大字段和
        f[i] = std::max(f[i - 1] + a[i],a[i]),mx = std::max(mx,f[i]);
    //因为这段是最大的，所以我们就重复加这段，加其他不会使答案更优
    sum = (sum + mx % MOD * (qpow(2,k) - 1)) % MOD;
    std::cout << sum << '\n';
    return 0;
}