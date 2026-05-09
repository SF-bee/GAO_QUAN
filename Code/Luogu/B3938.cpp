#include <bits/stdc++.h>

const int MAX = 1e6 + 5;
int T;
int n,t,m;
std::array<int,MAX> a,x;

inline int rd(){int x; std::cin >> x; return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> T;
    while(T--){
        std::cin >> n >> t >> m;
        std::generate_n(a.begin() + 1,n,rd);
        std::generate_n(x.begin() + 1,m,rd);
        for(int i = 1;i <= m;i++)
            a[x[i]] -= 2;
        std::sort(a.begin() + 1,a.begin() + n,std::greater<int>());
        int sum = 0,ans = 0;
        for(int i = 1;i <= n;i++){
            if(a[i] > 0) ans++;
            else if(a[i] <= 0 && sum + 1 - a[i] <= t){
                sum += 1 - a[i],ans++;
            }
        } 
        std::cout << ans << '\n';
    }
    return 0;
}