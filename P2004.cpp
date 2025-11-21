#include <bits/stdc++.h>
const int MAX = 5e3 + 5;

int n,m,c,mx = -INT_MAX;
std::pair<int,int> ans = {1,1};
std::array<int,MAX> a[MAX],b[MAX];

int main(){
    freopen("P2004.in","r",stdin);
    freopen("P2004.out","w",stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> c;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            std::cin >> b[i][j];
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j];
        }
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if (i + c - 1 > n || j + c - 1 > m) continue;
            int t = a[i + c - 1][j + c - 1] - a[i - 1][j + c - 1] - a[i + c - 1][j - 1] + a[i - 1][j - 1];
            if(mx < t){
                mx = t;
                ans = {i,j};
            }
        }
    }
    std::cout << ans.first << ' ' << ans.second;
    return 0;
}