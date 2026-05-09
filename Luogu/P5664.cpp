#include <bits/stdc++.h>
using ll = long long;
const int N = 1e2 + 5,M = 2e3 + 5;
const int mod = 998244353;

int n,m;
int a[N][M],dp[N][M][N];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            std::cin >> a[i][j];
        
    
    for(int i = 1;i <= n;i++){  //枚举第几行
        for(int j = 1;j <= n;j++){  //枚举背包大小
            //01背包
            for(int l = 1;l <= m;l++){  //物品编号
                for(int k = j;k >= 0;k--){  //选了k个物品
                    dp[i][j][k] = dp[i - 1][j][k] 
                }
            }
        }
    }
    return 0;
}