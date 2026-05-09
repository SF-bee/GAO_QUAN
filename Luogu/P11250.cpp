#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e3 + 5;
const ll mod = 1e9 + 7;

ll t,n,m,k;
ll c[MAX][MAX];

ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    c[0][0] = 1;
    for(int i = 0;i < MAX;i++){
        for(int j = 0;j <= i;j++){
            if(j == 0) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
    std::cin >> t;
    while(t--){
        std::cin >> n >> m >> k;
        if(m - 2 * k > n - k) std::cout << 0 << '\n';
        else if(m < 2 * k) std::cout << 0 << '\n';
        else{
            std::cout << (c[n][k] * c[n - k][m - 2 * k] % mod) * qpow(2,m - 2 * k) % mod << '\n';
        }
    }
    return 0;
}