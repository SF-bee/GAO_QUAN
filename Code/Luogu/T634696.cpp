#include <bits/stdc++.h>
const int MAX = 3e5 + 5;

int n,q,a[MAX],ans[MAX];
struct pro{
    int l,r,k,val;
    bool operator < (const pro &rhs) const{
        return k > rhs.k;
    }
}p[MAX];
struct point{
    int x,y;
    bool operator < (const point &rhs) const{
        return y > rhs.y;
    }
}; std::vector<point> hp;
struct bit{
    int cnt[MAX];
    int lowbit(int x){return x & (-x);}
    void insert(int x,int k){
        for(;x <= n;x += lowbit(x))
            cnt[x] += k;
    }
    int query(int x){
        int res = 0;
        while(x > 0){
            res += cnt[x];
            x -= lowbit(x);
        }
        return res;
    }
    int query(int l,int r){
        return query(r) - query(l - 1);
    }
}tree;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q;
    for(int i = 1;i <= n;i++){
        std::cin >> a[i];
        for(int j = a[i];j > 0;j >>= 1){
            hp.push_back({i,j});
        }
    }
    for(int i = 1;i <= q;i++){
        std::cin >> p[i].l >> p[i].r >> p[i].k;
        p[i].val = i;
    }
    std::sort(hp.begin(),hp.end());
    std::sort(p + 1,p + q + 1);
    for(int j = 0,i = 1;i <= q;i++){
        for(;j < hp.size() && hp[j].y > p[i].k;j++) tree.insert(hp[j].x,1);
        ans[p[i].val] += tree.query(p[i].l,p[i].r);
    }
    for(int i = 1;i <= q;i++) std::cout << ans[i] << '\n';
    return 0;
}