#include <bits/stdc++.h>

struct node{
    int p,val;
};
inline bool comp(const node x,const node y){return x.val < y.val;}
const int MAX = 1e5;
const int MOD = 1e8 - 3;
int n,ans;
int c[MAX],d[MAX];
node a[MAX],b[MAX];

void merge(int l,int r){
    if(l == r) return;
    int mid = (l + r) >> 1;
    merge(l,mid);merge(mid + 1,r);
    for(int i = l,j = l,k = mid + 1;i <= r;i++){
        if(j == mid + 1)
            d[i] = c[k++];
        else if(k == r + 1){
            d[i] = c[j++];
            ans = (ans % MOD + (k - mid - 1) % MOD) % MOD;
        }
        else if(c[j] <= c[k]){
            d[i] = c[j++];
            ans = (ans % MOD + (k - mid - 1) % MOD) % MOD;
        }
        else
            d[i] = c[k++];
    }
    for(int i = l;i <= r;i++)
        c[i] = d[i];
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 0;i < n;i++){
        std::cin >> a[i].val;
        a[i].p = i;
    }
    for(int i = 0;i < n;i++){
        std::cin >> b[i].val;
        b[i].p = i;
    }
    std::sort(a,a + n,comp);
    std::sort(b,b + n,comp);
    // for(int i = 0;i < n;i++)
    //     std::cout << a[i].p << ' ' << b[i].p << '\n';
    for(int i = 0;i < n;i++)
        c[b[i].p] = a[i].p;
    merge(0,n - 1);
    std::cout << ans % MOD << '\n';
    return 0;
}