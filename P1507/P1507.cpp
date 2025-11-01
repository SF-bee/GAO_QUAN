#include <bits/stdc++.h>

const int MAX = 500;
int n,h,t;
int a[MAX][3];
int dp[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> h >> t;
    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    for(int i = 1;i <= n;i++){
        for(int j = h;j >= a[i][0];j--){
            for(int k = t;k >= a[i][1];k--){
                dp[j][k] = std::max(dp[j][k],dp[j - a[i][0]][k - a[i][1]] + a[i][2]);
            }
        }
    }
    std::cout << dp[h][t];
    return 0;
}