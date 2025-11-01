#include <bits/stdc++.h>
const int MAX = 5e2 + 5;

int n,k,h[MAX];
int top,nd[MAX][2],stk[MAX];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> k;
    for(int i = 1;i <= n;i++) std::cin >> h[i];

    for (int i = 1; i <= n; i++) {
        while(top && h[stk[top]] > h[i]) nd[i][0] = stk[top--];
        if(top) nd[stk[top]][1] = i;
        stk[++top] = i;
    }
    for(int i = 1;i <= n;i++)
        std::cout << nd[i][0] << ' ' << nd[i][1] << '\n';
    return 0;
}