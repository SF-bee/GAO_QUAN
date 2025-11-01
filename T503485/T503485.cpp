#include <bits/stdc++.h>
const int MAX = 1e5;

int n,s,ans = -MAX,dp[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        std::cin >> s;
        dp[i] = std::max(dp[i - 1] + s,s);
        ans = std::max(ans,dp[i]);
    }
    std::cout << ans;
    return 0;
}