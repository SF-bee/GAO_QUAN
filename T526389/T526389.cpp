#include <bits/stdc++.h>
typedef long long ll;

std::bitset<100005> vis;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    ll res = 1,a,b;
    std::cin >> a >> b;
    while(1){
        res = res * a % b;
        if(vis[res]) break;
        vis[res] = 1;
    }
    for(int i = 0;i < b;i++) if(vis[i]){
        std::cout << i << '\n';
        return 0;
    }
    return 0;
}