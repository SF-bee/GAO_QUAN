#include <bits/stdc++.h>

const int MAX = 5e3;
int n,m,sum;
std::array<int,MAX> l,stdans[MAX];
std::set<int> yans[MAX];

inline int rd(){int x; std::cin >> x; return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> m;
    for(int i = 1;i <= n;i++) std::generate_n(stdans[i].begin(),m,rd);
    for(int i = 1;i <= n;i++){
        std::cin >> l[i];
        for(int j = 0;j < l[i];j++){
            int x;
            std::cin >> x;
            yans[i].insert(x);
        }
    }
    
    for(int i = 1;i <= n;i++){
        int cnt = 0;
        for(int j = 0;j < m;j++){
            cnt += yans[i].count(stdans[i][j]);
        }
        if(cnt == m) sum += 2;
    }
    std::cout << sum;
    return 0;
}