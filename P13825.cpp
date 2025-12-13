#include <bits/stdc++.h>
using ll = unsigned long long;

struct SegmentTree{
    SegmentTree *ls,*rs;
    int l,r;
    ll val,tag;

    SegmentTree(int L,int R) : l(L),r(R),val(0),tag(0) {
        ls = rs = nullptr;
    }

    bool in(int L,int R) {return L <= l && r <= R;}
    bool out(int L,int R) {return l > R || r < L;}
    void pushup() {val = ls->val + rs->val;}
    void maketag(ll k){
        val += (r - l + 1) * k;
        tag += k;
    }
    void pushdown(){
        if(!ls){
            int mid = (l + r) / 2;
            ls = new SegmentTree(l,mid);
            rs = new SegmentTree(mid + 1,r);
        }
        if(tag){
            ls->maketag(tag);
            rs->maketag(tag);
            tag = 0;
        }
    }
    void update(int L,int R,ll k){
        if(in(L,R)) maketag(k);
        else if(!out(L,R)){
            pushdown();
            ls->update(L,R,k);
            rs->update(L,R,k);
            pushup();
        }
    }
    ll query(int L,int R){
        if(in(L,R)) return val;
        else if(out(L,R)) return 0;
        pushdown();
        return ls->query(L,R) + rs->query(L,R);
    }
};

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n,m;
    std::cin >> n >> m;
    auto root = new SegmentTree(1,n);
    while(m--){
        int op,l,r,k;
        std::cin >> op >> l >> r;
        switch (op){
            case 1:
                std::cin >> k;
                root->update(l,r,k);
                break;
            case 2:
                std::cout << root->query(l,r) + 1ll * (r-l+1)*(l + r)/2 << '\n';
                break;
        }
    }
    return 0;
}