#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,m,q;
int a[MAX],b[MAX];
int log2[22],fax[22][MAX],gax[22][MAX],fin[22][MAX],gin[22][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    for(int i = 1;i < MAX;i++)
        log2[i] = log2[i >> 1] + 1;

    std::cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        std::cin >> a[i], fax[0][i] = fin[0][i] = a[i];
    for(int i = 1; i <= m; i++)
        std::cin >> b[i], gax[0][i] = gin[0][i] = b[i];
    for(int k = 1;(1 << k) <= n;k++){
        for(int i = 1;i <= n;i++)
            fax[k][i] = std::max(fax[k - 1][i],fax[k - 1][i + (1 << (k - 1))]),
            fin[k][i] = std::min(fin[k - 1][i],fin[k - 1][i + (1 << (k - 1))]);
        for(int i = 1;i <= m;i++)
            gax[k][i] = std::max(gax[k - 1][i],gax[k - 1][i + (1 << (k - 1))]),
            gin[k][i] = std::min(gin[k - 1][i],gin[k - 1][i + (1 << (k - 1))]);
    }

    while(q--){
        int la,ra,lb,rb;
    }
    return 0;
}