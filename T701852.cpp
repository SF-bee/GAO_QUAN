#include <bits/stdc++.h>
#define int long long
const int MAX = 1e7 + 5;

int n,top;
int ls[MAX],rs[MAX];
int a[MAX],stk[MAX];

signed main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++){
        std::cin >> a[i];
        while(top && a[stk[top]] > a[i]) ls[i] = stk[top--];
        if(top) rs[stk[top]] = i;
        stk[++top] = i;
    }
    int a1 = 0,a2 = 0;
    for(int i = 1;i <= n;i++)
        a1 ^= (i * (ls[i] + 1)), a2 ^= (i * (rs[i] + 1));
    std::cout << a1 << ' ' << a2 << '\n';    
    return 0;
}