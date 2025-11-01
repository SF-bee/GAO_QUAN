#include <bits/stdc++.h>

const int MAX = 1e5 + 5;
int T,n,maxa;
std::array<int,MAX> a;

inline int rd(){int x; std::cin >> x; maxa = std::max(maxa,x); return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> T;
    while(T--){
        std::cin >> n;
        maxa = 0;
        std::generate_n(a.begin(),n,rd);

        bool flag = 1;
        for(int i = 0;i < n;i++)
            if(maxa % a[i] != 0) flag = 0;
        std::cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}