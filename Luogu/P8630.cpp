#include <bits/stdc++.h>
const int MAX = 1e3+5;

int n,ans;
std::string s;
std::multiset<std::string> a;

inline std::string rd(){
    std::string x;
    std::cin >> x;
    std::sort(x.begin(),x.end());
    return x;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s >> n;
    for(int i = 0;i < n;i++) a.insert(rd());

    for(int i = 0;i < s.size() - 7;i++){
        std::string t = s.substr(i,8);
        std::sort(t.begin(),t.end());
        ans += a.count(t);
    }
    std::cout << ans;
    return 0;
}