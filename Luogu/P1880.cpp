#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 2e2 + 5;

ll n,sum[MAX],a[MAX],f[MAX][MAX],g[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::memset(g,0x3f,sizeof(g));
    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],a[i + n] = a[i];
    for(int i = 1;i <= 2 * n;i++)
        g[i][i] = 0,
        sum[i] = sum[i - 1] + a[i];
    for(int i = 1;i < n;i++){ //枚举区间长
        for(int l = 1;l <= 2 * n - i;l++){ //枚举区间首
            int r = l + i;
            for(int k = l;k < r;k++){
                f[l][r] = std::max(f[l][r],f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
                g[l][r] = std::min(g[l][r],g[l][k] + g[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }

    ll ans1 = LONG_LONG_MIN,ans2 = LONG_LONG_MAX;
    for(int i = 1;i <= n;i++)
        ans1 = std::max(ans1,f[i][i + n - 1]),
        ans2 = std::min(ans2,g[i][i + n - 1]);
    std::cout << ans2 << '\n' << ans1 << '\n';
    return 0;
}