#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e5 + 5;

int n,m;
ll a[MAX],cnt[MAX << 2],maxa[MAX << 2];

#define lc(p) (p << 1)
#define rc(p) ((p << 1) + 1)
void push_up(int p) {cnt[p] = cnt[lc(p)] + cnt[rc(p)],maxa[p] = std::max(maxa[lc(p)],maxa[rc(p)]);}
void build(int p,int l,int r){
    if(l == r) {maxa[p] = cnt[p] = a[l];return;}
    int mid = (l + r) >> 1;
    build(lc(p),l,mid);
    build(rc(p),mid + 1,r);
    push_up(p);
}
void update(int p,int l,int r,int ul,int ur){
    if(l == r && ul <= l && r <= ur) {maxa[p] = cnt[p] = std::sqrt(cnt[p]);return;}
    int mid = (l + r) >> 1;
    if(ul <= mid && maxa[lc(p)] > 1) update(lc(p),l,mid,ul,ur);
    if(mid < ur && maxa[rc(p)] > 1) update(rc(p),mid + 1,r,ul,ur);
    push_up(p);
}
ll query(int p,int l,int r,int ul,int ur){
    if(ul <= l && r <= ur) return cnt[p];
    ll res = 0;
    int mid = (l + r) >> 1;
    if(ul <= mid) res += query(lc(p),l,mid,ul,ur);
    if(mid < ur) res += query(rc(p),mid + 1,r,ul,ur);
    return res;
}
#undef lc
#undef rc

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> a[i];
    build(1,1,n);
    std::cin >> m;
    while(m--){
        int op,x,y;
        std::cin >> op >> x >> y;
        if(y < x) std::swap(x,y);
        switch (op){
        case 0:
            update(1,1,n,x,y);
            break;
        case 1:
            std::cout << query(1,1,n,x,y) << '\n';
            break;
        }
    }
    return 0;
}