#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 3e5 + 5;

int n,c;
ll sum,a[MAX],dp[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> c;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],sum += a[i];
    if(c > 0){
        ll res = -1e18;
        for(int i = 1;i <= n;i++)
            dp[i] = std::max(dp[i - 1] + a[i],a[i]),
            res = std::max(res,dp[i]);
        std::cout << std::max(sum,sum - res + res * c) << '\n';
    }
    else{
        ll res = 1e18;
        for(int i = 1;i <= n;i++)
            dp[i] = std::min(dp[i - 1] + a[i],a[i]),
            res = std::min(res,dp[i]);
        std::cout << std::max(sum,sum - res + res * c) << '\n';
    }
    return 0;
}