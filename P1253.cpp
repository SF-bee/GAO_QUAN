#include <bits/stdc++.h>
using ll = long long;
const int MAX = 1e6 + 5;
const ll NO_TAG = -1e18;

int n,q;
int a[MAX];

struct SegmentTree {
    ll Maxa[MAX << 2]; //存储区间最大值
    ll Uptag[MAX << 2]; //存储赋值标记（0=无标记，非0=区间赋值为该值）
    ll Addtag[MAX << 2]; //存储加法标记（0=无标记）

    #define ls(p) (p << 1)
    #define rs(p) ((p << 1) | 1)
    bool IsIn(int l,int r,int L,int R) {return L <= l && r <= R;}
    bool IsOut(int l,int r,int L,int R) {return r < L || l > R;}
    void PushUp(int p) {Maxa[p] = std::max(Maxa[ls(p)],Maxa[rs(p)]);}
    
    void Build(int p,int l,int r) {
        Uptag[p] = NO_TAG;
        Addtag[p] = 0;
        if(l == r) {
            Maxa[p] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(ls(p),l,mid);
        Build(rs(p),mid + 1,r);
        PushUp(p);
    }
    void TagUpdate(int p,ll x) {
        Maxa[p] = x;
        Uptag[p] = x;
        Addtag[p] = 0;
    }
    void TagAdd(int p,ll x) {
        Maxa[p] += x;
        if(Uptag[p] != NO_TAG)
            Uptag[p] += x;
        else
            Addtag[p] += x;
    }
    void Pushdown(int p) {
        if (Uptag[p] != NO_TAG) {
            TagUpdate(ls(p), Uptag[p]);
            TagUpdate(rs(p), Uptag[p]);
            Uptag[p] = NO_TAG;
        }
        if (Addtag[p]) {
            TagAdd(ls(p), Addtag[p]);
            TagAdd(rs(p), Addtag[p]);
            Addtag[p] = 0;
        }
    }
    
    void Update(int p,int l,int r,int L,int R,ll x,bool op) {
        if(IsIn(l,r,L,R)) {
            !op ? TagUpdate(p,x) : TagAdd(p,x);
            return;
        }
        else if(IsOut(l,r,L,R)) return;
        Pushdown(p);
        int mid = (l + r) >> 1;
        Update(ls(p),l,mid,L,R,x,op);
        Update(rs(p),mid + 1,r,L,R,x,op);
        PushUp(p);
    }
    
    ll Query(int p,int l,int r,int L,int R) {
        if(IsIn(l,r,L,R)) return Maxa[p];
        else if(IsOut(l,r,L,R)) return -1e18;
        Pushdown(p);
        int mid = (l + r) >> 1;
        ll lson = Query(ls(p),l,mid,L,R);
        ll rson = Query(rs(p),mid + 1,r,L,R);
        return std::max(lson,rson);
    }
}root;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> q;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    root.Build(1,1,n);
    while(q--){
        int op,l,r,x;
        std::cin >> op >> l >> r;
        switch (op) {
            case 1:
                std::cin >> x;
                root.Update(1,1,n,l,r,x,0);
                break;
            case 2:
                std::cin >> x;
                root.Update(1,1,n,l,r,x,1);
                break;
            case 3:
                std::cout << root.Query(1,1,n,l,r) << '\n';
                break;
        }
    }
    return 0;
}