#include <bits/stdc++.h>
const int MAX = 5e3 + 5;

int n,m;
int a[MAX],b[MAX],dp[MAX][MAX][2];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    std::cin >> m;
    for(int j = 1;j <= m;j++)
        std::cin >> b[j];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = 0;
    for(int i = 1;i <= n;i++){  //初始化a
        if(i == 1){
            if(a[i] == 0) dp[i][0][0] = 2;
            if(a[i] == 1) dp[i][0][0] = 1;
        }
        else if(a[i - 1] != a[i]) dp[i][0][0] = dp[i - 1][0][0] + 1;
        else dp[i][0][0] = dp[i - 1][0][0] + 2;
    }
    for(int i = 1;i <= m;i++){ //初始化b
        if(i == 1){
            if(b[i] == 0) dp[0][i][1] = 2;
            if(b[i] == 1) dp[0][i][1] = 1;
        }
        else if(b[i - 1] != b[i]) dp[0][i][1] = dp[0][i - 1][1] + 1;
        else dp[0][i][1] = dp[0][i - 1][1] + 2;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            //转移到a
            if(a[i] == a[i - 1]) dp[i][j][0] = std::min(dp[i][j][0],dp[i - 1][j][0] + 2);
            else if(a[i] != a[i - 1]) dp[i][j][0] = std::min(dp[i][j][0],dp[i - 1][j][0] + 1);
            if(a[i] == b[j]) dp[i][j][0] = std::min(dp[i][j][0],dp[i - 1][j][1] + 2);
            else if(a[i] != b[j]) dp[i][j][0] = std::min(dp[i][j][0],dp[i - 1][j][1] + 1);

            //转移到b
            if(b[j] == b[j - 1]) dp[i][j][1] = std::min(dp[i][j][1],dp[i][j - 1][1] + 2);
            else if(b[j] != b[j - 1]) dp[i][j][1] = std::min(dp[i][j][1],dp[i][j - 1][1] + 1);
            if(b[j] == a[i]) dp[i][j][1] = std::min(dp[i][j][1],dp[i][j - 1][0] + 2);
            else if(b[j] != a[i]) dp[i][j][1] = std::min(dp[i][j][1],dp[i][j - 1][0] + 1);
        }
    }
    // for(int i = 1;i <= n;i++){
    //     for(int j = 1;j <= m;j++){
    //         std::cout << dp[i][j][0] << '/' << dp[i][j][1] << ' ';
    //     }
    //     std::cout << '\n';
    // }
    std::cout << std::min(dp[n][m][0],dp[n][m][1]) << '\n';
    return 0;
}