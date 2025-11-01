#include <bits/stdc++.h>
typedef long long ull;
const int MAX = 3e3 + 5;
const ull MOD = 10000000000037;
const ull base = 51971;

int n;
std::string a,b;
std::vector<ull> ans;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n;
    std::cin >> a >> b;
    for(int i = 0;i < n;i++){
        ull hash = 0,cnt = 1;
        for(int j = i,pos = 0;j < n;j++){
            for(;pos < n && a[pos] != b[j];pos++);
            if(pos >= n) break;
            pos++;
            hash += b[j] * cnt % MOD,cnt *= base;
            ans.push_back(hash);
        }
    }
    std::sort(ans.begin(),ans.end());
    std::cout << std::unique(ans.begin(),ans.end()) - ans.begin();
    return 0;
}