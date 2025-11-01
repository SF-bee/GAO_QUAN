#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e5 + 5;

int n;
ll m,ans = 1,sum;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int a,i = 1;i <= n;i++){
        std::cin >> a;
        if(sum + a > m) ans++,sum = a;
        else sum += a;
    }
    std::cout << ans << '\n';
    return 0;
}