#include <bits/stdc++.h>
typedef unsigned long long ull;
const ull base = 13331;
const int MAX = 1e6 + 5;

std::string s;
ull hs[MAX],p[MAX];
int m;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s;
    s = '.' + s;
    p[0] = 1;
    for(int i = 1;i < s.size();i++){
        hs[i] = hs[i - 1] * base + s[i];
        p[i] = p[i - 1] * base;
    }
    std::cin >> m;
    int l1,r1,l2,r2;
    while(m--){
        std::cin >> l1 >> r1 >> l2 >> r2;
        if(hs[r1] - hs[l1 - 1] * p[r1 - l1 + 1] == hs[r2] - hs[l2 - 1] * p[r2 - l2 + 1])
            std::cout << "Yes\n";
        else std::cout << "No\n";
    }
    return 0;
}