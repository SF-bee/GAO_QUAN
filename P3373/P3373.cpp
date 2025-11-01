#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e5 + 5;

ll n,q,mod;
ll a[MAX],cnt[MAX << 2],atag[MAX << 2],mtag[MAX << 2];

#define lc(u) (u << 1)
#define rc(u) ((u << 1) + 1)
//合并节点
void push_up(int p){cnt[p] = (cnt[lc(p)] + cnt[rc(p)]) % mod;}
//建树
void build(int p,int l,int r){
    mtag[p] = 1;
    atag[p] = 0;
    if(l == r) {cnt[p] = a[l]; return;}
    int mid = (l + r) >> 1;
    build(lc(p),l,mid);
    build(rc(p),mid + 1,r);
    push_up(p);
}
//标记
void pushtag(int p,int l,int r,ll k,ll b){
    mtag[p] = (mtag[p] * k) % mod;
    atag[p] = (atag[p] * k + b) % mod;
    cnt[p] = (cnt[p] * k + (r - l + 1) * b) % mod;
}
//下放标记
void push_down(int p,int l,int r){
    int mid = (l + r) >> 1;
    pushtag(lc(p),l,mid,mtag[p],atag[p]);
    pushtag(rc(p),mid + 1,r,mtag[p],atag[p]);
    mtag[p] = 1,atag[p] = 0;
}
//修改
void update(int p,int l,int r,int ul,int ur,ll k,ll b){
    if(ul <= l && r <= ur) {pushtag(p,l,r,k,b);return;}
    push_down(p,l,r);
    int mid = (l + r) >> 1;
    if(ul <= mid) update(lc(p),l,mid,ul,ur,k,b);
    if(mid < ur) update(rc(p),mid + 1,r,ul,ur,k,b);
    push_up(p);
}
//查询
int query(int p,int l,int r,int ul,int ur){
    if(ul <= l && r <= ur) {return cnt[p];}
    int mid = (l + r) >> 1,ans = 0;
    push_down(p,l,r);
    if(ul <= mid) ans = (ans + query(lc(p),l,mid,ul,ur)) % mod;
    if(mid < ur) ans = (ans + query(rc(p),mid + 1,r,ul,ur)) % mod;
    push_up(p);
    return ans % mod;
}
#undef lc
#undef rc

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> q >> mod;
    for(int i = 1;i <= n;i++) std::cin >> a[i];
    build(1,1,n);
    while (q--){
        ll op,x,y,k;
        std::cin >> op >> x >> y;
        switch(op){
            case 1:
                std::cin >> k;
                update(1,1,n,x,y,k,0);
                break;
            case 2:
                std::cin >> k;
                update(1,1,n,x,y,1,k);
                break;
            case 3:
                std::cout << query(1,1,n,x,y) << '\n';
                break;
        }
    }
    return 0;
}