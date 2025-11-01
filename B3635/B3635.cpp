#include <bits/stdc++.h>

int n;
int dp[1000005];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 1;
    dp[6] = 2;
    dp[7] = 3;
    dp[8] = 4;
    dp[9] = 5;
    dp[10] = 2;
    dp[11] = 1;
    for(int j = 12;j <= n;j++){
        dp[j] = std::min({dp[j - 1],dp[j - 5],dp[j - 11]}) + 1;
    }
    std::cout << dp[n];
    return 0;
}