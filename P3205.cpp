#include <bits/stdc++.h>
typedef long long ll;
const int mod = 19650827;
const int MAX = 1e3 + 5;

int n;
ll a[MAX],dp[MAX][MAX][2]; //dp[l][r][0/1]代表区间 l~r 最后一个元素从左/右添加的方案数

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],dp[i][i][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int l = 1;l <= n - i;l++){
            int r =  l + i;
            if(a[l] < a[r]) dp[l][r][1] += dp[l][r - 1][0];
            if(a[r - 1] < a[r]) dp[l][r][1] += dp[l][r - 1][1];
            if(a[l] < a[r]) dp[l][r][0] += dp[l + 1][r][1];
            if(a[l] < a[l + 1]) dp[l][r][0] += dp[l + 1][r][0];
            dp[l][r][0] %= mod,dp[l][r][1] %= mod;
        }
    }
    std::cout << (dp[1][n][0] + dp[1][n][1]) % mod << '\n';
    return 0;
}