#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 8e2 + 5;
const int K = 20;
const int mod = 1e9 + 7;

int n,m,k;
int mp[MAX][MAX],dp[MAX][MAX][K][2];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            std::cin >> mp[i][j],dp[i][j][(mp[i][j]) % (k + 1)][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            for(int a = 0;a <= k;a++){
                dp[i][j][a][1] = (dp[i][j][a][1] + dp[i - 1][j][(a + mp[i][j]) % (k + 1)][0]) % mod;
                dp[i][j][a][1] = (dp[i][j][a][1] + dp[i][j - 1][(a + mp[i][j]) % (k + 1)][0]) % mod;
                dp[i][j][a][0] = (dp[i][j][a][0] + dp[i - 1][j][(k + 1 + a - mp[i][j]) % (k + 1)][1]) % mod;
                dp[i][j][a][0] = (dp[i][j][a][0] + dp[i][j - 1][(k + 1 + a - mp[i][j]) % (k + 1)][1]) % mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++){
            ans = (ans + dp[i][j][0][1]) % mod;
        }
            
    std::cout << ans << '\n';
    return 0;
}