#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e4 + 5;

ll q,cb[MAX],x,sum;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> q;
    for(int j = 1;j < MAX;j++)
        cb[j] = 1ll * j * j * j;
    ll i = 1;
    while (q--){
        std::cin >> x;
        for(;i < MAX;i++){
            if(cb[i] > x) break;
            sum += (cb[i] - cb[i - 1]) * (i - 1);
        }
        std::cout << sum + (i - 1) * (x - cb[i - 1] + 1) << '\n';
    }
    return 0;
}