#include <bits/stdc++.h>

int ans = 0;
std::string s;

bool check(std::string t){
    for(int i = 0;i <= t.size() / 2 + 1;i++)
        if(t[i] != t[t.size() - i - 1])
            return 0;
    return 1;       
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s;
    for(int i = 0,j = 1;i < s.size();i += j,j++){
        std::string t = s.substr(i,j);
        // std::cout << i << ' ' << j << ' ' << t << '\n';
        if(check(t)) ans++;
    }
    std::cout << ans;
    return 0;
}