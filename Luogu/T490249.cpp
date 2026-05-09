#include <bits/stdc++.h>
const int MAX = 5e5 + 5;

int n,m;
int a[MAX],b[MAX],t[2 * MAX];

int rd(){int x; std::cin >> x; return x;}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    std::generate_n(a,n,rd);
    std::generate_n(b,m,rd);

    long long ans = 0;
    for(int i = 0,j = 0,k = 0;i < n + m;i++){
        if(j == n)
            t[i] = b[k++];
        else if(k == m)
            t[i] = a[j++];
        else if(a[j] <= b[k])
            t[i] = a[j++];
        else
            ans += n - j,t[i] = b[k++];
        std::cout << t[i] << " \n"[i == n + m - 1];
    }
    std::cout << ans << '\n';
    return 0;
}