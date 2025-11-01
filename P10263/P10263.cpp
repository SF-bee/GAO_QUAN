#include <bits/stdc++.h>

const int MAX = 1e5 + 5;
long long n,m,k,ans = 0;;
long long cnt_n[MAX],cnt_m[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
        for(int j = i;j <= k;j += i)
            cnt_n[j]+=1;
    for(int i = 1;i <= m;i++)
        for(int j = i;j <= k;j += i)
            cnt_m[j]+=1;
    for(int i = 1;i <= k;i++)
        ans += 1ll * i * cnt_n[i] * cnt_m[i];
    std::cout << ans;
    return 0;
}

/*
1
1 A1 1
2 A1 2 A2 1 A2 2
3 A1 3 A3 1 A3 3
4 A1 4 A2 2 A4 1 A4 4
5 A1 5 A5 1 A5 5
*/