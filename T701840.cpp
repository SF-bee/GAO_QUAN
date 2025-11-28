#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e5 + 5;

int n,m,a[MAX];
struct Segmentree{
    Segmentree *ls,*rs;
    int l,r;
    ll sum,tag;
    void PushUp() {sum = ls->sum + rs->sum;}
    void MakeTag(ll k) {
        tag += k;
        sum += k * (r - l + 1);
    }
    void PushDown() {
        ls -> MakeTag(tag);
        rs -> MakeTag(tag);
        tag = 0;
    }
    Segmentree(int L, int R) : l(L), r(R), sum(0), tag(0), ls(nullptr), rs(nullptr) {
        if (L == R) {
            sum = a[L];
            return;
        }
        int mid = (L + R) >> 1;
        ls = new Segmentree(L, mid);
        rs = new Segmentree(mid + 1, R);
        PushUp();
    }
    bool IsIn(int L,int R) {return L <= l && r <= R;}
    bool IsOut(int L,int R) {return R < l || L > r;}
    void Update(int L,int R,ll k){
        if(IsIn(L,R)) MakeTag(k);
        else if(!IsOut(L,R)) {
            PushDown();
            ls -> Update(L,R,k);
            rs -> Update(L,R,k);
            PushUp();
        }
    }
    ll Query(int L,int R){
        if(IsIn(L,R)) return sum;
        else if(IsOut(L,R)) return 0;
        PushDown();
        return ls -> Query(L,R) + rs -> Query(L,R);
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    Segmentree *root = new Segmentree(1,n);
    while(m--) {
        int op,l,r;
        ll k;
        switch (op) {
        case 1:
            std::cin >> l >> r >> k;
            root -> Update(l,r,k);
            break;
        case 2:
            std::cin >> l >> r;
            std::cout << root -> Query(l,r) << '\n';
            break;
        }
    }
    return 0;
}