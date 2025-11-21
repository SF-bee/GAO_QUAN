#include <bits/stdc++.h>

std::string s,t;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s >> t;
    for(int i = 0;i <= s.size() - t.size();i++){
        bool flag = 1;
        for(int j = 0;j < t.size();j++)
            if(s[i + j] != '?' && t[j] != '?' && s[i + j] != t[j]){
                flag = 0;
                break;
            }
        if(flag) std::cout << i + 1 << ' ' << i + t.size() << '\n';
    }
    return 0;
}