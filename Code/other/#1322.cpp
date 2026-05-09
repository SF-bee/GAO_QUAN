#include <bits/stdc++.h>
#define int long long
const int MAX = 1e5 + 5;

int n,a[MAX];

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];

    auto check = [&](int x)
    {
        int up = a[1] + x,low = a[1] - x;
        for(int i = 2;i <= n;i++){
            int _l = a[i] - x,_r = a[i] + x;
            int nlow = std::max(low,_l);
            int nup = std::min(up,_r);
            if(nlow > nup) return false;
            else low = nlow,up = nup;
        }
        return true;
    };
    int l = 0;
    int r = (*std::max_element(a + 1,a + n + 1) - *std::min_element(a + 1,a + n + 1)) * 2;
    int ans = 0;
    for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
        if(check(mid))
            ans = mid,r = mid - 1;
        else l = mid + 1;
    }
    std::cout << ans << '\n';
    return 0;
}