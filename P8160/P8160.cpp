#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 2e5 + 5;

int n,q;
ll a[MAX],sum[MAX];

inline ll lowbit(ll x){return x & -x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        std::cin >> a[i];
        sum[i] = sum[i - 1] + lowbit(a[i]);
    }
    int j = 1;
    std::cin >> q;
    while(q--){
        ll x;
        std::cin >> x;
        for(;j <= n;j++)
            if(x <= sum[j]){
                std::cout << a[j] / lowbit(a[j]) << '\n';
                break;
            }
    }
    return 0;
}