#include <bits/stdc++.h>
const int MAX = 50;

int n,m;
int a[MAX][MAX],num[MAX];
int mans,ans[MAX];

void dfs(int d,int sum,int cnt){
    if(d == n + 1){
        if(sum > mans){
            mans = sum;
            for(int i = 1;i <= n;i++) ans[i] = num[i];
        }
        return;
    }
    for(int i = 0;i <= m;i++){
        num[d] = i;
        if(cnt + i <= m)
            dfs(d + 1,sum + a[d][i],cnt + i);
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            std::cin >> a[i][j];
    dfs(1,0,0);
    std::cout << mans << '\n';
    for(int i = 1;i <= n;i++)
        std::cout << i << ' ' << ans[i] << '\n';
    return 0;
}