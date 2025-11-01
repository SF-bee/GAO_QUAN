#include <bits/stdc++.h>

std::string s,t;

bool check(char x,char y){
    if(('A' <= y && y <= 'Z') && ('a' <= x && x <= 'z'))
        return (y - 'A') == (x - 'a');
    else if(('A' <= x && x <= 'Z') && ('a' <= y && y <= 'z'))
        return (y - 'a') == (x - 'A');
    else if(y == '?') return 1;
    return 0;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s >> t;
    int cnt = 0;
    for(int i = t.size() - 1;i < s.size();i++){
        bool flag = 0;
        for(int j = i - t.size() + 1;j <= i;j++)
            if(!check(s[j],t[j])) flag = 1;
        if(flag = 0) cnt++;
    }
    std::cout << cnt;
    return 0;
}