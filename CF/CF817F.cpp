#include <bits/stdc++.h>
const int MAX = 3e5 + 5;
using ll = long long;

struct SegmentTree{
    SegmentTree *ls,*rs;
    ll l,r,val;
    //0表示没有标记，1表示有未下传的入，2表示有未下传的消，3表示有未下传的取反
    int tag; 

    SegmentTree(ll L,ll R) : l(L),r(R),val(0),tag(0){
        ls = rs = nullptr;
    }

    bool in(ll L,ll R) {return L <= l && r <= R;}
    bool out(ll L,ll R) {return R < l || r < L;}
    void pushup() {val = ls->val + rs->val;}
    void maketag(int k) {
        if (k == 1) val = r - l + 1,tag = 1;
        else if (k == 2) val = 0,tag = 2;
        else if (k == 3) { // 取反
            val = (r - l + 1) - val;
            if (tag == 0) tag = 3;
            else if (tag == 1) tag = 2;
            else if (tag == 2) tag = 1;
            else if (tag == 3) tag = 0;
        }
    }
    void pushdown(){
        if(!ls){
            ll mid = (l + r) / 2;
            ls = new SegmentTree(l,mid);
            rs = new SegmentTree(mid + 1,r);
        }
        if(tag){
            ls->maketag(tag);
            rs->maketag(tag);
            tag = 0;
        }
    }
    void update(ll L,ll R,int k){
        if(out(L,R)) return;
        if(in(L,R)) maketag(k);
        else if(!out(L,R)){
            pushdown();
            ls->update(L,R,k);
            rs->update(L,R,k);
            pushup();
        }
    }
    int query(){
        if(val == 0) return l;
        pushdown();
        if(ls->val < (ls->r - ls->l + 1)) return ls->query();
        else return rs->query();
    }
};

int n,tot,op[MAX];
ll p[MAX],l[MAX],r[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    p[++tot] = 1;
    for(int i = 1;i <= n;i++){
        std::cin >> op[i] >> l[i] >> r[i];
        p[++tot] = l[i],p[++tot] = r[i];
        p[++tot] = r[i] + 1;
    }
    std::sort(p + 1,p + tot + 1);
    tot = std::unique(p + 1,p + tot + 1) - p - 1;
    auto root = new SegmentTree(1,tot);
    for(int i = 1;i <= n;i++){
        l[i] = std::lower_bound(p + 1,p + tot + 1,l[i]) - p;
        r[i] = std::lower_bound(p + 1,p + tot + 1,r[i]) - p;
        root->update(l[i],r[i],op[i]);
        std::cout << p[root->query()] << '\n';
    }
    return 0;
}