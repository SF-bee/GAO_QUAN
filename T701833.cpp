#include <bits/stdc++.h>
const int MAX = 3e6 + 5;

int n,top;
int a[MAX],stk[MAX];

int main(){
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> a[i];
    std::vector<int> ans(n + 1,0);
    for(int i = n;i >= 1;i--){
        while(top && a[stk[top]] <= a[i]) top--;
        ans[i] = stk[top];
        stk[++top] = i;
    }
    for(int i = 1;i <= n;i++)
        std::cout << ans[i] << " \n"[i == n];
    return 0;
}
/*
5
1 4 2 3 5

4 5 3 5 0
*/