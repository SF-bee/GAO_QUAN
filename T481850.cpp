#include <bits/stdc++.h>
typedef long long ll;

const int MAX = 1e5 + 5;
int m,n;
ll ans = 0;
std::array<ll,MAX> a,b;

inline ll rd(){ll x;std::cin >> x;return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> m >> n;
    std::generate_n(a.begin(),m,rd);
    std::generate_n(b.begin(),n,rd);

    std::sort(a.begin(),a.begin() + m);
    for(int i = 0;i < n;i++){
        auto t = std::lower_bound(a.begin(),a.begin() + m,b[i]);
        ll cnt = LONG_LONG_MAX;
        if(t != a.begin() + m) cnt = std::min(cnt,abs(b[i] - *t));
        if(t != a.begin()) cnt = std::min(cnt,abs(b[i] - *(t - 1)));
        ans += cnt;
    }
    std::cout << ans;
    return 0;
}