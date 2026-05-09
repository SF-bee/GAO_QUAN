#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,m;
struct SegmentTree {
    int sum[MAX << 2]; //统计开着的灯的数量
    bool tag[MAX << 2]; //该区间是否被取反
    #define ls(n) (n << 1)
    #define rs(n) ((n << 1) | 1)
    bool Isin(int l,int r,int L,int R) {return L <= l && r <= R;}
    bool Isout(int l,int r,int L,int R) {return r < L || l > R;}
    void PushUp(int p) {sum[p] = sum[ls(p)] + sum[rs(p)];}
    void MakeTag(int p,int l,int r) {
        tag[p] ^= 1;
        sum[p] = (r - l + 1) - sum[p];
    }
    void PushDown(int p,int l,int r) {
        if(tag[p]){
            int mid = (l + r) >> 1;
            MakeTag(ls(p),l,mid);
            MakeTag(rs(p),mid + 1,r);
            tag[p] = 0;
        }
        
    }
    void Update(int p,int l,int r,int L,int R) {
        if(Isin(l,r,L,R)) {
            MakeTag(p,l,r);
            return;
        }
        else if(Isout(l,r,L,R)) return;
        PushDown(p,l,r);
        int mid = (l + r) >> 1;
        Update(ls(p),l,mid,L,R);
        Update(rs(p),mid + 1,r,L,R);
        PushUp(p);
    }
    int Query(int p,int l,int r,int L,int R) {
        if(Isin(l,r,L,R)) return sum[p];
        else if(Isout(l,r,L,R)) return 0;
        PushDown(p,l,r);
        int mid = (l + r) >> 1;
        int sum = Query(ls(p),l,mid,L,R) +
                Query(rs(p),mid + 1,r,L,R);
        PushDown(p,l,r);
        return sum;
    }
}root;

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);
    
    std::cin >> n >> m;
    while(m--) {
        int c,a,b;
        std::cin >> c >> a >> b;
        if(c == 0) {
            root.Update(1,1,n,a,b);
        }
        else if(c == 1) {
            std::cout << root.Query(1,1,n,a,b) << '\n';
        }
    }
    return 0;
}