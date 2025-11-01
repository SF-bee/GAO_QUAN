#include <bits/stdc++.h>
using ll = long long;
const int MAX = 3e7 + 5;

ll tot,prm[MAX],mp[MAX];
std::bitset<MAX> ip;

void init(){
    for(int i = 2;i < MAX;i++){
        if(!ip[i]) prm[++tot] = i,mp[i] = i;
        for(int j = 1;j <= tot;j++){
            if(prm[j] * i >= MAX) break;
            ip[prm[j] * i] = 1;
            mp[prm[j] * i] = prm[j];
            if(i % prm[j] == 0) break;
        }
    }
}

int main(){
    init();
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int T,x,k;
    std::cin >> T;
    while(T--){
        std::cin >> x >> k;
        int sum = 0;
        while(x > 1){
            int cur = mp[x],cnt = 0;
            while (x % cur == 0)
                cnt++, x /= cur;
            sum += cnt / k;
        }
        if(sum > 0)
            std::cout << "E_huan win\n";
        else
            std::cout << "E_huan lose\n";
    }
    return 0;
}