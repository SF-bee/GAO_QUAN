#include <bits/stdc++.h>
using ll = long long;
const int POS = 20;
const int N = 15;

using Row = std::array<ll, N>;
ll a,b;
std::array<Row, POS> f;

int main (){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> a >> b;
    
    auto get = [&](int x){
        f.fill({});
        std::vector<int> num;
        while(x){
            num.push_back(x % 10);
            x /= 10;
        }
        auto dfs = [&](auto &self,int pos,int last,bool lim,bool lead) -> ll {
            if(pos < 0)
                return 1;
            if(!lim && !last && f[pos][last])
                return f[pos][last];
            for(int i = 1)
        };
    };
    return 0;
}