#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 105;

int n,k;
ll ans = -INT_MAX;
ll a[MAX][MAX],dp[MAX][MAX][5 * MAX];  //dp_i_j_c表示到达i,j并且使用了c次魔法获得的最大积分

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= i;j++)
            std::cin >> a[i][j];
    std::memset(dp,0xf3,sizeof(dp));
    std::memset(dp[0],0,sizeof(dp[0]));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            for(int c = 0;c <= k && c <= i;c++){
                //每次要么没用魔法，要么用了用了魔法
                if(c == 0) //没用魔法，正常转移
                    dp[i][j][c] = std::max(dp[i - 1][j][0],dp[i - 1][j - 1][0]) + a[i][j];
                else{//使用魔法，上一次使用转移而来
                    dp[i][j][c] = std::max(dp[i - 1][j][c],dp[i - 1][j - 1][c]) + a[i][j];
                    dp[i][j][c] = std::max(dp[i][j][c],std::max(dp[i - 1][j][c - 1],dp[i - 1][j - 1][c - 1]) + 3 * a[i][j]);
                }
            }
        }
    }
    k = std::min(n,k);
    //答案在最后一行中找
    for(int j = 1;j <= n;j++)
        for(int c = 0;c <= k;c++)
            ans = std::max(ans,dp[n][j][c]);
    std::cout << ans << '\n';
    return 0;
}