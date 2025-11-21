#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e5 + 5;

int n,m;
ll a[MAX],cnt[MAX << 2],tag[MAX << 2];
#define lc(x) (x << 1)
#define rc(x) ((x << 1) + 1)
void push_up(int p){cnt[p] = cnt[lc(p)] + cnt[rc(p)];}
void build(int p,int l,int r){
    if(l == r){cnt[p] = a[l];return;}
    int mid = (l + r) >> 1;
    build(lc(p),l,mid);
    build(rc(p),mid + 1,r);
    push_up(p);
}
void pushtag(int p,int l,int r,ll k){
    tag[p] += k;
    cnt[p] += k * (r - l + 1);
}
void push_down(int p,int l,int r){
    int mid = (l + r) >> 1;
    pushtag(lc(p),l,mid,tag[p]);
    pushtag(rc(p),mid + 1,r,tag[p]);
    tag[p] = 0;
}
void update(int p,int l,int r,int ul,int ur,ll k){
    if(ul <= l && r <= ur) {pushtag(p,l,r,k);return;}
    push_down(p,l,r);
    int mid = (l + r) >> 1;
    if(ul <= mid) update(lc(p),l,mid,ul,ur,k);
    if(mid < ur) update(rc(p),mid + 1,r,ul,ur,k);
    push_up(p);
}
ll query(int p,int l,int r,int x){
    if(1 <= l && r <= x){return cnt[p];}
    ll res = 0;
    int mid = (l + r) >> 1;
    push_down(p,l,r);
    if(1 <= mid) res += query(lc(p),l,mid,x);
    if(mid < x) res += query(rc(p),mid + 1,r,x);
    return res;
}
#undef lc
#undef rc

int main(){
    #if !ONLINE_JUDGE
    freopen("P1438.in","r",stdin);
    freopen("P1438.out","w",stdout);
    #endif
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int i = n;i >= 1;i--)
        a[i] = a[i] - a[i - 1];
    build(1,1,n);
    for(int op,l,r,k,d,i = 1;i <= m;i++){
        std::cin >> op >> l;
        switch(op){
            case 1:
            std::cin >> r >> k >> d;
            update(1,1,n,l,l,k);
            if(l + 1 <= r) update(1,1,n,l + 1,r,d);
            if(r + 1 <= n)update(1,1,n,r + 1,r + 1,-(k+(r-l)*d));
            break;
            case 2:
            std::cout << query(1,1,n,l) << '\n';
            break;
        }
    }
    return 0;
}