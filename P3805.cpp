#include <bits/stdc++.h>
const int MAX = 2.2e7 + 5;

int n,r[MAX];
char ch[MAX];

int main(){
    ch[++n] = '^';
    ch[++n] = '|';
    char c = getchar();
    for(;std::isalpha(c);c = getchar()){
        ch[++n] = c;
        ch[++n] = '|';
    }
    ch[++n] = '$';
    for(int i = 1,j = 0,m = 0;i < n;i++){
        if(i <= j) r[i] = std::min(r[2 * m - i],j - i + 1);
        while(ch[i - r[i]] == ch[i + r[i]]) r[i]++;
        if(i + r[i] - 1 >= j){
            j = i + r[i] - 1;
            m = i;
        }
    }
    int ans = 0;
    for(int i = 1;i < n;i++)
        ans = std::max(r[i] - 1,ans);
    std::cout << ans << '\n';    
    return 0;
}