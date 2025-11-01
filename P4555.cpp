#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

//r_i 表示以 i 为中心最长回文串的半径
//f_i 表示以 i 开头的最长回文串的长度
//g_i 表示以 i 结束的最长回文串的长度
int n,r[MAX],f[MAX],g[MAX];
char s[MAX];

int main(){
    s[++n] = '^';
    s[++n] = '|';
    char ch = getchar();
    for(;std::isalpha(ch);ch = getchar()){
        s[++n] = ch;
        s[++n] = '|';
    }
    s[++n] = '$';
    for(int j = 0,m = 0,i = 1;i < n;i++){
        if(i <= j) r[i] = std::min(r[2 * m - i],j - i + 1);
        while(s[i - r[i]] == s[i + r[i]]) r[i]++;
        if(i + r[i] - 1 >= j){
            j = i + r[i] - 1;
            m = i;
        }
    }
    for(int i = 1;i < n;i++){
        f[i - r[i] + 1] = std::max(f[i - r[i] + 1],r[i] - 1);
        g[i + r[i] - 1] = std::max(g[i + r[i] - 1],r[i] - 1);
    }
    int ans = 0;
    for(int i = 2;i <= n - 1;i += 2)
        f[i] = std::max(f[i],f[i - 2] - 2);
    for(int i = n - 1;i >= 2;i -= 2)
        g[i] = std::max(g[i],g[i + 2] - 2);
    for(int i = 2;i <= n - 1;i += 2)
        if(f[i] && g[i])
            ans = std::max(ans,f[i] + g[i]);
    std::cout << ans << '\n';
    return 0;
}