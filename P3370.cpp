#include <bits/stdc++.h>
typedef unsigned long long ull;
const int MAX = 1e4 + 5;
const ull MOD = 1000000007;
const ull BASE = 37;

int n;
std::vector<ull> vec;

ull hash(std::string s){
    ull cnt = 0;
    ull b = 1;
    for(auto i : s)
        cnt += (b * i) % MOD,b *= BASE;
    return cnt;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++){
        std::string t;
        std::cin >> t;
        vec.push_back(hash(t));
    }
    std::sort(vec.begin(),vec.end());
    vec.erase(std::unique(vec.begin(),vec.end()),vec.end());
    std::cout << vec.size();
    return 0;
}