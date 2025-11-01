#include <bits/stdc++.h>

const int MAX = 20005;
int n;
int l[MAX],r[MAX];
int dp[MAX][2];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> l[i] >> r[i];
    dp[1][0] = r[1] + r[1] - l[1] - 1;
    dp[1][1] = r[1] - 1;
    for(int i = 2;i <= n;i++){
        dp[i][0] = std::min(dp[i - 1][0] + abs(l[i - 1] - r[i]),dp[i - 1][1] + abs(r[i - 1] - r[i])) + r[i] - l[i] + 1;
        dp[i][1] = std::min(dp[i - 1][0] + abs(l[i - 1] - l[i]),dp[i - 1][1] + abs(r[i - 1] - l[i])) + r[i] - l[i] + 1;
    }
    std::cout << std::min(dp[n][0] + n - l[n],dp[n][1] + n - r[n]);
    return 0;
}