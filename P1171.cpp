#include <bits/stdc++.h>
const int MAX = 21;

int n,s[MAX][MAX],dp[1<<MAX][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            std::cin >> s[i][j];
    std::memset(dp,0x3f,sizeof(dp));
    dp[1][1] = 0;
    for(int S = 1;S < (1 << n);S++){
        for(int i = 1;i <= n;i++) if(S & (1 << i - 1)){  //从哪来
            for(int j = 1;j <= n;j++) if((S & (1 << j - 1)) == 0){ //到哪去
                dp[S | (1 << j - 1)][j] = std::min(dp[S | (1 << j - 1)][j],
                                                   dp[S][i] + s[i][j]);
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 2;i <= n;i++)
        ans = std::min(ans,dp[(1 << n) - 1][i] + s[i][1]);
    std::cout << ans << '\n';
    return 0;
}