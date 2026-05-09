#include <bits/stdc++.h>

const int MAX = 1e5;
int n,m;
int a[MAX];
int log_2[MAX],f[MAX][MAX];
int RMQ(int l,int r){
    int k = log_2[r - l + 1];
    return std::min(f[l][k],f[r - (1 << k) + 1][k]);
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 0;i < n;i++)
        std::cin >> a[i];
    for(int i = 2;i <= n;i++)
        log_2[i] = log_2[i >> 1] + 1;
    for(int i = 1;i <= n;i++)
        f[i][0] = a[i];
    for(int j = 1;(1 << j) <= n;j++)
        for(int i = 1;i <= n - (1 << j) + 1;i++)
            f[i][j] = std::min(f[i][j - 1],f[i + (1 << j - 1)][j - 1]);
    for(int i = 1;i <= n;i++){
        if(i == 1) std::cout << 0 << '\n';
        else if(i <= m) std::cout << RMQ(1,i - 1) << '\n';
        else std::cout << RMQ(i - m,i - 1) << '\n';
    }
    return 0;
}