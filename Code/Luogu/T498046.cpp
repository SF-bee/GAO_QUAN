#include <bits/stdc++.h>
typedef long long lint;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 5;
const int MOD = 10000;

int n,q;
lint a[MAX],st[20][MAX],sum[20][MAX]; //sum j i表示第 i 座山的后 2^j 座山的乘积
int log_2[MAX],nxt[MAX],g[20][MAX];  //nxt i表示从第 i 座山发射会停在哪一座山，g j i表示第 i 座山的后 2^j 座山的编号

int rmq(int l,int r){
    int k = log_2[r - l + 1];
    return std::max(st[k][l],st[k][r - (1 << k) + 1]);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i],
        st[0][i] = a[i],
        g[0][i] = i + 1,
        sum[0][i] = a[i] % MOD;
    //假设有一座高度无限高的山在所有山之后
    st[0][n + 1] = INF;
    g[0][n + 1] = n + 1;
    sum[0][n + 1] = 1;

    //st表求出区间最高的山
    for(int i = 2;i <= n + 1;i++)
        log_2[i] = log_2[i >> 1] + 1;
    for(int j = 1;(1 << j) <= n + 1;j++)
        for(int i = 1;i <= n + 2 - (1 << j);i++)
            st[j][i] = std::max(st[j - 1][i],st[j - 1][i + (1 << j - 1)]);
    //二分求出从每座山发射的终止山
    for(int i = 1;i <= n;i++){
        int t = n + 1;
        for(int l = i + 1,r = n + 1,mid;l <= r;){
            mid = (l + r) >> 1;
            if(rmq(i + 1,mid) >= a[i])
                r = (t = mid) - 1;
            else
                l = mid + 1;
        }
        nxt[i] = t;
    }
    //倍增求出炮弹路径的积
    for(int j = 1;(1 << j) <= n + 1;j++)
        for(int i = 1;i <= n + 1;i++)
            g[j][i] = g[j - 1][g[j - 1][i]],
            sum[j][i] = (sum[j - 1][i] % MOD) * (sum[j - 1][g[j - 1][i]] % MOD) % MOD;
    while(q--){
        int x;
        std::cin >> x;
        int d = nxt[x];
        lint cnt = 1;
        for(int k = log_2[n + 1];k >= 0;k--){
            if(x + (1 << k) <= d){
                cnt = cnt * sum[k][x] % MOD;
                x += (1 << k);
            }
        }
        std::cout << cnt << '\n';
    }
    return 0;
}