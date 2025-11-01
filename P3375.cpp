#include <bits/stdc++.h>
const int MAX = 2e6 + 5;

std::string s1,s2;
int p[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s1 >> s2;
    s1 = s2 + "&" + s1;
    for(int j = 0,i = 1;i < s1.size();i++){
        while(j > 0 && s1[j] != s1[i])
            j = p[j - 1];
        if(s1[j] == s1[i])
            p[i] = ++j;
    }
    for(int i = s2.size() + 1;i < s1.size();i++)
        if(p[i] == s2.size())
            std::cout << i - s2.size() - s2.size() + 1 << '\n';
    for(int i = 0;i < s2.size();i++)
        std::cout << p[i] << ' ';
    return 0;
}