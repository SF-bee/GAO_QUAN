#include <bits/stdc++.h>
const int MAX = 5e3 + 5;

int n,dp[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    std::memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        if(i - 3 >= 0)
            dp[i] = std::min(dp[i],dp[i - 3] + 1);
        if(i - 5 >= 0)
            dp[i] = std::min(dp[i],dp[i - 5] + 1);
    }
    std::cout << (dp[n] != 0x3f3f3f3f ? dp[n] : -1) << '\n';
    return 0;
}