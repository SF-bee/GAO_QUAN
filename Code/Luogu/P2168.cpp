#include <bits/stdc++.h>
typedef long long lint;

struct node{
    lint val,d;
    bool operator< (const node &rhs) const{
        if(val != rhs.val) return val > rhs.val;
        else return d > rhs.d;
    }
};

const int MAX = 1e6 + 5;
int n,k;
lint ans;
std::priority_queue<node> huf;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    for(int i = 0;i < n;i++){
        lint val;
        std::cin >> val;
        huf.push({val,1});
    }
    for(;(huf.size() - 1) % (k - 1) != 0;huf.push({0,1}));

    while(huf.size() >= k){
        lint new_val = 0,new_d = 0;
        for(int i = 0;i < k;i++){
            auto [val,d] = huf.top();
            huf.pop();
            new_val += val;
            new_d = std::max(new_d,d);
        }
        ans += new_val;
        huf.push({new_val,new_d + 1});
    }
    std::cout << ans << '\n' << huf.top().d - 1;
    return 0;
}