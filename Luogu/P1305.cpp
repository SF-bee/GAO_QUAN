#include <bits/stdc++.h>

const int MAX = 30;
int n;
char r;
std::map<char,std::pair<char,char> > e;

void dfs(char d);

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++){
        std::string s;
        std::cin >> s;
        if(i == 0) r = s.at(0);
        e[s.at(0)].first = s.at(1);
        e[s.at(0)].second = s.at(2);
    }

    dfs(r);
    return 0;
}

void dfs(char d){
    std::cout << d;
    if(e[d].first != '*') dfs(e[d].first);
    if(e[d].second != '*')dfs(e[d].second);
}