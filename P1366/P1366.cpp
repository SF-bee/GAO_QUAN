#include <bits/stdc++.h>
const int MAX = 1e7 + 5;

int T,n,m;
unsigned long long a[MAX],b[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> T;
    unsigned long long ans = 0,cnt = 0;
    while(T--){
        ans = 0,cnt = 0;
        std::cin >> n >> m;
        for(int i = 1;i <= n;i++) std::cin >> a[i];
        for(int i = 1;i <= m;i++) std::cin >> b[i];
        
        for(int i = 1,j = 1;i <= n;i++){
            cnt = 0;
            for(;j <= m && a[i] >= b[j];j++){
                if(a[i] == b[j]) cnt++;
            }
            ans ^= cnt;
        }
        std::cout << ans << '\n';
    }
    return 0;
}