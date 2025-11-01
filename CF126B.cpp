#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

std::string s;
int ans,maxa,p[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s;
    for(int j = 0,i = 1;i < s.size();i++){
        while(j > 0 && s[i] != s[j]) j = p[j - 1];
        if(s[i] == s[j]) p[i] = ++j;
    }
    for(int i = 1;i < s.size() - 1;i++) maxa = std::max(maxa,p[i]);
    for(int t = p[s.size() - 1];t;t = p[t - 1]){
        if(maxa >= t){
            ans = t;
            for(int i = 0;i < t;i++) std::cout << s[i];
            std::cout << '\n';
            return 0;
        }
    }
    std::cout << "Just a legend\n";
    return 0;
}