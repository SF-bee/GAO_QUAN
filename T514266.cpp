#include <bits/stdc++.h>
typedef long long lint;
const int MAX = 1e7;
const lint MOD = 998244353;

lint k;

lint qpow(lint a,lint b){
    lint res = 1;
    for(;b > 0;b >>= 1) {
        if(b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> k;
    std::cout << qpow(2,k - 1) << '\n';
    return 0;
}