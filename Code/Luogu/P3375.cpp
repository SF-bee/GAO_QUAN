#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

std::string s1,s2;
int p[MAX];

int main(){
    std::cin.tie(0)->sync_with_stdio(0);
    
    std::cin >> s1 >> s2;
    for(int i = 1,j = 0;i < s2.size();i++){
        while(j > 0 && s2[i] != s2[j])
            j = p[j - 1];
        if(s2[i] == s2[j])
            p[i] = ++j;
    }
    for(int i = 0,j = 0;i < s1.size();i++){
        while(j > 0 && s1[i] != s2[j])
            j = p[j - 1];
        if(s1[i] == s2[j])
            j++;
        if(j == s2.size()){
            j = p[j - 1];
            int pos = i - s2.size() + 2;
            std::cout << pos << '\n';
        }
    }
    for(int i = 0;i < s2.size();i++)
        std::cout << p[i] << ' ';
    return 0;
}
