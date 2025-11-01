#include <bits/stdc++.h>
const int MAX = 105;

int n,m,ki,mi = 1e9;
int sum[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> m >> ki;
    
    for(int i = 1;i <= n;i++){
        std::string s;
        std::cin >> s;
        s = '.' + s;
        for(int j = 1;j < s.size();j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[j] - '0');
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            for(int k = i;k <= n;k++)
                for(int l = j;l <= m;l++){
                    int cnt = sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
                    if(cnt >= ki){
                        mi = std::min(mi,(k - i + 1) * (l - j + 1));
                    }
                }
    std::cout << (mi != 1e9 ? mi : 0) << '\n';
    return 0;
}