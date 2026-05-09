#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,k;
struct tp {
    int a,b,c;
    int cnt,ans;
}a[MAX];
struct fwt {
    int cnt[MAX * 2];
    #define lowbit(x) (x&(-x))
    void add(int p,int x) {
        for(;p <= n;p += lowbit(p))
            cnt[p] += x;
    }
    int query(int r) {
        int res = 0;
        while(r)
            res += cnt[r],
            r -= lowbit(r);
        return res;
    }
    #undef lowbit
}BIT;
int f[MAX];

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);

    auto cmp = [&](tp x,tp y) -> bool { return x.a < y.a;};
    std::cin >> n >> k;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i].a >> a[i].b >> a[i].c,a[i].cnt = 1;
    std::sort(a + 1,a + n + 1,cmp);
    
    auto cdq = [&](auto &cdq,int l,int r) -> void {
        if(l == r) return;
        int mid = (l + r) >> 1;
        cdq(cdq,l,mid),cdq(cdq,mid + 1,r);
        
        return;
    };
    cdq(cdq,1,n);
    for(int i = 1;i <= n;i++)
        f[a[i].ans]++;
    for(int i = 0;i < n;i++)
        std::cout << f[i] << '\n';
    return 0;
}