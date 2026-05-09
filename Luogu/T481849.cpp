#include <bits/stdc++.h>

const int MAX = 1e6 + 5;
int q;
std::array<int,MAX> next;

inline void insert(int x,int y){
    next[y] = next[x];
    next[x] = y;
    return;
}

inline int query(int x){
    return next[x];
}

inline void dele(int x){
    next[x] = next[next[x]];
    return;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> q;
    while(q--){
        int op,x,y;
        std::cin >> op >> x;
        switch (op){
            case 1:
                std::cin >> y;
                insert(x,y);
                break;
            case 2:
                std::cout << query(x) << '\n';
                break;
            case 3:
                dele(x);
                break;
        }
    }
    return 0;
}