#include <bits/stdc++.h>
const int MAX = 2e6 + 5;

int n,m;
int a[MAX],ans[MAX];
std::vector<std::tuple<int,int,int> > q[MAX];

struct BIT{
    int sum[MAX];
    #define lowbit(x) (x & (-x))
    void insert(int p,int x){
        for(;p <= n;p += lowbit(p))
            sum[p] += x;
    }
    int query(int r){
        int res = 0;
        while(r > 0){
            res += sum[r];
            r -= lowbit(r);
        }
        return res;
    }
}bit;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int l,r,x,i = 1;i <= m;i++){
        std::cin >> l >> r >> x;
        q[l - 1].push_back({x,-1,i});
        q[r].push_back({x,1,i});
    }
    for(int i = 1;i <= n;i++){
        bit.insert(a[i],1);
        for(auto [pos,mul,id] : q[i]){
            ans[id] += mul * bit.query(pos);
        }
    }
    for(int i = 1;i <= m;i++)
        std::cout << ans[i] << '\n';
    return 0;
}