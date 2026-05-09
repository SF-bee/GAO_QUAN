#include <bits/stdc++.h>
const int MAX = 1e5 + 5;

int n,a[MAX],f[40];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    for(int i = 1;i <= n;i++){
        int maxa = 1;
        for(int j = 0;j < 31;j++)
            if((1 << j) & a[i]) maxa = std::max(maxa,f[j] + 1);
        for(int j = 0;j < 31;j++)
            if((1 << j) & a[i]) f[j] = std::max(maxa,f[j]);
    }
    std::cout << *std::max_element(f,f + 31) << '\n';
    return 0;
}