#include <bits/stdc++.h>

const int MAX = 1005;
int n,k,ans,sum;
std::array<int,MAX> a;

inline int rd() {int x; std::cin >> x; return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    std::generate_n(a.begin(),n,rd);

    std::sort(a.begin(),a.begin() + n);
    for(int l = 0,r = 0;r < n;){
        if(a[r] - a[l] <= k){
            sum += a[r];
            ans = std::max(ans,sum);
            r++;
        }
        else{
            sum -= a[l];
            ans = std::max(ans,sum);
            l++;
        }
    }
    std::cout << ans;
    return 0;
}
/*
1 3 3 4 4 6 7

*/