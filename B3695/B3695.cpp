#include <bits/stdc++.h>
const int MAX = 3e4 + 5;

int n,m,q;
std::bitset<MAX> s[MAX];
std::bitset<MAX> cl;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m >> q;
    for(int i = 1;i <= m;i++) cl.set(i);
    int c,u;
    for(int i = 1;i <= n;i++){
        std::cin >> c;
        for(int j = 1;j <= c;j++) std::cin >> u,s[i].set(u);
    }

    int o,x,y;
    while(q--){
        std::cin >> o >> x >> y;
        switch (o){
            case 1:
                s[x] <<= y;
                s[x] &= cl;
                break;
            case 2:
                s[x] >>= y;
                s[x] &= cl;
                break;
            case 3:
                // for(int i = 1;i <= m;i++) std::cout << (s[x]&s[y]).test(i) << " \n"[i == m];
                std::cout << (s[x]&s[y]).count() << '\n';
                break;
            case 4:
                // for(int i = 1;i <= m;i++) std::cout << (s[x]|s[y]).test(i) << " \n"[i == m];
                std::cout << (s[x]|s[y]).count() << '\n';
                break;
            case 5:
                // for(int i = 1;i <= m;i++) std::cout << (s[x]^s[y]).test(i) << " \n"[i == m];
                std::cout << (s[x]^s[y]).count() << '\n';
                break;
        }
    }
    return 0;
}