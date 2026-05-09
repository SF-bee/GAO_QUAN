#include <bits/stdc++.h>
const int MAX = 1e6 + 5;

int n,m,a[MAX],lst[MAX],ans[MAX];
struct que{
    int l,r,val;
    bool operator < (const que &rhs) const{
        return r < rhs.r;
    }
}q[MAX];
#define lowbit(x) (x&(-x))
struct bit{
    int cnt[MAX];
    void add(int x,int k){
        for(;x <= n;x += lowbit(x))
            cnt[x] += k;
    }
    int query(int x){
        int res = 0;
        while(x > 0)
            res += cnt[x],x -= lowbit(x);
        return res;
    }
}sum;
#undef lowbit

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    std::cin >> m;
    for(int i = 1;i <= m;i++)
        std::cin >> q[i].l >> q[i].r,q[i].val = i;
    std::sort(q + 1,q + m + 1);
    for(int l = 1,i = 1;i <= m;i++){
        for(;l <= q[i].r;l++){
            if(lst[a[l]] == 0) lst[a[l]] = l,sum.add(l,1);
            else{
                sum.add(lst[a[l]],-1);
                sum.add(l,1);
                lst[a[l]] = l;
            }
        }
        ans[q[i].val] = sum.query(q[i].r) - sum.query(q[i].l - 1);
    }
    for(int i = 1;i <= m;i++)
        std::cout << ans[i] << '\n';
    return 0;
}