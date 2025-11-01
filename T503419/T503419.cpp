#include <bits/stdc++.h>
const int N = 1e2 + 5;
const int MAX = 1e5 + 5;

int n,ans,a[N];
int dp[N][MAX << 1];  //dp[i][j]表示选择序列1~i，j能否被凑出

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
    	std::cin >> a[i];
    dp[0][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < MAX;j++){
            /*对于每个dp_i_j,要么不选这个数字，
            要么选择，可由加得到j或由减得到j
            */
            dp[i][j] = std::max({dp[i - 1][j],dp[i - 1][abs(j - a[i])],dp[i - 1][abs(j + a[i])]});
        }
    }
    for(int i = 0;i < MAX;i++)
        if(dp[n][i]) ans++;
    std::cout << ans - 1;
    return 0;
}
/*
|3 - 5| = 2
*/