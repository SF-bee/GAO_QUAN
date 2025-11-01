#include <bits/stdc++.h>
typedef long long lint;

const int MAX = 1e3 + 5;
int n,ans;
std::array<int,MAX> arr,brr;

inline int rd(){int x; std::cin >> x; return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    std::generate_n(arr.begin() + 1,n,rd);

    for(int i = 1;i <= n;i++)
        brr[i] = brr[i - 1] ^ arr[i];
    for(int l = 1;l <= n;l++){
        for(int r = l;r <= n;r++){
            ans = std::max(ans,brr[r] ^ brr[l - 1]);
        }
    }
    std::cout << ans;
    return 0;
}