#include <bits/stdc++.h>
typedef long long ll;

int qpow(int h){
    int res = 1,x = 2;
    while(h){
        if(h & 1) res *= x;
        x *= x;
        h >>= 1;
    }
    return res;
}
int T;
ll x,y,h;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        std::cin >> x >> y >> h;
        ll z = 0;
        for(int i = h - 1;i >= 0;i--){
            ll now = z | (1 << i);
            if((x ^ z) * (y ^ z) < (x ^ now) * (y ^ now))
                z |= (1 << i);
        }
        std::cout << (x ^ z) * (y ^ z) << '\n';
    }
    return 0;
}