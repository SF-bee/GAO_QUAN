#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 5e3 + 5;
const int MOD = 1e9 + 7;

ll n,a[MAX];
ll ans;

ll C(ll x){
    return (x * (x - 1) / 2) % MOD;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n;
    for(int i = 0;i < n;i++){
        ll x;
        std::cin >> x;
        a[x]++;
    }
    for(int i = 1;i <= 2500;i++){
        ans += C(a[i])*C(a[2 * i]) % MOD;
        ans %= MOD;
        for(int j = i + 1;i + j <= 5000;j++)
            ans += a[i] * a[j] % MOD * C(a[i + j]) % MOD;
    }
    std::cout << ans << '\n';
    return 0;
}