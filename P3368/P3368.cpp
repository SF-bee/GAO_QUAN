#include <bits/stdc++.h>
const int MAX = 5e5 + 5;

int n,m,a[MAX];
struct bit{
    int c[MAX];
    bit(){std::memset(c,0,sizeof(c));}
    int lowbit(int x) {return x & (-x);}
    void add(int x,int k){
        for(;x <= n;x += lowbit(x)) c[x] += k;
    }
    int get(int x){
        int res = 0;
        while(x > 0){
            res += c[x];
            x -= lowbit(x);
        }
        return res;
    }
}cnt;
 

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) std::cin >> a[i];
    while(m--){
        int op,x,y,k;
        std::cin >> op;
        switch (op){
            case 1:
                std::cin >> x >> y >> k;
                cnt.add(x,k);
                cnt.add(y + 1,-k);
                break;
            case 2:
                std::cin >> x;
                std::cout << a[x] + cnt.get(x) << '\n';
        }
    }
    return 0;
}