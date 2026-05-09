#include <bits/stdc++.h>
typedef long long ll;

int n,k;
int neighbor[1 << 10][1 << 10];
ll dp[10][1 << 10][100];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    std::vector<int> can;
    for (int i = 0; i < (1 << n); ++i) if ((i & (i << 1)) == 0)
        can.push_back(i);
    for(auto s : can)
        for(auto t : can){
            if ((s & t) || (s & (t << 1)) || (t & (s << 1))) continue;
            neighbor[s][t] = 1;
        }
    dp[0][0][0] = 1;
    for(int i = 0;i < n;i++){
        for(auto s : can){
            for(int j = 0;j <= k;j++){
                for(auto t : can) if(neighbor[s][t]){
                    int cnt = j + __builtin_popcount(t);
                    if(cnt <= k){
                        dp[i + 1][t][cnt] += dp[i][s][j];
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(auto t : can)
        ans += dp[n][t][k];
    std::cout << ans << '\n';
    return 0;
}