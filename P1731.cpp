/*
注意到，pi是齐次的，因此比较大小与pi无关
如何计算表面积
注意到，蛋糕是单调递减的，因此每层蛋糕圆部分的面积之和应该等于最底层蛋糕的上表面，因此圆的面积只和最底的蛋糕半径相关 r1*r1
每一层的侧面积 2 * r_i * h_i
如何计算体积
r_i * r_i * h_i
*/
#include <bits/stdc++.h>
using ll = long long;
const int INF = 0x3f3f3f3f;

ll n,m;
ll ans = INF;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m;
    ll maxR = std::ceil(std::sqrt((double)n / m));
    auto dfs = [](auto &self,int d,ll lastR,ll lastH,ll Q,ll V) -> void {
        if(d == m + 1) {
            if(V == n) ans = std::min(ans,Q);
            return;
        }
        if(Q > ans) return;
        for(ll r = lastR;r >= m - d + 1;r--) {
            if(d == 1) Q = r * r;
            if(Q + 2 * (n - V) / r > ans) continue;
            for(ll h = lastH;h >= m - d + 1;h--) {
                if(V + r * r * h <= n) {
                    self(self,d + 1,r - 1,h - 1,Q + 2 * r * h,V + r * r * h);
                }
                    
            }
        }
    };
    dfs(dfs,1,maxR,n,0,0);
    if(ans == INF) std::cout << 0 << '\n';
    else std::cout << ans << '\n';
    return 0;
}