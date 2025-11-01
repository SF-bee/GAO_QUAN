#include <bits/stdc++.h>

const int MAX = 205;
int n;
int a[MAX][MAX];
int dp[MAX];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)
            std::cin >> a[i][j];
    memset(dp,0x3f,sizeof(dp));
    dp[1] = 0;
    for(int i = 2;i <= n;i++){
        for(int j = 1;j < i;j++){
            dp[i] = std::min(dp[i],dp[j] + a[j][i]);
        }
    }
    std::cout << dp[n];
    return 0;
}