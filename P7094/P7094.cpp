#include <bits/stdc++.h>
typedef long long ll;

ll T,a,b,c,d;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    while (T--){
        std::cin >> a >> b >> c >> d;
        ll cnt = 0;
        for(int y = 1;y <= c * d / b;y++)
            if(c * d - b * y > 0 && (a * c * y) % (c * d - b * y) == 0)
                cnt++;
        std::cout << cnt << '\n';
    }
    return 0;
}