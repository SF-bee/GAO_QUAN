#include <bits/stdc++.h>
const int MAX = 105;

std::string s;
int n,k;
int c[30][30];
int f[MAX][MAX][MAX];

void Max(int &x,int y){
    if(x < y)
        x = y;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s >> k >> n;
    for(int p,i = 0;i < n;i++){
        char x,y;
        std::cin >> x >> y >> p;
        c[x - 'a'][y - 'a'] = p;
    }
    for(auto &i : s)
        i -= 'a';
    n = s.size();
    std::memset(f,-63,sizeof(f));
    for (int i = 0; i < 26; i++)
        f[0][s[0] != i][i] = 0;
    for(int i = 0;i < n - 1;i++)
        for(int j = 0;j <= k;j++)
            for(int p = 0;p < 26;p++)
                if(f[i][j][p] > -1e9)
                    for(int q = 0;q < 26;q++)
                        Max(f[i + 1][j + (s[i + 1] != q)][p],f[i][j][p] + c[p][q]);
    int ans = INT_MIN;
    for (int i = 0; i <= k; i++)
        for (int d = 0; d < 26; d++)
            Max(ans, f[n - 1][i][d]);
    std::cout << ans << '\n';
}