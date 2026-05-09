#include <bits/stdc++.h>

const int MAX = 300;
int n,m,t;
int a[MAX][2];
int dp[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m >> t;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i][0] >> a[i][1];
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= a[i][0];j--){
            for(int k = t;k >= a[i][1];k--){
                dp[j][k] = std::max(dp[j][k],dp[j - a[i][0]][k - a[i][1]] + 1);
            }
        }
    }
    std::cout << dp[m][t];
    return 0;
}