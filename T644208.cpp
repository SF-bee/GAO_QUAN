#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n,id,maxa,ans;
std::string s[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        std::cin >> s[i];
        if(s[i].size() > maxa){
            maxa = s[i].size();
            id = i;
        }
    }
    for(int i = 1;i <= n;i++) if(i != id){
        int j = 0;
        for(;j < s[i].size();j++)
            if(s[i][j] != s[id][j]) break;
        ans = std::max(ans,int(s[i].size() + maxa - 2 * j));
    }
    std::cout << ans << '\n';
    return 0;
}