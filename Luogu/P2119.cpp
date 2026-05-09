#include <bits/stdc++.h>
const int MAX = 2e4 + 5;

int n,m;
int x[2 * MAX],cnt[MAX],ans[MAX][4];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 0;i < m;i++){
        std::cin >> x[i];
        cnt[x[i]]++;
    }

    for(int t = 1;9 * t <= n;t++){
        int a,b,c,d,res = 0;
        for(a = n - 9 * t - 1;a > 0;a--){
            b = a + 2 * t;
            c = a + 8 * t + 1;
            d = a + 9 * t + 1;
            res += cnt[c] * cnt[d];
            ans[a][0] += cnt[b] * res;
            ans[b][1] += cnt[a] * res;
        }
        res = 0;
        for(d = 9 * t + 2;d <= n;d++){
            a = d - 9 * t - 1;
            b = d - 7 * t - 1;
            c = d - t;
            res += cnt[a] * cnt[b];
            ans[c][2] += cnt[d] * res;
            ans[d][3] += cnt[c] * res;
        }
    }
    for(int i = 0;i < m;i++){
        std::cout << ans[x[i]][0] << ' '
                  << ans[x[i]][1] << ' '
                  << ans[x[i]][2] << ' '
                  << ans[x[i]][3] << '\n';
    }
    return 0;
}