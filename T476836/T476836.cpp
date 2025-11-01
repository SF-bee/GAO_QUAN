#include <bits/stdc++.h>

const int MAX = 20;
int n,m,maxa = 0;
int sum0[MAX][MAX],sum1[MAX][MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++){
        std::string s; std::cin >> s;
        for(int j = 1;j <= m;j++){
            sum0[i][j] = sum0[i - 1][j] + sum0[i][j - 1] - sum0[i - 1][j - 1] + (s[j - 1] == '0' ? 1 : 0);
            sum1[i][j] = sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1] + (s[j - 1] == '1' ? 1 : 0);
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            for(int k = i;k <= n;k++){
                for(int l = j;l <= m;l++){
                    int s0 = sum0[k][l] - sum0[i - 1][l] - sum0[k][j - 1] + sum0[i - 1][j - 1];
                    int s1 = sum1[k][l] - sum1[i - 1][l] - sum1[k][j - 1] + sum1[i - 1][j - 1];
                    if(s0 == s1) maxa = std::max(maxa,(k - i + 1) *(l - j + 1));
                }
            }
        }
    }
    std::cout << maxa;
    return 0;
}