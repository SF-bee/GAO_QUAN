#include <bits/stdc++.h>
using ll = long long;
const int MAX = 2e5 + 5;
const int mod = 998244353;

struct mat{
    ll m[2][2];
    mat operator * (const mat& rhs) const{
        mat res;
        res.m[0][0] = res.m[0][1] = res.m[1][0] = res.m[1][1] = 0;
        for(int k = 0;k < 2;k++)
            for(int i = 0;i < 2;i++)
                for(int j = 0;j < 2;j++)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * rhs.m[k][j]) % mod;
        return res;
    }
};

int n,q;
std::string a;
mat E,X,Y;
struct SegmentTree{
    mat cnt[MAX * 4][2];
    int tag[MAX * 4];
    #define lc(x) (x * 2)
    #define rc(x) (x * 2 + 1)
    void pushup(int p){
        cnt[p][0] = cnt[rc(p)][0] * cnt[lc(p)][0];
        cnt[p][1] = cnt[rc(p)][1] * cnt[lc(p)][1];
    }
    void build(int p,int l,int r){
        if(l == r) {
            if(a[l] == 'X') cnt[p][0] = X, cnt[p][1] = Y;
            else cnt[p][0] = Y, cnt[p][1] = X;
            return;
        }
        int mid = (l + r) / 2;
        build(lc(p),l,mid);
        build(rc(p),mid+1,r);
        pushup(p);
    }
    void pushtag(int p, int k){
        if(k) {
            std::swap(cnt[p][0], cnt[p][1]);
            tag[p] ^= 1;
        }
    }
    void pushdwon(int p,int l,int r){
        int mid = (l + r) / 2;
        pushtag(lc(p), tag[p]);
        pushtag(rc(p), tag[p]);
        tag[p] = 0;
    }
    void update(int p,int l,int r,int ql,int qr,int k){
        if(ql <= l && r <= qr){
            pushtag(p, k);
            return;
        }
        pushdwon(p,l,r);
        int mid = (l + r) / 2;
        if(ql <= mid) update(lc(p),l,mid,ql,qr,k);
        if(mid < qr) update(rc(p),mid+1,r,ql,qr,k);
        pushup(p);
    }
    mat query(int p,int l,int r,int ql,int qr){
        mat res = E;
        if(ql <= l && r <= qr) return cnt[p][0];
        pushdwon(p,l,r);
        int mid = (l + r) / 2;
        if(ql <= mid) res = query(lc(p),l,mid,ql,qr) * res;
        if(mid < qr) res = query(rc(p),mid+1,r,ql,qr) * res;
        return res;
    }
    #undef lc
    #undef rc
}seg;

void init(){
    X = {{{0,1},{1,0}}};
    Y = {{{114514,7},{1,0}}};
    E = {{{1,0},{0,1}}};
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    init();
    std::cin >> n >> a;
    a = '#' + a;
    seg.build(1,1,n);
    std::cin >> q;
    while(q--){
        int op,l,r,a,b;
        std::cin >> op >> l >> r;
        switch (op){
            case 1:
                seg.update(1,1,n,l,r,1);
                break;
            case 2:
                std::cin >> a >> b;
                mat t = seg.query(1,1,n,l,r);
                ll na = (a * t.m[0][0] + b * t.m[0][1]) % mod;
                ll nb = (a * t.m[1][0] + b * t.m[1][1]) % mod;
                std::cout << na << ' ' << nb << '\n';
                break;
        }
    }
    return 0;
}