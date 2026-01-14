#include <bits/stdc++.h>
using ll = long long;
const int MAX = 100;

int n,c;
ll a[MAX];

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> c;
    for(int i = 1;i <= n;i++){
        std::cin >> a[i];
        if(a[i] > c) n = i - 1; 
    }
    
    ll ans = 0;
    auto dfs = [&](auto &self,int d,ll sum) ->void {
        ans = std::max(ans,sum);
        if(a[d] + sum <= c)
            self(self,d - 1,sum + a[d]);
    };
    dfs(dfs,n,0);
    std::cout << ans << '\n';
    return 0;
}