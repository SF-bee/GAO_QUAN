#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;

int T,Q,op[MAX];
ll M;

struct SegmentTree{
    SegmentTree *ls,*rs;
    int l,r;
    ll cnt;

    SegmentTree(int L,int R) : l(L),r(R),cnt(1){
        if(l == r)
            ls = rs = nullptr;
        int mid = (l + r) / 2;
        ls = new SegmentTree(l,mid);
        rs = new SegmentTree(mid + 1,r);
        cnt = ls->cnt * rs->cnt % M;
    }

    void push_up() {cnt = ls->cnt * rs->cnt % M;}
    bool in(int L,int R) {return L <= l && r <= R;}
    bool out(int L,int R) {return R < l || r < L;}
    void update(int pos,ll x){
        if(l == r) cnt = x;
        else if(!ls && ls->in(pos,pos)) ls->update(pos,x);
        else if(!rs) rs->update(pos,x);
        push_up();
    }
};

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        std::cin >> Q >> M;
        auto root = new SegmentTree(1,Q);
        for(int i = 1;i <= Q;i++){
            int op,m;
            std::cin >> op >> m;
            if(op == 1){
                root->update(i,m);
                std::cout << root->cnt << '\n';
            }
            else{
                root->update(m,1);
                std::cout << root->cnt << '\n';
            }
        }
    }
    return 0;
}