#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1005;

int n,c;
ll a[MAX],pre[MAX];

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> c;
    for(int i = 1;i <= n;i++){
        std::cin >> a[i];
        if(a[i] > c){
            n = i - 1;
            break; 
        }
        pre[i] = pre[i - 1] + a[i];
    }
    
    ll ans = 0;
    auto dfs = [&](auto &self,int d,ll sum) ->void {
        if(sum + pre[d] <= ans) return;
        ans = std::max(ans,sum);
        for(int i = d;i;i--)
            if(a[i] + sum <= c)
                self(self,i - 1,sum + a[i]);
    };
    dfs(dfs,n,0);
    std::cout << ans << '\n';
    return 0;
}