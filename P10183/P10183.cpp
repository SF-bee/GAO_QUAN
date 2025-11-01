#include <bits/stdc++.h>

const int MAX = 2000006;
int n;
long long a[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    memset(a,0x3f,sizeof(a));
    long long min_gcd = LONG_LONG_MAX;
    for(int i = 0;i < n;i++){
        std::cin >> a[i];
        if(a[i] % 2 != 0){
            std::cout << -1;
            return 0;
        }
    }
    std::cout << min_gcd / 2;
    return 0;
}