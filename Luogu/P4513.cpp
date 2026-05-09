#include <bits/stdc++.h>
const int MAX = 5e5 + 5;

int n,m;
int a[MAX];

struct SegmentTree {
    SegmentTree *ls,*rs;
    int l,r,sum,max,maxl,maxr;

    void PushUp() {
        if(ls->maxr < 0 && rs->maxl < 0)
            max = std::max(ls->maxr,rs->maxl);
        else {
            max = 0;
            if(ls->maxr > 0) max += ls->maxr;
            if(rs->maxl > 0) max += rs->maxl;
        }
        max = std::max(ls->max,rs->max);
        maxl = std::max(ls->maxl,ls->sum + rs->maxl);
        maxr = std::max(rs->maxr,rs->sum + ls->maxr);
        sum = ls->sum + rs->sum;
    }
    SegmentTree(int L,int R) : l(L),r(R) {
        if(L == R){
            ls = rs = nullptr;
            sum = max = maxl = maxr = a[l];
            return;
        }
        int mid = (L + R) >> 1;
        ls = new SegmentTree(L,mid);
        rs = new SegmentTree(mid + 1,R);
        PushUp();
    }
    bool isIn(int L,int R) {return L <= l && r <= R;}
    bool isOut(int pos) {return pos < l || r < pos;}
    bool isOut(int L,int R) {return l > R || r < L;}
    void Update(int pos,int val){
        if(l == r && l == pos){
            sum = max = maxl = maxr = val;
            return;
        }
        else if(!isOut(pos)){
            ls->Update(pos,val);
            rs->Update(pos,val);
            PushUp();
        }
    }
    int Query(int L,int R){
        if(isIn(L,R)) return max;
        int res = std::max(ls->Query(L,R),rs->Query(L,R));
        int rmax = 0;
        if(ls->maxr > 0) rmax += ls->maxr;
        if(rs->maxl > 0) rmax += rs->maxl;
        return std::max(res,rmax);
    }
};

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    SegmentTree *root = new SegmentTree(1,n);
    while(m--){
        int k,x,y;
        std::cin >> k >> x >> y;
        switch (k) {
        case 1:
            if(x > y) std::swap(x,y);
            std::cout << root->Query(x,y) << '\n';
            break;
        case 2:
            root->Update(x,y);
        }
    }
    return 0;
}