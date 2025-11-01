#include <bits/stdc++.h>
const int MAX = 1e6 + 6;

int T,n,sum,a;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while (T--){
        sum = 0;
        std::cin >> n;
        for(int i = 1;i <= n;i++)
            std::cin >> a,sum ^= a;
        std::cout << (sum > 0 ? "Yes\n" : "No\n");
    }
    return 0;
}