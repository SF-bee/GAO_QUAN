#include <bits/stdc++.h>

std::string s;
std::vector<std::string> t;

bool check(std::string s){
    int dx = 0,xx = 0,sz = 0,fh = 0;
    if(s.size() < 6 && s.size() > 12) return 0;
    for(auto i : s){
        if(i >= 'A' && i <= 'Z') dx = 1;
        else if(i >= 'a' && i <= 'z') xx = 1;
        else if(i >= '0' && i <= '9') sz = 1;
        else if(i == '!' || i == '@' || i == '#' || i == '$') fh = 1;
        else return 0;
    }
    if(dx + xx + sz >= 2 && fh >= 1) return 1;
    else return 0;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s;
    int a = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == ',') t.push_back(s.substr(a,i - a)),a = i + 1;
    }
    t.push_back(s.substr(a));
    for(auto i : t)
        if(check(i)) std::cout << i << '\n';
    return 0;
}