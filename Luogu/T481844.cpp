#include <bits/stdc++.h>
typedef long long ll;

const int MAX = 1e6 + 5;
ll n,k,ans;
std::array<ll,MAX> a;

bool check(ll _mid){
    ll pre = 1;
    for(int i = 0;i < k;i++){
        ll res = _mid;
        if(pre < a[i]){
            ll t = (a[i] - pre) * 2;
            if(t > _mid) return false;
            res -= t;
        }
        pre = a[i] + (res >> 1) + 1;
    }
    return pre >= n + 1;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    std::generate_n(a.begin(),k,[](){ll x;std::cin >> x;return x;});
    
    std::sort(a.begin(),a.begin() + k);
    for(ll l = 1,r = n << 1,mid;l <= r;){
        mid = (l + r) >> 1;
        if(check(mid)) r = (ans = mid) - 1;
        else l = mid + 1;
    }
    std::cout << ans;
    return 0;
}