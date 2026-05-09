#include <bits/stdc++.h>
using ll = long long;
#define Nanami return
#define ChiaKi 0
const int MAX = 3e3 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n,m,s[MAX],t[MAX];
int d[4][4],A,B;
ll dp[MAX][MAX][3];
//dp[i][j][0/1/2]表示匹配到第i,j个，这个位置的末尾 都没空格/s有空格/t有空格的 最大相似度

int toi(char ch){
    if(ch == 'A') return 0;
    if(ch == 'T') return 1;
    if(ch == 'G') return 2;
    if(ch == 'C') return 3;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string sg;
    std::cin >> sg,n = sg.size();
    for(int i = 0;i < n;i++)
        s[i + 1] = toi(sg[i]);
    std::cin >> sg,m = sg.size();
    for(int i = 0;i < m;i++)
        t[i + 1] = toi(sg[i]);
    for(int i = 0;i < 4;i++)
        for(int j = 0;j < 4;j++)
            std::cin >> d[i][j];
    std::cin >> A >> B;
    
    for (int i = std::max(n, m); i; --i) {
        dp[0][i][0] = dp[i][0][0] = dp[0][i][2] = dp[i][0][1] = -INF;
        dp[0][i][1] = dp[i][0][2] = -A - B * (i - 1);
    }
    dp[0][0][1] = dp[0][0][2] = -INF;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++){
            dp[i][j][0] = std::max({dp[i - 1][j - 1][0],dp[i - 1][j - 1][1],dp[i - 1][j - 1][2]}) + d[s[i]][t[j]];
            dp[i][j][1] = std::max({dp[i][j - 1][0] - A,dp[i][j - 1][1] - B,dp[i][j - 1][2] - A});
            dp[i][j][2] = std::max({dp[i - 1][j][0] - A,dp[i - 1][j][2] - B,dp[i - 1][j][1] - A});
        }
    std::cout << std::max({dp[n][m][0],dp[n][m][1],dp[n][m][2]}) << '\n';
    Nanami ChiaKi;
}