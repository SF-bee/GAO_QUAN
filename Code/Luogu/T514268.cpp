#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 2e3 + 5;
const int mod = 998244353;

ll q,n,m;
ll c[MAX][MAX],sum[MAX];

void init(){
    for(int i = 0;i < MAX;i++)
        c[i][0] = 1;
    for(int i = 1;i < MAX;i++)
        for(int j = 1;j <= i;j++)
            c[i][j] = (c[i][j] + c[i - 1][j] + c[i - 1][j - 1]) % mod;
    for(int i = 1;i < MAX;i++)
        for(int j = 1;j <= i;j++)
            sum[i] += c[i][j];
}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    init();
    std::cin >> q;
    for(int i = 0;i < MAX;i++){
        for(int j = 1;j < MAX;j++)
            c[i][j] = (c[i][j] + c[i][j - 1]) % mod;
        for(int j = 1;j < MAX;j++)
            c[i][j] = (c[i][j] + c[i][j - 1]) % mod;
    }
    for(int j = 1;j < MAX;j++)
        for(int i = 1;i < MAX;i++)
            c[i][j] = (c[i][j] + c[i - 1][j]) % mod;
    while (q--){
        std::cin >> n >> m;
        std::cout << c[n][m] << '\n';
    }
    return 0;
}
/*
1 1 0 0 0 0 0 0
1 2 1 0 0 0 0 0
1 3 3 1 0 0 0 0
1 4 6 4 1 0 0 0
1 5 10 10 5 1 0
*/