#include <bits/stdc++.h>
#define int long long
const int MAX = 60;

int n,c;
int ps[MAX],pw[MAX],sum[MAX];
int dp[MAX][MAX][2];

int calc(int s,int t,int l,int r){  //s,t表示需要走的两端，l,r表示已经关掉的区间
    return (ps[t] - ps[s]) * (sum[l] + sum[n] - sum[r - 1]);
}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::memset(dp,0x3f,sizeof(dp));
    std::cin >> n >> c;
    for(int i = 1;i <= n;i++){
        std::cin >> ps[i] >> pw[i];
        sum[i] = sum[i - 1] + pw[i];
    }
    dp[c][c][0] = dp[c][c][1] = 0;

    for(int r = c;r <= n;r++){
        for(int l = r - 1;l >= 1;l--){
            dp[l][r][1] = std::min(
                dp[l][r - 1][1] + calc(r - 1,r,l - 1,r),
                dp[l][r - 1][0] + calc(l,r,l - 1,r)
            );
            dp[l][r][0] = std::min(
                dp[l + 1][r][1] + calc(l,r,l,r + 1),
                dp[l + 1][r][0] + calc(l,l + 1,l,r + 1)
            );
        }
    }
    std::cout << std::min(dp[1][n][0],dp[1][n][1]) << '\n';
    return 0;
}