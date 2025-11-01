#include <bits/stdc++.h>

const int MAX = 2e5 + 5;
int n,q;
int d[MAX],c[MAX];
int st[MAX][20],log_2[MAX],f[MAX][20],g[MAX][20];

void init(){  //预处理圆盘直径
    for(int i = 2;i <= n + 1;i++)
        log_2[i] = log_2[i >> 1] + 1;
    for(int i = 1;i <= n;i++)
        st[i][0] = d[i];
    for(int j = 1;(1 << j) <= n;j++)
        for(int i = 1;i <= n - (1 << j) + 1;i++)
            st[i][j] = std::max(st[i][j - 1],st[i + ((1 << j) - 1)][j - 1]);
}

int rmq(int l,int r){  //查询l~r最大的圆盘直径
    int k = log_2[r - l + 1];
    return std::max(st[l][k],st[r - (1 << k) + 1][k]);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q;
    for(int i = 1;i <= n;i++) std::cin >> d[i] >> c[i];
    init();
    c[n + 1] = INT_MAX;
    d[n + 1] = INT_MAX;
    for(int i = 1;i < n;i++){  //二分求每个圆盘的下一个
        int l = i + 1,r = n + 1,mid;
        for(;l < r;){
            mid = (l + r) >> 1;
            if(rmq(i + 1,mid) <= d[i]) l = mid + 1;
            else r = mid;
        }
        f[i][0] = l;
        g[i][0] = c[f[i][0]];
    }
    f[n][0] = f[n + 1][0] = n + 1;
    g[n][0] = g[n + 1][0] = c[f[n][0]];
    for(int k = 1;k <= 16;k++)
        for(int i = 1;i <= n;i++){
            f[i][k] = f[f[i][k - 1]][k - 1];
            g[i][k] = g[i][k - 1] + g[f[i][k - 1]][k - 1];
        }
    while(q--){
        int r,v;
        std::cin >> r >> v;
        if(v > c[r]){
            v -= c[r];
            for(int k = 16;k >= 0;k--)
                if(v > g[r][k])
                    v -= g[r][k],
                    r = f[r][k];
            r = f[r][0];
        }
        if(r == n + 1) r = 0;
        std::cout << r << '\n';
    }
    return 0;
}