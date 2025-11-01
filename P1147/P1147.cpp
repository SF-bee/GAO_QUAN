#include <bits/stdc++.h>

int m;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> m;
    for(int l = 0,r = 0,cnt = 0;l < m;){
        if(cnt == m) std::cout << l << ' ' << r << '\n';
        if(cnt > m) cnt -= l,l++;
        else r++,cnt += r;
    }
    return 0;
}