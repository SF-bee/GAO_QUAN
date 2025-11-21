#include <bits/stdc++.h>

std::string s1,s2;
int ans = 0;

char neg(char x){
    if(x == 'o') return '*';
    else return 'o';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> s1 >> s2;
    for(int i = 0;i < s1.size();i++){
        if(s1[i] != s2[i]){
            s1[i] = neg(s1[i]);
            s1[i + 1] = neg(s1[i + 1]);
            ans++;
        }
    }
    std::cout << ans;
    return 0;
}