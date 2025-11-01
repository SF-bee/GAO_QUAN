#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e5 + 5;

int n,tot;
ll ans,book[MAX << 1];
struct rect{
    ll xl,xr,y,k;
    bool operator < (const rect & rhs) const{
        return y < rhs.y;
    }
}seg[MAX << 1];
struct SegTree{
    ll cnt[MAX << 4],tag[MAX << 4],len[MAX << 4];
    #define lc(u) (u << 1)
    #define rc(u) (u << 1 | 1)
    void push_up(int p){
        if(tag[p]) cnt[p] = len[p];
        else cnt[p] = cnt[lc(p)] + cnt[rc(p)];
    }
    void build(int p,int l,int r){
        len[p] = book[r] - book[l - 1];
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(lc(p),l,mid);
        build(rc(p),mid + 1,r);
    }
    void update(int p,int l,int r,int ql,int qr,ll k){
        if(ql <= l && r <= qr){
            tag[p] += k;
            push_up(p);
            return;
        }
        int mid = (l + r) >> 1;
        if(ql <= mid) update(lc(p),l,mid,ql,qr,k);
        if(mid < qr) update(rc(p),mid + 1,r,ql,qr,k);
        push_up(p);
    }
    #undef lc
    #undef rc
}tre;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        int xl,xr,yl,yr;
        std::cin >> xl >> yl >> xr >> yr;
        seg[i] = {xl,xr,yl,1};
        seg[n + i] = {xl,xr,yr,-1};
        book[++tot] = xl;
        book[++tot] = xr;
    }
    std::sort(book + 1,book + tot + 1);
    tot = std::unique(book + 1,book + tot + 1) - book - 1;
    for(int i = 1;i <= 2 * n;i++){
        seg[i].xl = 
          std::lower_bound(book + 1,book + tot + 1,seg[i].xl) - book;
        seg[i].xr = 
          std::lower_bound(book + 1,book + tot + 1,seg[i].xr) - book;
    }
    std::sort(seg + 1,seg + 2 * n + 1);
    tre.build(1,1,tot);
    for(int i = 1;i <= 2 * n;i++){
        ans += tre.cnt[1] * (seg[i].y - seg[i - 1].y);
        tre.update(1,1,tot,seg[i].xl + 1,seg[i].xr,seg[i].k);
        
    }
    std::cout << ans << '\n';
    return 0;
}