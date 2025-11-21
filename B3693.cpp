#include <bits/stdc++.h>
const int MAX = 1e3 + 5;

int T,n,m,q;
unsigned long long a[MAX][MAX],sum[MAX][MAX],ans;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        ans = 0;
        memset(sum,0,sizeof(sum));
        std::cin >> n >> m >> q;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                std::cin >> a[i][j],sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        int u,v,x,y;        
        while(q--){
            std::cin >> u >> v >> x >> y;
            ans ^= sum[x][y] - sum[x][v - 1] - sum[u - 1][y] + sum[u - 1][v - 1];
        }
        std::cout << ans << '\n';
    }
    return 0;
}