#include <bits/stdc++.h>
typedef long long ll;

ll xl,xr,yl,yr;


int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> xl >> xr >> yl >> yr;
    ll a = std::min(xl * yr,xr * yl);
    ll b = std::max(xr * yr,xl * yl);
    std::cout << (a < 1ll * -INT_MAX - 1 || b > 1ll * INT_MAX ? "long long int\n" : "int");
    return 0;
}