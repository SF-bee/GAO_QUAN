#include <bits/stdc++.h>
typedef long long ll;
const int N = 1e5 + 5;
const int K = 20;

ll n,k;
ll a[N],dp[N][K][2];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int j = 1;j <= k;j++){   
        for(int i = 1;i <= n;i++){ 
            dp[i][j][0] = std::max(dp[i - 1][j][0],dp[i - 1][j][1]);
            dp[i][j][1] = std::max(dp[i - 1][j][1],dp[i - 1][j - 1][0]) + a[i];
        }
    }
    std::cout << std::max(dp[n][k][1],dp[n][k][0]) << '\n';
    return 0;
}