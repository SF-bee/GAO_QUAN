#include <bits/stdc++.h>
const int MAX = 2e5 + 5;

std::unordered_set<std::string> p;
std::string t,s;
int ans,mx;
bool dp[MAX];

inline bool check(int x){
    for(int i = std::min(x,mx);i >= 1;i--){
        std::string t = s.substr(x - i + 1,i);
        // std::cout << t << '\n';
        if(dp[x - i] && p.count(t) == 1) return 1;
    }
    return 0;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    while(std::cin >> t){
        if(t != ".") p.insert(t),mx = std::max(mx,(int)t.size());
        else break;
    }

    while(std::cin >> t){
        s += t;
    }
    s = '.' + s;
    dp[0] = 1;
    for(int i = 1;i < s.size();i++){
        if(check(i)) dp[i] = 1,ans = i;
    }
    std::cout << ans;
    return 0;
}