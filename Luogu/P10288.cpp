#include <bits/stdc++.h>

const int MAX = 1e5 + 7;
int T,n,q,a[MAX],b[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while(T--){
        std::cin >> n;
        std::vector<int> arr[n + 7];
        for(int i = 1;i <= n;i++){
            std::cin >> a[i];
            b[i] = a[i];
        }
        std::sort(b + 1,b + n + 1);
        int end = std::unique(b + 1,b + n + 1) - b - 1;
        for(int i = 1;i <= n;i++){
            a[i] = std::lower_bound(b + 1,b + end + 1,a[i]) - b;
            arr[a[i]].push_back(i);
        }
        std::cin >> q;
        while(q--){
            int l,r,x;
            std::cin >> l >> r >> x;
            int k = std::lower_bound(b + 1,b + end + 1,x) - b;
            if (b[k] != x){
                std::cout << 0 << '\n';
                continue;
            }
            auto i = std::lower_bound(arr[k].begin(),arr[k].end(),l);
            auto j = --std::upper_bound(arr[k].begin(),arr[k].end(),r);
            std::cout << j - i + 1 << '\n';
        }
    }
    return 0;
}