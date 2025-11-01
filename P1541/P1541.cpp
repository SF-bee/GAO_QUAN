#include <bits/stdc++.h>

const int MAX = 500;
int n,m;
int a[MAX];
int move[5];
int dp[50][50][50][50];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) std::cin >> a[i];
    for(int i = 1;i <= m;i++) {int t; std::cin >> t; move[t]++;}
    
    for(int i = 0;i <= move[1];i++){
        for(int j = 0;j <= move[2];j++){
            for(int k = 0;k <= move[3];k++){
                for(int l = 0;l <= move[4];l++){
                    int t = 1 + i + j * 2 + k * 3 + l * 4;
                    if(i > 0) dp[i][j][k][l] = std::max(dp[i][j][k][l],dp[i - 1][j][k][l] + a[t]);
                    if(j > 0) dp[i][j][k][l] = std::max(dp[i][j][k][l],dp[i][j - 1][k][l] + a[t]);
                    if(k > 0) dp[i][j][k][l] = std::max(dp[i][j][k][l],dp[i][j][k - 1][l] + a[t]);
                    if(l > 0) dp[i][j][k][l] = std::max(dp[i][j][k][l],dp[i][j][k][l - 1] + a[t]);
                }
            }
        }
    }
    std::cout << dp[move[1]][move[2]][move[3]][move[4]] + a[1];
    return 0;
}